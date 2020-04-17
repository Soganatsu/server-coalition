#include <ServerCoalition.hpp>

// Program Entry Point
int main(int argc, char** argv, char** arge) {
	// Check Command Line Arguments first
	if (CLH_FAILED(CommandLineHandler(argc, argv, arge))) {
		// Something went wrong
		return CLHGetLastError();
	}

	// Initialize any Third-Party features
	//TODO: Add SQLite3

	// Perform Run Mode specific tasks
#if defined(_LINUX)
	if (gRunMode != SCRunMode::Debug) {
		//TODO: Daemonize
	}
#endif//_LINUX

	// Main Loop
	while (gRunning) {

		std::this_thread::sleep_for(std::chrono::milliseconds(1));
	}

	return EXIT_SUCCESS;
}
