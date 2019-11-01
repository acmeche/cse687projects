//////////////////////////////////////////////////////////////////////////////////////////////////
// File:        Executive.cpp																
// Purpose:     Responsible for initializing the executive class and running the test cases	
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
   10/8/2019    1.0        Initial Creation
   10/17/2019   1.0        Added system pause command to allow user to see output on screen before
                           closing program window
   10/22/2019   2.0        Coppied TestRunner.cpp code into project and replaced it with Executive class
   10/31/2019   2.1        Implemented logic that reads from config Xml file and dynamicallys loads the 
                           appropriate test case DLLs based on config definition.  Upon loading a DLL
                           within the process space of the Executive, the runTests() method of the 
                           TestHarness is called to execute each test case
*/
#include <fstream>
#include <iostream>
#include <sstream>
#include <Windows.h>
#include <wchar.h>
#include "TestHarness.h"
#include "Logger.h"
#include "..\XmlReader\XmlReader.h"

using namespace CSE687_Project2;

int main(int argc, char** argv)
{
    try {
        size_t numberOfConvertedChars = 0;
        
        wchar_t* cmdLineArg;
        if (argc > 1) {
            cmdLineArg = new wchar_t[strlen(argv[1]) + 1];
            mbstowcs_s(&numberOfConvertedChars, cmdLineArg, strlen(argv[1]) + 1, argv[1], _TRUNCATE);
        }
        else {
            cmdLineArg = const_cast<wchar_t*>(L"TestXml.xml");
        }

        TCHAR* xmlConfigFilename;
        TCHAR xmlConfigPath[MAX_PATH];
        
        GetFullPathName(cmdLineArg, MAX_PATH, xmlConfigPath, &xmlConfigFilename);
              
        std::stringstream xmlDoc;
        xmlDoc << std::ifstream(xmlConfigPath).rdbuf();

        XmlReader xmlReader(xmlDoc.str());      
        xmlReader.reset();
        while(xmlReader.next())
        {
            numberOfConvertedChars = 0;

            if (xmlReader.tag() == "TestRequest") {
                size_t rawStringSize = xmlReader.element().length();
                wchar_t* convertedStringResult = new wchar_t[rawStringSize];
                mbstowcs_s(&numberOfConvertedChars, convertedStringResult, rawStringSize, xmlReader.body().c_str(), _TRUNCATE);
           
                TCHAR* dllFile;
                TCHAR dllPath[MAX_PATH];
                GetFullPathName(convertedStringResult, MAX_PATH, dllPath, &dllFile);

                // Load the DLL
                HINSTANCE dllHandle = ::LoadLibrary(dllPath);

                if (!dllHandle) {
                    Logger::writeLog(LOGLEVEL::DEBUG_FAILURE_DETAIL, E_RESULT::FAIL, "Unable to load DLL.");
                }
                else {
                    TestHarness harness;
                    harness.runTests();

                    // Destroy it DLL handle explicitly
                    ::FreeLibrary(dllHandle);
                }
            }
        }
    }
    catch (...) {
        Logger::writeLog(LOGLEVEL::DEBUG_FAILURE_DETAIL, E_RESULT::FAIL, "A general application error occured while executing test cases.");
    }

    system("pause");
    return 0;
}