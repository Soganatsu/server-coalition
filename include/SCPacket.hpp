/*
	Filename: SCPacket.hpp
	Author: Jesse Stojan
	Copyright (c) 2020 - All Rights Reserved
*/
#pragma once
//================================================================
#if defined(_WIN32) || defined(_WIN64)
//================================================================
#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN 1
#endif//WIN32_LEAN_AND_MEAN
#include <Windows.h>

#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32")

#ifndef _WIN32
#define _WIN32 1
#endif//_WIN32

using socket_t = SOCKET;
#ifndef MSG_DONTWAIT
#define MSG_DONTWAIT 0
#endif//MSG_DONTWAIT
//================================================================
#elif defined(__apple__) || defined(__macintosh__) || defined(__mac_os_x__)
//================================================================

#ifndef _OSX
#define _OSX 1
#endif//_OSX

using socket_t = int;
//================================================================
#elif defined(__linux__) || defined(__LINUX__)
//================================================================
#include <sys/types.h>
#include <sys/select.h>
#include <sys/socket.h>
#include <sys/errno.h>
#include <signal.h>

#ifndef _LINUX
#define _LINUX 1
#endif//_LINUX

using socket_t = int;
#define WSAGetLastError errno
//================================================================
#endif//PLATFORM(Win32|Apple|Linux)
//================================================================

//================================================================
// STL Headers
//================================================================
#include <iostream>
#include <stdint.h>

//================================================================
// Date Types
//================================================================
using port_t = uint16_t;

//================================================================
// Enumerators
//================================================================
namespace ESCPDataType
{
enum Type {
	Null		= 0x00,
	Bool		= 0x01,
	Int8		= 0x02,
	Uint8		= 0x03,
	Int16		= 0x04,
	Uint16		= 0x05,
	Int32		= 0x06,
	Uint32		= 0x07,
	Int64		= 0x08,
	Uint64		= 0x09,
	Float		= 0x0A,
	Double		= 0x0B,
	LongDouble	= 0x0C,
	String8		= 0x0D,
	String16	= 0x0E,
	String32	= 0x0F,
	//RESERVED 0x10-0x1F
	Array		= 0x20,
	Key			= 0x40,
	Endian		= 0x80
};//Type
}//ESCPDataType
using SCPDataType = ESCPDataType::Type;

//================================================================

struct SCPKey {
	/*
		E = Endianess
		| 0 1 2 3 4 5 6 7 |
		| SCPDataType | E |
	*/
	uint8_t type;
	uint8_t reserved;
	uint16_t count;
};

//================================================================

/*
	SCPacket -
		Packet Object Base Class
*/
struct SCPacket {
	// Default Constructor
	SCPacket();

	// Virtual Destructor
	virtual ~SCPacket();

	uint64_t bsz;	// Packet Byte Size
	uint8_t* data;	// Data Bytes

	// Encrypt Packet data
	void encrypt(const char* key, const char* salt);

	// Decrypt Packet data
	void decrypt(const char* key, const char* salt);

	//----------------
	// Add Data
	//----------------
	// Add SCPKey
	int add(const SCPKey& v);
	// Add bool
	int add(const bool& v);
	// Add int8_t
	int add(const int8_t& v);
	// Add uint8_t
	int add(const uint8_t& v);
	// Add int16_t
	int add(const int16_t& v);
	// Add uint16_t
	int add(const uint16_t& v);
	// Add int32_t
	int add(const int32_t& v);
	// Add uint32_t
	int add(const uint32_t& v);
	// Add int64_t
	int add(const int64_t& v);
	// Add uint64_t
	int add(const uint64_t& v);
	// Add float
	int add(const float& v);
	// Add double
	int add(const double& v);
	// Add long double
	int add(const long double& v);
	// Add char
	int add(const char* v);
	// Add wchar_t
	int add(const wchar_t* v);
	// Add char32_t
	int add(const char32_t* v);

	// Add Array SCPKey
	int add(const SCPKey* v, const uint32_t& count);
	// Add Array bool
	int add(const bool* v, const uint32_t& count);
	// Add Array int8_t
	int add(const int8_t* v, const uint32_t& count);
	// Add Array uint8_t
	int add(const uint8_t* v, const uint32_t& count);
	// Add Array int16_t
	int add(const int16_t* v, const uint32_t& count);
	// Add Array uint16_t
	int add(const uint16_t* v, const uint32_t& count);
	// Add Array int32_t
	int add(const int32_t* v, const uint32_t& count);
	// Add Array uint32_t
	int add(const uint32_t* v, const uint32_t& count);
	// Add Array int64_t
	int add(const int64_t* v, const uint32_t& count);
	// Add Array uint64_t
	int add(const uint64_t* v, const uint32_t& count);
	// Add Array float
	int add(const float* v, const uint32_t& count);
	// Add Array double
	int add(const double* v, const uint32_t& count);
	// Add Array long double
	int add(const long double* v, const uint32_t& count);
	// Add Array char
	int add(const char** v, uint32_t* lengths, const uint32_t& count);
	// Add Array wchar_t
	int add(const wchar_t** v, uint32_t* lengths, const uint32_t& count);
	// Add Array char32_t
	int add(const char32_t** v, uint32_t* lengths, const uint32_t& count);

	//----------------
	// Get Data
	//----------------
	// Get SCPKey
	int get(uint64_t idx, SCPKey** ppDest);
	// Get bool
	int get(uint64_t idx, bool* pDest);
	// Get bool
	int get(uint64_t idx, int8_t* pDest);
	// Get bool
	int get(uint64_t idx, uint8_t* pDest);
	// Get bool
	int get(uint64_t idx, int16_t* pDest);
	// Get bool
	int get(uint64_t idx, uint16_t* pDest);
	// Get bool
	int get(uint64_t idx, int32_t* pDest);
	// Get bool
	int get(uint64_t idx, uint32_t* pDest);
	// Get bool
	int get(uint64_t idx, int64_t* pDest);
	// Get bool
	int get(uint64_t idx, uint64_t* pDest);
	// Get bool
	int get(uint64_t idx, float* pDest);
	// Get double
	int get(uint64_t idx, double* pDest);
	// Get long double
	int get(uint64_t idx, long double* pDest);
	// Get char string
	int get(uint64_t idx, char** ppDest);
	// Get wchar_t string
	int get(uint64_t idx, wchar_t** ppDest);
	// Get char32_t string
	int get(uint64_t idx, char32_t** ppDest);

	// Get Array SCPKey
	int get(uint64_t idx, SCPKey** ppDest, uint32_t* pCount);
	// Get Array bool
	int get(uint64_t idx, bool** ppDest, uint32_t* pCount);
	// Get Array int8_t
	int get(uint64_t idx, int8_t** ppDest, uint32_t* pCount);
	// Get Array uint8_t
	int get(uint64_t idx, uint8_t** pDest, uint32_t* pCount);
	// Get Array int16_t
	int get(uint64_t idx, int16_t** pDest, uint32_t* pCount);
	// Get Array uint16_t
	int get(uint64_t idx, uint16_t** pDest, uint32_t* pCount);
	// Get Array int32_t
	int get(uint64_t idx, int32_t** pDest, uint32_t* pCount);
	// Get Array uint32_t
	int get(uint64_t idx, uint32_t** pDest, uint32_t* pCount);
	// Get Array int64_t
	int get(uint64_t idx, int64_t** pDest, uint32_t* pCount);
	// Get Array uint64_t
	int get(uint64_t idx, uint64_t** pDest, uint32_t* pCount);
	// Get Array float
	int get(uint64_t idx, float** pDest, uint32_t* pCount);
	// Get Array double
	int get(uint64_t idx, double** pDest, uint32_t* pCount);
	// Get Array long double
	int get(uint64_t idx, long double** pDest, uint32_t* pCount);
	// Get Array char
	int get(uint64_t idx, char*** pppDest, uint32_t* pCount);
	// Get Array wchar_t
	int get(uint64_t idx, wchar_t*** pppDest, uint32_t* pCount);
	// Get Array char32_t
	int get(uint64_t idx, char32_t*** pppDest, uint32_t* pCount);

};
