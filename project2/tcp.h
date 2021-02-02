#include<thread>
#include<iostream>
#include<winsock2.h>
#include<string>

#pragma comment(lib,"ws2_32.lib")


class tcp
{
    int create();
    bool Bind(unsigned short);
    tcp acce();
    void close();
    int Recv(std::string);
    int Send(std::string);
    bool Connect(std::string, unsigned short, unsigned int);
    bool block(bool);//设置阻塞
    void init()
    {
        WSADATA ws;
        WSAStartup(MAKEWORD(2, 2), &ws);
    }
	unsigned short port = 14370; // 建立连接的端口
	int sock = 0; 
	std::string ip;
};