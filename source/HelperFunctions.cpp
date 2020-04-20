/*
	Filename: HelperFunctions.cpp
	Author: Jesse Stojan
	Copyright (c) 2020 - All Rights Reserved
*/
#include <HelperFunctions.hpp>

//----------------------------------------------------------------

// ANSI to UNICODE
wchar_t* ctow(const char* src, const size_t& len) {
	if (!src) return nullptr;
	size_t length = len;
	if (!length) {
		length = strnlen(src, UINT64_MAX - 1);
	}
	union {
		wchar_t w;
		char b[2];
	} u;
	wchar_t* s = new wchar_t[(length + 1)];
	if (!s) { return nullptr; }
	wmemset(s, L'\0', (length + 1));

	u.w = L'\0';
	for (size_t i = 0; i < length; ++i) {
		u.b[0] = src[i];
		s[i] = u.w;
	}

	return s;
}

//----------------------------------------------------------------

// UNICODE to ANSI
char* wtoc(const wchar_t* src, const size_t& len) {
	if (!src) return nullptr;
	size_t length = len;
	if (!length) {
		length = wcsnlen(src, UINT64_MAX - 1);
	}
	union {
		wchar_t w;
		char b[2];
	} u;
	char* s = new char[(length + 1)];
	if (!s) { return nullptr; }
	memset(s, '\0', (length + 1));

	u.w = L'\0';
	for (size_t i = 0; i < length; ++i) {
		u.w = src[i];
		s[i] = u.b[0];
	}

	return s;
}

//----------------------------------------------------------------
