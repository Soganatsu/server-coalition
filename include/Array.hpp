/*
	Filename: Array.hpp
	Author: Jesse Stojan
	Copyright (c) 2020 - All Rights Reserved
*/
#pragma once

#include <stdio.h>

// Non-Pointer Array
template <typename T>
class Array {
public:
	// Default Constructor
	Array() {}

	// Copy Constructor
	template <typename U>
	Array(const Array<U>& c) {}

	// Move Constructor
	template <typename U>
	Array(Array<U>&& m) {}

	// Destructor
	~Array() {}

	T& operator[](const size_t& idx) {
		if (idx < 0 || idx >= m_len) return m_err;
		return m_arr[idx];
	}

	const size_t& length() const { return m_len; }

	void push(const T&) {}
	void pop() {}
	void insert(const uint64_t& idx, const T& v) {}
	void remove(const uint64_t& idx) {}

private:
	size_t m_len;
	T* m_arr;
	T m_err;
};

// Pointer Array
template <typename T>
class Array<T*> {
public:

	// Default Constructor
	Array() {}

	// Copy Constructor
	template <typename U>
	Array(const Array<U>& c) {}

	// Move Constructor
	template <typename U>
	Array(Array<U>&& m) {}

	// Destructor
	~Array() {}

	T* operator[](const size_t& idx) {
		if (idx < 0 || idx >= m_len) return nullptr;
		return m_arr[idx];
	}

	const size_t& length() const { return m_len; }

	void push(const T&) {
	}
	void pop() {
	}
	void insert(const uint64_t& idx, const T& v) {
	}
	void remove(const uint64_t& idx) {
	}

private:
	size_t m_len;
	T* m_arr;
};