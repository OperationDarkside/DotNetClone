#pragma once

#ifndef SOCKET_H
#define SOCKET_H
#ifdef _WIN32
#include "String.h"
#include "AddressFamily.h"
#include "SocketType.h"
#include "ProtocolType.h"
#include "IPEndPoint.h"
#include <stdio.h>
#include <winsock2.h>
#include <windows.h>



namespace dnc{
	namespace Net{
		namespace Sockets{
			
			class Socket: public Object {
			public:
				Socket(AddressFamily af, SocketType st, ProtocolType pt);
				~Socket();

				Socket Accept();
				void Bind(IPEndPoint ep);
				void Connect(String host, int port);
				void Disconnect();
				void Close();
				void Listen(int backlog);
				int Send(char* data);
				int Receive(char* data);
			private:
				Socket();
				AddressFamily addressFamily;
				SocketType sockType;
				ProtocolType protocolType;

				SOCKET sock;
				SOCKADDR_IN addr;
			};
			
		}
	}
}
#endif // _WIN
#endif // !SOCKET_H