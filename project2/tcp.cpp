#include "tcp.h"

using namespace std;

int tcp::create()
{
	sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1) 
    {
		printf("Create socket failed!\n");
	}
	return sock;
}

bool tcp::Bind(unsigned short port) {
	if (sock <= 0) {
		create();
	}
	sockaddr_in saddr;
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(port); 
	saddr.sin_addr.s_addr = htons(0);
	if (bind(sock, (sockaddr*)&saddr, sizeof(saddr)) != 0) 
    {
		printf("bind port %d failed!", port);
		return false;
	}
	printf("bind port %d succeeded.", port);
	listen(sock, 1); // 监听指定的端口，只用来创建链接
	return true;
}

bool tcp::Connect(string ip, unsigned short port, unsigned int timeoutms)
{
	if (sock <= 0) {
		create();
	}
	sockaddr_in saddr;
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(port);
	saddr.sin_addr.s_addr = inet_addr(ip.c_str());

	block(false);
	fd_set set; 
	if (connect(sock, (sockaddr*)&saddr, sizeof(saddr)) != 0) {
		FD_ZERO(&set);
		FD_SET(sock, &set);
		timeval tm;
		tm.tv_sec = 0;
		tm.tv_usec = timeoutms * 1000;
		if (select(sock + 1, 0, &set, 0, &tm) <= 0) {
			// 只要有一个可写，就会返回文件描述符的值，否则返回-1，超时返回0
			printf("connect timeout or error!\n");
			printf("connect %s:%d failed!: %s\n", ip, port, strerror(errno));
			return false;
		}
	}
	block(true);
	printf("connect %s:%d succeded!\n", ip, port);
	return true;
}

bool tcp::block(bool a)
{
	if (sock <= 0) 
    {
		return false;
	}
	unsigned long ul = 0;
	if (!a) 
    {
		ul = 1;
	}
	ioctlsocket(sock, FIONBIO, &ul);
	return true;
}