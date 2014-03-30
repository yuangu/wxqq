#ifndef EVANET_H
#define EVANET_H
#include "headers.h"
#include "singleton.h"
enum SOCKET_TYPE
{
	SOCKET_TYPE_UDP,
	SOCKET_TYPE_TCP,
};

class EvaNet :public CSingleton<EvaNet>
{
public:
	EvaNet();
	~EvaNet();
	bool create(SOCKET_TYPE type, const char* ip, unsigned short port);
	int send(const char* buff, int length);
	int epoll( char* buff, int lenth);

	void close();
private:
	unsigned int m_socket;

	 sockaddr_in hostAddr;
};
#endif