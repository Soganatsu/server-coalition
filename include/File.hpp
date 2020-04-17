#pragma once

#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>

#if defined(UNICODE)
using string_t = wchar_t;
#else
using string_t = char;
#endif//UNICODE

class File {
public:
	// Constructor
	File();

	// Destructor
	~File();

	// Load File by pathname
	int Load(const string_t& pathname, std::ios& flags);

	// Reload File
	int Reload();

	// Write Bytes to File
	size_t Write(void* pData, const size_t& bsz);

	// Close File
	void Close();

	const size_t& size() const { return m_bsz; }

private:
	uint8_t m_pathlen;
	string_t* m_pathname;

	size_t	m_bsz;
	uint8_t* m_data;

};
