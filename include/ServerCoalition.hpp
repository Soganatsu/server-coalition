#pragma once

#include <CommandLineHandler.hpp>

namespace ESCRunMode
{
enum Type {
	Debug,
	Background
};
}//ESCRunMode
using SCRunMode = ESCRunMode::Type;

//================================================================
// Global Variables
//================================================================
extern bool gRunning;
extern SCRunMode gRunMode;

//================================================================
//
//================================================================
