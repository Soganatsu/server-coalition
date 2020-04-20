/*
	Filename: SCSocket.hpp
	Author: Jesse Stojan
	Copyright (c) 2020 - All Rights Reserved
*/
#pragma once

#include <SCPacket.hpp>

//================================================================

/*
	SCSocket -
		IP Socket Object Base Class
*/
class SCSocket {
public:
	// Constructor
	SCSocket();

	// Virtual Destructor
	virtual ~SCSocket();

protected:
	port_t	m_port;

};

//================================================================
