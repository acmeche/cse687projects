//////////////////////////////////////////////////////////////////////////////////////////////////
// File:        XmlReader.cpp																
// Purpose:     Parse XML strings with additional DLL library functionality
// Version:     1.0																			
// Language:    C++, Visual Studio 2019														
// Platform:    Windows 10																	
// Application: Single-User Test Harness, CSE687 - Object Oriented Design					
// Author:      Lamont Harrington															
//              Aaron Meche																	
//              Chris Johnson																
//              Jason Mitchell																
//////////////////////////////////////////////////////////////////////////////////////////////////
/*
   Maintenance History
   ===================
   DATE         VERSION    DESCRIPTION
   ----         -------    ----------------------------------------------------------------------
   10/28/2019    1.0       Initial Creation
   10/30/2019	   1.0       Added a new constructor that accepts a filestream object, created a new private
						               data member std::string path (the option to store a file path) along with a getPath
						               and setPath function, and added the public member function getTestRequestDllLocations(),
						               which allows for reading DLL locations from an XML file.
						   
*/
#include "pch.h"

#include "XmlReader.h"
#include <ctype.h>
#include <stack>
#include <algorithm>
#include <fstream>
#include <iostream>
#include <istream>
#include <string>
#include <sstream>

XmlReader::XmlReader(const std::string& xml) 
  : _xml(std::string(xml)), position(0), localposition(0) {}

XmlReader::XmlReader(std::stringstream xmlDoc)
	: position(0), localposition(0)
{
	xmlDoc << std::ifstream(xmlConfigPath).rdbuf();
	XmlReader xmlReader(xmlDoc.str());
}

//----< helper identifies markup chars >-----------------------------

bool specialChar(char ch)
{
  bool test = isspace(ch) || ch == '/' || ch == '>' || ch == '<' || ch == '=';
  test = test || ch == '\'' || ch == '"';
  return test;
}

std::string XmlReader::getPath()
{
	return path;
}

void XmlReader::setPath(std::string filePath)
{
	path = filePath;
}

std::vector<std::string> XmlReader::getTestRequestDllLocations()
{
	std::vector<std::string> returnVec;
	while (next())
	{
		std::string mainTag = tag().c_str();
		if (mainTag == TEST_REQUEST_TAG)
		{
			std::string dllLocation = body().c_str();
			returnVec.push_back(dllLocation);
		}
	}
	return returnVec;
}

//----< helper finds identifiers >-----------------------------------

std::string XmlReader::extractIdentifier(size_t& pos)
{
  std::string ident;
  while(true)
  {
    if(pos == _xml.size())
      return ident;
    char ch = _xml.at(pos);
    if(specialChar(ch))
      ++pos;
    else
      break;
  }
  while(true)
  {
    char ch = _xml.at(pos);
    if(specialChar(ch))
      break;
    ident += ch;
    ++pos;
  }
  return ident;
}
//----< return current element string >------------------------------

std::string XmlReader::element()
{
  // find tag
  localposition = position;
  _tag = extractIdentifier(localposition);

  // is declaration?
  std::string decTag = "?xml";
  if(_tag.compare("?xml") == 0)
  {
    size_t locpos = _xml.find("?>");
    return _xml.substr(position-1,locpos-position+3); 
  }

  // is comment?
  if(_tag.compare("!--") == 0)
  {
    size_t locpos = _xml.find("-->");
    return _xml.substr(position-1,locpos-position+4); 
  }

  // find end of element </tag>
  size_t locpos1 = localposition;
  std::stack<std::string> tagStack;
  tagStack.push(_tag);
  while(true)
  {
    locpos1 = _xml.find(_tag,locpos1);
    if(locpos1 >= _xml.size())
      break;
    if(_xml.at(locpos1-1)=='/')
      tagStack.pop();
    else if(_xml.at(locpos1-1)=='<')
      tagStack.push(_tag);
    if(tagStack.size() == 0)
      break;
    ++locpos1;
  }

  // find end element <tag />
  size_t locpos2 = _xml.find(">",localposition);
  if(_xml.at(locpos2-1) != '/')
    locpos2 = _xml.size();

  // find end element
  localposition = std::min(locpos1,locpos2);
  if(localposition >= _xml.size())
    throw std::exception("malformed XML");
  if(localposition == locpos1)
  {
    localposition = _xml.find('>',localposition);
    return _xml.substr(position-1, localposition - position +2);
  }
  return _xml.substr(position-1, localposition - position + 2);
}
//----< return body string >-----------------------------------------

std::string XmlReader::body()
{
  if(_tag.compare("?xml")==0 || _tag.compare("!--")==0)
  {
    return "";
  }
  std::string elem = element();
  size_t locpos1 = elem.find('>');
  if(locpos1 >= elem.size())
    throw std::exception("malformed XML");
  if(elem[locpos1-1] == '/')
    return "";
  std::string localtag = tag();
  size_t locpos2 = elem.find_last_of("</");
  if(locpos2 < elem.size())
    return elem.substr(locpos1+1,locpos2-locpos1-2);
  return "";
}
//----< move to next XML tag >---------------------------------------

bool XmlReader::next()
{
  while(true)
  {
    position = _xml.find('<',position);
    if(position >= _xml.size())
      return false;
    ++position;
    if(_xml.at(position) != '/')
      break;
  }
  return true;
}
//----< return tag string >------------------------------------------

std::string XmlReader::tag()
{
  localposition = position;
  return extractIdentifier(localposition);
}
//----< return vector of attributes >--------------------------------

XmlReader::attribElems XmlReader::attributes()
{
  _attributes.clear();
  if(_tag.compare("?xml")==0 || _tag.compare("!--")==0)
    return _attributes;
  localposition = position;
  // move past tag
  extractIdentifier(localposition);

  // find attributes
  size_t locpos = _xml.find('>',localposition);
  while(true)
  {
    std::string name = extractIdentifier(localposition);
    if(locpos < localposition)
      return _attributes;
    std::string value = extractIdentifier(localposition);
    if(locpos < localposition)
      throw std::exception("malformed XML");
    std::pair<std::string,std::string> elem;
    elem.first = name;
    elem.second = value;
    _attributes.push_back(elem);
  }
  return _attributes;
}
//----< test stub >--------------------------------------------------

#ifdef TEST_XMLREADER
#include <iostream>

int main()
{
  std::cout << "\n  Testing XmlReader";
  std::cout << "\n ===================\n";

  std::string test1 = "<?xml version=\"1.0\"?><!-- top level comment -->";
  test1 += "<parent att1='val1' att2='val2'><child1 /><child2>child2 body<child1 /></child2></parent>";
  XmlReader rdr(test1);

  std::cout << "\n  source = " << test1.c_str() << std::endl;

  //std::cout << "\n  Testing extractIdentifier";
  //std::cout << "\n ---------------------------";
  //std::string ident;
  //size_t position = 1;
  //do
  //{
  //  ident = rdr.extractIdentifier(position);
  //  std::cout << "\n  " << ident.c_str();
  //} while(ident.size() > 0);

  std::cout << "\n  testing next(), tag(), element(), body(), and attributes()";
  std::cout << "\n -----------------------------------------------------------";
  rdr.reset();
  while(rdr.next())
  {
    //std::cout << "\n  tag:     " << rdr.tag().c_str();
    std::cout << "\n  element: " << rdr.element().c_str();
    std::cout << "\n  body:    " << rdr.body().c_str();
    XmlReader::attribElems attribs = rdr.attributes();
    for(size_t i=0; i<attribs.size(); ++i)
      std::cout << "\n  attributes: " << attribs[i].first.c_str() << ", " << attribs[i].second.c_str();
  }
  std::cout << "\n\n";
  return 0;
}
#endif

