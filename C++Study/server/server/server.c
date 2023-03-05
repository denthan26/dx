#define _CRT_SECURE_NO_WARNINGS

#include<WinSock2.h>// windows socked 第二版本
#pragma comment(lib, "Ws2_32.lib")
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//#include <WS2tcpip.h>
int main()
{
	// 启动网络库
	WORD wdVersion = MAKEWORD(2, 2);// 高字节 副版本
	WSADATA wdSockMsg;
	int nRes = WSAStartup(wdVersion, &wdSockMsg);
	if (0 != nRes)
	{
		switch (nRes)
		{
		case WSASYSNOTREADY:
			printf("亲亲，重启下电脑试试，或者检查网络库\n");
			break;
		case WSAVERNOTSUPPORTED:
			printf("请更新网络库\n");
			break;
		case WSAEINPROGRESS:
			printf("重新启动\n");
			break;
		case WSAEPROCLIM:
			printf("请尝试关闭不必要的软件，以为当前网络提供充足资源\n");
			break;
		case WSAEFAULT:
			break;
		}
		
		return 0;
	}
	// 校验版本
	if (2 != HIBYTE(wdSockMsg.wVersion) || 2 != LOBYTE(wdSockMsg.wVersion))
	{
		// 说明版本不对
		WSACleanup();// 关闭/清理网络库
		return 0;
	}
		
	SOCKET socketServer = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == socketServer)
	{
		int a = WSAGetLastError();
		// 清理网络库
		WSACleanup();
		return 0;
	}

	// 2017以上不支持inet_addr
	/*struct sockaddr_in si;
	si.sin_family = AF_INET;
	si.sin_port = htons(12345);
	si.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");*/
	
	struct sockaddr_in si;
	si.sin_family = AF_INET;
	si.sin_port = htons(12345);
	struct in_addr s;//存放Ipv4地址的结构体
	inet_pton(AF_INET, "127.0.0.1", (void*)&si.sin_addr.S_un.S_addr);//进行转换
	// 绑定地址与端口
	int bres = bind(socketServer, (const struct sockaddr*)&si, sizeof(si));
	if (SOCKET_ERROR == bres)
	{
		// 出错了
		int a = WSAGetLastError();
		// 释放
		closesocket(socketServer);
		WSACleanup();
		return 0;
	}

	int lisr = listen(socketServer, SOMAXCONN);
	if (SOCKET_ERROR == lisr)
	{
		// 出错了
		int a = WSAGetLastError();
		// 释放
		closesocket(socketServer);
		WSACleanup();
		return 0;
	}

	// for
	// 创建客户端链接
	struct sockaddr_in clientMsg;
	int len = sizeof(clientMsg);
	SOCKET socketClient = accept(socketServer, (struct sockaddr*)&clientMsg, &len);
	if (INVALID_SOCKET == socketClient)
	{
		// printf("客户端链接失败\n");
		// 出错了
		int a = WSAGetLastError();
		// 释放
		closesocket(socketServer);
		WSACleanup();
		return 0;
	}
	printf("客户端链接成功\n");


	/*
	* 服务器打印客户端链接成功
	* 向客户端发送  我是服务器，已与你成功创建链接
	* 客服端发送    谢谢
	*/

	// send
	int redr = send(socketClient, "我是服务器，已与你成功创建链接", 50, 0);
	if (SOCKET_ERROR == redr)
	{
		// 出错了
		int a = WSAGetLastError();
		// 根据实际情况处理
	}


	while (1)
	{
		// recv
		char buf[1500] = { 0 };
		int res = recv(socketClient, buf, 1499, 0);
		if (res == 0)
		{
			printf("连接中断，客户端下线\n");
		}
		else if (SOCKET_ERROR == res)
		{
			// 出错了
			int a = WSAGetLastError();
			// 根据实际情况处理
		}
		else
		{
			printf("%d  %s\n", res, buf);
		}

		scanf("%s", buf);
		// send
		redr = send(socketClient, buf, strlen(buf), 0);
		if (SOCKET_ERROR == redr)
		{
			// 出错了
			int a = WSAGetLastError();
			// 根据实际情况处理
		}
	}
	


	closesocket(socketServer);
	closesocket(socketClient);
	WSACleanup();
	
	system("pause");
	return 0;
}