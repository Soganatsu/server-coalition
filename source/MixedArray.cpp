/*
	Filename: MixedArray.cpp
	Author: Jesse Stojan
	Copyright (c) 2020 - All Rights Reserved
*/
#include <MixedArray.hpp>

//----------------------------------------------------------------

MixedArray::MixedArray() {
	m_len = 0;
	m_bsz = 0;
	m_offsets = nullptr;
	m_counts = nullptr;
	m_lengths = nullptr;
	m_bytes = nullptr;
}

//----------------------------------------------------------------

MixedArray::~MixedArray() {
	if (m_offsets) {
		delete[] m_offsets;
		m_offsets = nullptr;
	}
	if (m_counts) {
		delete[] m_counts;
		m_counts = nullptr;
	}
	if (m_bytes) {
		delete[] m_bytes;
		m_bytes = nullptr;
	}
	if (m_lengths) {
		for (size_t i = 0; i < m_len; ++i) {
			if (m_lengths[i]) {
				delete[] m_lengths[i];
				m_lengths[i] = nullptr;
			}
		}
		delete[] m_lengths;
		m_lengths = nullptr;
	}
	m_len = 0;
	m_bsz = 0;
}

//----------------------------------------------------------------

void MixedArray::popFront() {
	//TODO: 
}

//----------------------------------------------------------------

void MixedArray::pop() {
	//TODO: 
}

//----------------------------------------------------------------

size_t MixedArray::AddData(void* data, const size_t& bsz) {
	if (!bsz) return 0;
	size_t start = m_bsz;
	size_t end = m_bsz + bsz;
	uint8_t* buff = new uint8_t[end];
	if (!buff) {
		return ~(size_t());
	}

	// Copy memory into buffer
	memcpy(buff, m_bytes, m_bsz);

	// Copy new memory into buffer
	memcpy(&buff[start], data, bsz);

	// Free original memory and remove pointer reference
	delete[] m_bytes;
	m_bytes = nullptr;

	// Assign pointer reference to new memory
	m_bytes = buff;
	buff = nullptr;

	// Set new byte size
	m_bsz = end;

	return start;
}

//----------------------------------------------------------------
