#pragma once
#ifndef __COMMAND_LINE_HANDLER_COMMANDS_HPP__
#define __COMMAND_LINE_HANDLER_COMMANDS_HPP__

// Command Line Handler - Commands

/*
	Output Help
*/
#define CLH_HELP "help"
#define CLH_HELP_SH "?"

/*
	Run in Debug Mode
*/
#define CLH_RUN_DEBUG "debug"
#define CLH_RUN_DEBUG_SH "dbg"

/*
	Configure Assigned Listening Port
*/
#define CLH_CONFIG_PORT "port"
#define CLH_CONFIG_PORT_SH "p"

/*
	Add Remote Distributed Server (Node)
*/
#define CLH_CONFIG_ADD_REMOTE_NODE "add-node"
#define CLH_CONFIG_ADD_REMOTE_NODE_SH "+n"

/*
	Remote Remote Distributed Server (Node)
*/
#define CLH_CONFIG_REMOVE_REMOTE_NODE "rm-node"
#define CLH_CONFIG_REMOVE_REMOTE_NODE_SH "-n"

//TODO: Add more commands

#endif//__COMMAND_LINE_HANDLER_COMMANDS_HPP__
