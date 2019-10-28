//////////////////////////////////////////////////////////////////////////////////////////////////
// File:        LocalTestHarness.cpp																
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
*/

#include <iostream>
#include <fstream>
#include <vector>

#undef UNICODE 
#include <Windows.h>
#include <tchar.h>

#include "Executive.h"
#include "XmlReader.h"

using namespace CSE687_Project2;

typedef bool (*executeMethod)();

int main(int argc, char** argv)
{
    // Read in file and store in text
    std::string xmlText;
    std::fstream xml(argv[1]);
    if (xml.is_open())
    {
        while (std::getline(xml, xmlText));
    }

    // TODO: Need to figure out if parsing should happen here or in executive class
    // Assuming argv[1] is the correct location to the XML file location
    XmlReader xmlReader(xmlText);
    while (xmlReader.next())
    {
        std::string tag = xmlReader.tag().c_str();
        if (tag == "TestRequest")
        {
            std::string dllLocation = xmlReader.body().c_str();
            std::cout << dllLocation << "\n";
            //SetCurrentDirectory("D:\\ProgrammingStuff\\programmingstuff\\Syracuse\\CSE 687\\Project2\\LocalTestHarness\\bin\\");
            HINSTANCE dll = LoadLibraryW(std::wstring(dllLocation.begin(), dllLocation.end()).c_str());
            if (!dll)
            {
                std::cout << "Could not load the dynamic library\n";
                return EXIT_FAILURE;
            }

            /**
            Commentting out this section of code since it doesn't appear able to load the method. Will continue to look into it
            executeMethod test = (executeMethod)GetProcAddress(dll, "execute");
            if (!test)
            {
                auto e = GetLastError();
                std::cout << "Could not load the function\n";
                std::cout << e << "\n";
                FreeLibrary(dll);
                return EXIT_FAILURE;
            }
            
            test();
            */
            FreeLibrary(dll);
        }
    }

    Executive executive;
    executive.runTests();

    system("pause");
    return 0;
}
