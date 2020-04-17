#pragma once

#include <stdio.h>
#include <stdint.h>

/*
	HArray -
		Heterogenous Array that can store and mix multiple data types.
*/
class HArray {
public:
	// Constructor
	HArray();

	// Destructor
	~HArray();

	template <typename T>
	size_t push(const T& v) {
		//TODO:
		return 0;
	}
	size_t push(void* v, const size_t& bsz) {
		//TODO:
		return 0;
	}

	template <typename T>
	size_t push(const T* v, const size_t& length) {
		//TODO:
		return 0;
	}

	// Get Basic Data Type
	template <typename T>
	const T& get(const size_t& index) {
	}

	// Get Object Data
	template <typename T>
	T* get(const size_t& index) {

	}

	// Get Array
	template <typename T>
	bool get(const size_t& index, T** ppDest, size_t* pLength) {
		size_t len = 0;
		//TODO: Get data
		*ppDest = nullptr;
		*pLength = len;
		return true;
	}

	// Get Multi-Dimensional Array
	template <typename T>
	bool get(const size_t& index, T*** pppDest, size_t** ppLengths, size_t* pCount) {
		if(index >= m_)
		size_t cnt = m_cnts[index];
		T** ppArr = new T*[cnt];
		for (size_t i = 0; i < cnt; ++i) {
			T* buff = new T[1];
			ppArr[i] = buff;
			buff = nullptr;
		}
		//TODO: Get data
		*pppDest = ppArr;
		ppArr = nullptr;
		return true;
	}

private:
	size_t						m_len;
	size_t						m_bsz;
	size_t*						m_locs;
	size_t*						m_cnts;
	uint8_t**					m_bytes;

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
