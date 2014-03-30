#ifndef HEADERS_H
#define HEADERS_H
#ifdef WIN32
#pragma comment(lib,"ws2_32.lib")
#include <WinSock2.h>
#else
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#endif




#endif