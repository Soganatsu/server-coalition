/*
	Filename: HelperFunctions.hpp
	Author: Jesse Stojan
	Copyright (c) 2020 - All Rights Reserved
*/
#pragma once

#include <string>
#include <sstream>
#include <stdint.h>
#include <memory.h>

//----------------------------------------------------------------

// ANSI to UNICODE (char -> wchar_t)
wchar_t* ctow(const char* src, const size_t& len = 0);

//----------------------------------------------------------------

// UNICODE to ANSI (wchar_t -> char)
char* wtoc(const wchar_t* src, const size_t& len = 0);

//----------------------------------------------------------------
