#ifndef XMLREADER_H
#define XMLREADER_H
//////////////////////////////////////////////////////////////////////////////////////////////////
// File:        XmlReader.cpp																
// Purpose:     Parse XML strings with additional DLL library functionality
// Version:     2.0																			
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
   10/28/2019    2.0       Initial Creation
   10/30/2019	 2.0       Added a new constructor that accepts a filestream object, created a new private
						   data member std::string path (the option to store a file path) along with a getPath
						   and setPath function, and added the public member function getTestRequestDllLocations(),
						   which allows for reading DLL locations from an XML file.

*/
#include <vector>
#include <fstream>
#include <string>



class XmlReader
{
public:
  const static std::string TEST_REQUEST_TAG;
  typedef std::vector<std::pair<std::string,std::string>> attribElems;
  XmlReader(const std::string& xml);
  XmlReader(std::ifstream file);
  bool next();
  std::string tag();
  std::string getPath();
  void setPath(std::string filePath);
  std::vector<std::string> getTestRequestDllLocations();
  attribElems attributes();
  std::string body();
  std::string element();
  std::string extractIdentifier(size_t& pos);
  void reset();
private:
  // source string
  std::string _xml;
  size_t position;
  std::string path; //path for file
  // current element parts
  std::string _tag;
  attribElems _attributes;
  size_t localposition;
};

inline void XmlReader::reset() { position = 0; }

#endif
