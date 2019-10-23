//////////////////////////////////////////////////////////////////////////////////////////////////
// File:        TestHarnessExporter.cpp																
// Purpose:     Header file that acts as helpful way to reduce dllexport duplicate code for 
//              TestHarness package
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
   10/22/2019   1.0         Initial creation
*/
#pragma once

#ifdef TESTHARNESS_EXPORTS
#define TESTHARNESS_API __declspec(dllexport)
#else
#define TESTHARNESS_API __declspec(dllimport)
#endif