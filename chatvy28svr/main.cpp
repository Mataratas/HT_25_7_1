#include "CTCPServer.h"
//======================================================================================
int main() {
	TSPS CS;
	if (!CS.init_ok())
		std::cout << BOLDRED << "\nFailed to run chat server\n" << RESET << std::endl;
	else
		if (CS.process_clients());

	return 0;
}
//======================================================================================
