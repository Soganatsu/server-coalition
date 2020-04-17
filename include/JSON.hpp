#pragma once

#include <stdio.h>
#include <string>
#include <sstream>

#include "Array.hpp"

template <typename T>
class JSON {
public:
	// Constructor
	JSON();

	// Destructor
	~JSON();

	// Convert added data into JSON string
	size_t stringify();

	// Parse JSON Raw Text
	size_t parse(const T* str);

private:
	size_t			m_rawlen;
	T*				m_raw;

	size_t			m_vcount;
	size_t*			m_vlengths;
	T**				m_vals;

};
