#pragma once

#ifndef SOCKET_H
#define SOCKET_H
#ifdef _WIN32

#include <stdio.h>
#include <winsock2.h>
#include <windows.h>
#include "String.h"
#include "AddressFamily.h"
#include "SocketType.h"
#include "ProtocolType.h"
#include "IPEndPoint.h"
#include "SocketFlags.h"
#include <array>


namespace dnc{
	namespace Net{
		namespace Sockets{

			class Socket: public Object{
			public:
				Socket(AddressFamily af, SocketType st, ProtocolType pt);
				~Socket();

				std::string ToString() override;
				std::string GetTypeString() override;

				Socket Accept();
				void Bind(IPEndPoint ep);
				void Connect(String host, int port);
				void Disconnect();
				void Close();
				void Listen(int backlog);
				int Send(char* data);
				template<size_t Num>
				int Receive(std::array<char, Num>& data);
				int Receive(char* buffer, int size, SocketFlags socketFlags);
			private:
				Socket();
				AddressFamily addressFamily;
				SocketType sockType;
				ProtocolType protocolType;

				SOCKET sock;
				SOCKADDR_IN addr;
			};


			template<size_t Num>
			inline int Socket::Receive(std::array<char, Num>& data){
				int bytesReceived = 0;
				size_t len = 0;
				//std::array<char, Num> tmp;

				len = data.size();

				data.fill(0);

				bytesReceived = recv(sock, data.data(), len, 0);

				if(bytesReceived == 0){
					throw "Server disconnected";
				}

				//tmp.swap(data);
				//std::swap(tmp, data);

				return bytesReceived;
			}


		}
	}
}
#endif // _WIN
#endif // !SOCKET_H