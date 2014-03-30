#include "src/evanet.h"

int main()
{
	EvaNet::getInstance().create(SOCKET_TYPE_UDP, "183.60.48.174", 8000);
	


	return 1;
}