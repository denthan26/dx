#define _CRT_SECURE_NO_WARNINGS

#include<WinSock2.h>// windows socked �ڶ��汾
#pragma comment(lib, "Ws2_32.lib")
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include <WS2tcpip.h>
int main()
{
	WORD wdVersion = MAKEWORD(2, 2);// ���ֽ� ���汾
	WSADATA wdSockMsg;
	int nRes = WSAStartup(wdVersion, &wdSockMsg);
	if (0 != nRes)
	{
		switch (nRes)
		{
		case WSASYSNOTREADY:
			printf("���ף������µ������ԣ����߼�������\n");
			break;
		case WSAVERNOTSUPPORTED:
			printf("����������\n");
			break;
		case WSAEINPROGRESS:
			printf("��������\n");
			break;
		case WSAEPROCLIM:
			printf("�볢�Թرղ���Ҫ���������Ϊ��ǰ�����ṩ������Դ\n");
			break;
		case WSAEFAULT:
			break;
		}

		return 0;
	}
	// У��汾
	if (2 != HIBYTE(wdSockMsg.wVersion) || 2 != LOBYTE(wdSockMsg.wVersion))
	{
		// ˵���汾����
		WSACleanup();// �ر�/���������
		return 0;
	}

	SOCKET socketServer = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);// �ͻ��˴�����������socket
	if (INVALID_SOCKET == socketServer)
	{
		int a = WSAGetLastError();
		// ���������
		WSACleanup();
		return 0;
	}


	// ���ӷ�����
	struct sockaddr_in serverMsg;
	serverMsg.sin_family = AF_INET;
	serverMsg.sin_port = htons(12345);
	struct in_addr s;//���Ipv4��ַ�Ľṹ��
	inet_pton(AF_INET, "127.0.0.1", (void*)&serverMsg.sin_addr.S_un.S_addr);//����ת��

	// 2017���ϲ�֧��inet_addr
	/*struct sockaddr_in si;
	si.sin_family = AF_INET;
	si.sin_port = htons(12345);
	si.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");*/

	int conr = connect(socketServer, (struct sockaddr*)&serverMsg, sizeof(serverMsg));
	if (SOCKET_ERROR == conr)
	{
		int a = WSAGetLastError();
		closesocket(socketServer);

		WSACleanup();

		// system("pause");
		return 0;

	}

	while (1)
	{
		// recv
		char buf[1500] = { 0 };
		int res = recv(socketServer, buf, 1499, 0);
		if (res == 0)
		{
			printf("�����жϣ��ͻ�������\n");
		}
		else if (SOCKET_ERROR == res)
		{
			// ������
			int a = WSAGetLastError();
			// ����ʵ���������
		}
		else
		{
			printf("%d  %s\n", res, buf);
		}

		scanf("%s", buf);
		// send
		int redr = send(socketServer, buf, strlen(buf), 0);
		if (SOCKET_ERROR == redr)
		{
			// ������
			int a = WSAGetLastError();
			// ����ʵ���������
		}
	}

	



	closesocket(socketServer);

	WSACleanup();

	system("pause");
	return 0;


}