#define _CRT_SECURE_NO_WARNINGS

#include<WinSock2.h>// windows socked �ڶ��汾
#pragma comment(lib, "Ws2_32.lib")
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//#include <WS2tcpip.h>
int main()
{
	// ���������
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
		
	SOCKET socketServer = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == socketServer)
	{
		int a = WSAGetLastError();
		// ���������
		WSACleanup();
		return 0;
	}

	// 2017���ϲ�֧��inet_addr
	/*struct sockaddr_in si;
	si.sin_family = AF_INET;
	si.sin_port = htons(12345);
	si.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");*/
	
	struct sockaddr_in si;
	si.sin_family = AF_INET;
	si.sin_port = htons(12345);
	struct in_addr s;//���Ipv4��ַ�Ľṹ��
	inet_pton(AF_INET, "127.0.0.1", (void*)&si.sin_addr.S_un.S_addr);//����ת��
	// �󶨵�ַ��˿�
	int bres = bind(socketServer, (const struct sockaddr*)&si, sizeof(si));
	if (SOCKET_ERROR == bres)
	{
		// ������
		int a = WSAGetLastError();
		// �ͷ�
		closesocket(socketServer);
		WSACleanup();
		return 0;
	}

	int lisr = listen(socketServer, SOMAXCONN);
	if (SOCKET_ERROR == lisr)
	{
		// ������
		int a = WSAGetLastError();
		// �ͷ�
		closesocket(socketServer);
		WSACleanup();
		return 0;
	}

	// for
	// �����ͻ�������
	struct sockaddr_in clientMsg;
	int len = sizeof(clientMsg);
	SOCKET socketClient = accept(socketServer, (struct sockaddr*)&clientMsg, &len);
	if (INVALID_SOCKET == socketClient)
	{
		// printf("�ͻ�������ʧ��\n");
		// ������
		int a = WSAGetLastError();
		// �ͷ�
		closesocket(socketServer);
		WSACleanup();
		return 0;
	}
	printf("�ͻ������ӳɹ�\n");


	/*
	* ��������ӡ�ͻ������ӳɹ�
	* ��ͻ��˷���  ���Ƿ�������������ɹ���������
	* �ͷ��˷���    лл
	*/

	// send
	int redr = send(socketClient, "���Ƿ�������������ɹ���������", 50, 0);
	if (SOCKET_ERROR == redr)
	{
		// ������
		int a = WSAGetLastError();
		// ����ʵ���������
	}


	while (1)
	{
		// recv
		char buf[1500] = { 0 };
		int res = recv(socketClient, buf, 1499, 0);
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
		redr = send(socketClient, buf, strlen(buf), 0);
		if (SOCKET_ERROR == redr)
		{
			// ������
			int a = WSAGetLastError();
			// ����ʵ���������
		}
	}
	


	closesocket(socketServer);
	closesocket(socketClient);
	WSACleanup();
	
	system("pause");
	return 0;
}