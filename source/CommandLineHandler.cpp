#include <CommandLineHandler.hpp>
#include <CLHCommands.hpp>

//================================================================
// `Local` Macro Definitions
//================================================================
#ifndef CLH_CHECKARG
#define CLH_CHECKARG(a) (!(strncmp(a, argv[i], sizeof a )) || !(strncmp(a##_SH, argv[i], sizeof a)))
#endif//CLH_CHECKARG

//================================================================
// `Local` Global Variables
//================================================================
CLHStatus CLH_lastError = CLHStatus::Success;


//----------------------------------------------------------------

const CLHStatus& CLHGetLastError() {
	return CLH_lastError;
}

//----------------------------------------------------------------

CLHStatus CommandLineHandler(
	int argc,
	char** argv,
	char** arge)
{
	for (int i = 0; i < argc; ++i) {
		if (CLH_CHECKARG(CLH_RUN_DEBUG)) {

		}
	}

	return CLH_lastError;
}

//----------------------------------------------------------------
