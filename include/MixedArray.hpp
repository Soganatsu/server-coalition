/*
	Filename: MixedArray.hpp
	Author: Jesse Stojan
	Copyright (c) 2020 - All Rights Reserved
*/
#pragma once

#include <stdio.h>
#include <stdint.h>
#include <memory.h>

/*
	MixedArray -
		Mixed Array that can store and mix multiple data types.
*/
class MixedArray {
public:
	// Constructor
	MixedArray();

	// Destructor
	~MixedArray();

	// Remove First Element
	void popFront();

	// Remove Last Element
	void pop();

	// Add Basic Data Type Data
	template <typename T>
	size_t push(const T& v) {
		//TODO:

		return 0;
	}

	// Push an Object
	size_t push(void* v, const size_t& bsz) {
		//todo:
		return 0;
	}

	// Push Single Dimension Array
	template <typename T>
	size_t push(const T* v, const size_t& length) {
		//TODO:
		return 0;
	}

	// Push Multi-Dimensional Array
	// 
	template <typename T>
	size_t push(
		const T** v,
		const size_t* lengths,
		const size_t& count,
		const size_t& esz)
	{
		//TODO:
		T** buff = new T*[count];
		size_t* lens = new size_t[count];
		for (size_t i = 0; i < count; ++i) {
			lens[i] = lengths[i];
		}

		return size_t();
	}

	// Get Basic Data Type
	template <typename T>
	const T& get(const size_t& index) const {
		return static_cast<T>(m_bytes[m_offsets[index]]);
	}

	// Get Object Data
	template <typename T>
	size_t get(const size_t& index, T** ppDest) {
		size_t bsz = 0;

		return bsz;
	}

	// Get Array
	template <typename T>
	bool get(
		const size_t& index,
		T** ppDest,
		size_t* pLength)
	{
		size_t len = 0;
		
		//TODO: Get data

		*ppDest = nullptr;
		*pLength = len;
		return true;
	}

	// Get Multi-Dimensional Array
	template <typename T>
	bool get(
		const size_t& index,
		T*** pppDest,
		size_t** ppLengths,
		size_t* pCount)
	{
		if (index >= m_len) return false;

		// Variables
		size_t offset = m_offsets[index];
		size_t count = m_counts[index];
		size_t* lengths = new size_t[count];
		T** data = new T*[count];

		// Copy Lengths
		memcpy(lengths, m_lengths[index], count * sizeof(size_t));

		// Extract Data
		for (size_t i = 0; i < count; ++i) {
			size_t sz = (lengths[index][i] * sizeof(lengths[index][i]));
			T* buff = new T[lengths[index][i]];
			memcpy(m_bytes[offset], buff[i], sz);
			data[i] = buff;
			offset += sz;
			buff = nullptr;
		}

		// Set Destination Variables
		*pppDest = data;
		*ppLengths = lengths;
		*pCount = count;

		// Reset for security
		data = nullptr;
		lengths = nullptr;
		count = 0;

		// Success
		return true;
	}

private:
	size_t AddData(void* data, const size_t& bsz);

private:
	size_t						m_len;
	size_t						m_bsz;
	size_t*						m_offsets;
	size_t*						m_counts;
	//size_t*						m_types;
	size_t**					m_lengths;
	uint8_t*					m_bytes;

};

//size_t push(const bool& v);
//size_t push(const int8_t& v);
//size_t push(const uint8_t& v);
//size_t push(const int16_t& v);
//size_t push(const uint16_t& v);
//size_t push(const int32_t& v);
//size_t push(const uint32_t& v);
//size_t push(const int64_t& v);
//size_t push(const uint64_t& v);
//size_t push(const float& v);
//size_t push(const double& v);
//size_t push(const long double& v);
//size_t push(const wchar_t& v);
//size_t push(const char16_t& v);
//size_t push(const char32_t& v);
//size_t push(const bool* v, const size_t& length);
//size_t push(const int8_t* v, const size_t& length);
//size_t push(const uint8_t* v, const size_t& length);
//size_t push(const int16_t* v, const size_t& length);
//size_t push(const uint16_t* v, const size_t& length);
//size_t push(const int32_t* v, const size_t& length);
//size_t push(const uint32_t* v, const size_t& length);
//size_t push(const int64_t* v, const size_t& length);
//size_t push(const uint64_t* v, const size_t& length);
//size_t push(const float* v, const size_t& length);
//size_t push(const double* v, const size_t& length);
//size_t push(const long double* v, const size_t& length);
//size_t push(const wchar_t* v, const size_t& length);
//size_t push(const char16_t* v, const size_t& length);
//size_t push(const char32_t* v, const size_t& length);
