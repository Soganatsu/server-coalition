/*
	Filename: JSON.hpp
	Author: Jesse Stojan
	Copyright (c) 2020 - All Rights Reserved
*/
#pragma once

#include "MixedArray.hpp"

#include <stdio.h>
#include <string>
#include <sstream>

class JSON {
public:
	// Constructor
	JSON();

	// Destructor
	~JSON();

	// Convert added data into JSON string
	size_t stringify();

	// Convert added data into JSON string
	// and place into a destination variable
	// ANSI
	size_t stringify(char** ppDest);

	// Convert added data into JSON string
	// and place into a destination variable
	// UNICODE
	size_t stringify(wchar_t** ppDest);

	// Parse JSON Raw Text (ANSI)
	size_t parse(const char* str);

	// Parse JSON Raw Text (UNICODE)
	size_t parse(const wchar_t* str);

private:
	size_t			m_rawlen;
	wchar_t*		m_raw;

	// Mixed Array of Elements
	MixedArray		m_e;
};
