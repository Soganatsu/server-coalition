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
