#include "evanet.h"




EvaNet::EvaNet()
{
#ifdef WIN32
	WORD versionRequested = MAKEWORD (1, 1);
	WSADATA wsaData;

	if (WSAStartup (versionRequested, & wsaData))
		return ;

	if (LOBYTE (wsaData.wVersion) != 1||
		HIBYTE (wsaData.wVersion) != 1)
	{
		WSACleanup ();
		return ;	}
#endif // WIN


}

EvaNet::~EvaNet()
{
#ifdef WIN32
WSACleanup ();
#endif
}

int EvaNet::send(const char* buff, int length)
{
	return sendto((SOCKET)m_socket, buff, length,  0, (SOCKADDR*) & hostAddr, sizeof (hostAddr));
}

int EvaNet::epoll(char* buff, int lenth)
{
	int recvLen = -1;
	fd_set fdread;
	int ret;
	struct timeval tv = {1, 0};
	ret = select(0, &fdread, NULL, NULL, &tv); 
	if (FD_ISSET(m_socket, &fdread)) 
	{
		ret  = recvfrom(m_socket, buff, lenth, 0, (SOCKADDR*) &hostAddr, &recvLen);		
	}
	return  recvLen;
}

bool EvaNet::create(SOCKET_TYPE type, const char* ip, unsigned short port)
{
	
	 hostAddr.sin_family = AF_INET;
	 hostAddr.sin_port = htons(port);
	 hostAddr.sin_addr.s_addr = inet_addr(ip);
	
	if (m_socket <= 0) close();
	m_socket = socket (PF_INET, type == SOCKET_TYPE_UDP ? SOCK_DGRAM : SOCK_STREAM, 0);
	if (m_socket > 0) return true;
	return false;
}

void  EvaNet::close()
{
	if (m_socket <= 0) 
#ifdef WIN32
		 closesocket(m_socket);
#else
		close(m_socket);
#endif
m_socket = -1;
}
