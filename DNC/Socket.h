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
#include "LingerOption.h"
#include <array>


namespace dnc{
	namespace Net{
		namespace Sockets{

			class Socket: public Object{

				friend class TcpClient;

			public:
				Socket(AddressFamily af, SocketType st, ProtocolType pt);
				~Socket();

				std::string ToString() override;
				std::string GetTypeString() override;

				Socket Accept();
				int Available();
				void Bind(IPEndPoint ep);
				void Connect(IPEndPoint ep);
				void Connect(IPAddress address, int port);
				void Connect(String host, int port);
				void Disconnect();
				void Close();
				LingerOption LingerState();
				void LingerState(LingerOption option);
				void Listen(int backlog);
				bool NoDelay();
				void NoDelay(bool noDelay);
				template<size_t Num>
				int Receive(std::array<char, Num>& data);
				int Receive(char* buffer, int size, SocketFlags socketFlags);
				int ReceiveBufferSize();
				void ReceiveBufferSize(int size);
				int ReceiveTimeout();
				void ReceiveTimeout(int timeout);
				int Send(char* data);
				int SendBufferSize();
				void SendBufferSize(int size);
				int SendTimeout();
				void SendTimeout(int timeout);
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