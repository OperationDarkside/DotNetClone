#pragma once

#ifndef SOCKET_H
#define SOCKET_H
#ifdef _WIN32
#include "String.h"
#include <stdio.h>
#include <winsock2.h>
#include <windows.h>



namespace dnc{
	namespace Net{
		namespace Sockets{
			
			class Socket: public Object {
			public:
				Socket();
				~Socket();

				void Connect(String host, int port);
				void Disconnect();
				void Close();
				int Send(char* data);
				int Receive(char* data);
			private:
				SOCKET sock;
				SOCKADDR_IN addr;
			};
			
		}
	}
}
#endif // _WIN
#endif // !SOCKET_H