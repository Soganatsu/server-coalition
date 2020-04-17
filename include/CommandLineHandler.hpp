#pragma once

#if defined(__M_X64__) || defined(__amd64__) || defined(_WIN64)
#ifndef __X64__
#define __X64__ 1
#endif//__X64__
#else
#ifndef __X64__
#define __X64__ 0
#endif//__X64__
#endif//64/32-Bit

// Windows Platform
#if defined(_WIN32) || defined(_WIN64)
/*
	Disable Warnings Visual Studio Warnings,
		26812 - The enum type '' is unscoped. Prefer 'enum class' over 'enum' (Enum.3).
*/
#pragma warning(disable: 26812)

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN 1
#endif//WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <windowsx.h>

#endif//_WIN32||_WIN64

// Linux Platform
#if defined(__linux__) || defined(__LINUX__)
#ifndef _LINUX
#define _LINUX
#endif//_LINUX
#include <sys/stat.h>
#include <sys/errno.h>
#endif//__linux__

// STL Headers
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include <time.h>
#include <thread>
#include <chrono>
#include <stdint.h>
#include <float.h>

//================================================================
// Macro Definitions
//================================================================
#if !defined(CLH_FAILED)
#define CLH_FAILED(v) (static_cast<CLHStatus>(v) < CLHStatus::Success)
#endif//CLH_FAILED

//================================================================
// Enumerators
//================================================================
namespace ECLHStatus {
enum Type : int {
	Success = 0x0
};//Type
}//ECLHStatus
using CLHStatus = ECLHStatus::Type;

//================================================================
// Global Functions
//================================================================
/*
	CommandLineHandler -
		Handles any command line arguments
	@param argc - argument count
	@param argv - argument values
	@param arge - environment values
	@return CLHStatus - Status Code
*/
CLHStatus CommandLineHandler(int argc, char** argv, char** arge);

//----------------------------------------------------------------

/*
	CLHGetLastError -
		Get the last Error Code for CommandLineHandler
	@return CLHStatus - Last Error Status Code
*/
const CLHStatus& CLHGetLastError();

//----------------------------------------------------------------
