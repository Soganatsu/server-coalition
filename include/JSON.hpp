/*
	Filename: JSON.hpp
	Author: Jesse Stojan
	Copyright (c) 2020 - All Rights Reserved
*/
#pragma once

#include "MixedArray.hpp"
#include <string>

#define JSON_STRINGIFY_UGLIFY 0x1
#define JSON_STRINGIFY_BEAUTIFY	0x2
#define JSON_STRINGIFY_DEFAULT JSON_STRINGIFY_UGLIFY

class JSON {
public:
	// Constructor
	JSON();

	// Destructor
	~JSON();

	// Convert added data into JSON string
	size_t stringify(const uint32_t& flags = JSON_STRINGIFY_DEFAULT);

	// Convert added data into JSON string
	// and place into a destination variable
	// ANSI
	size_t stringify(char** ppDest, const uint32_t& flags = JSON_STRINGIFY_DEFAULT);

	// Convert added data into JSON string
	// and place into a destination variable
	// UNICODE
	size_t stringify(wchar_t** ppDest, const uint32_t& flags = JSON_STRINGIFY_DEFAULT);

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
