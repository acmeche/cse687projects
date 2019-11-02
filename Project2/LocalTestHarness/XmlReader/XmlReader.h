#ifndef XMLREADER_H
#define XMLREADER_H
//////////////////////////////////////////////////////////////////////////////////////////////////
// File:        XmlReader.h														
// Purpose:     Header file that acts as the declaration of XmlReader code.
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
   DATE         VERSION     DESCRIPTION
   ----         -------     ----------------------------------------------------------------------
   11/01/2019   1.0         Initial creation
*/
#pragma warning( push )
#pragma warning( disable : 4251 )

#include <vector>
#include <fstream>
#include <string>
#include <sstream>

/**
* This class was imported to satisfy the following criteria:
    1.)	Shall be prepared using the latest version of Visual Studio, and written in the standard C++ programming 
        language, using the standard C++ libraries.
    2.)	Shall use Visual Studio, Community Edition available at no cost.
    4.)	Shall accept a TestRequest XML string defining one or more test elements by naming dynamic link libraries.
*/

class __declspec(dllexport) XmlReader
{
public:
  const static std::string TEST_REQUEST_TAG;
  typedef std::vector<std::pair<std::string,std::string>> attribElems;
  XmlReader(const std::string& xml);
  XmlReader(std::stringstream xmlDoc);
  bool next();
  std::string tag();
  std::string getPath(); // returns a string containing a file path
  void setPath(std::string filePath);  // sets the path variable with a string denoating a file path
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

#pragma warning( pop )
#endif
