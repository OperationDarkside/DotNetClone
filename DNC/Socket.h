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

#pragma comment(lib, "Ws2_32.lib")

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
				bool Blocking();
				void Blocking(bool value);
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
				template<size_t Num>
				int Receive(std::array<char, Num>& data, int offset, int size);
				int Receive(char* buffer, int size, SocketFlags socketFlags);
				int ReceiveBufferSize();
				void ReceiveBufferSize(int size);
				int ReceiveTimeout();
				void ReceiveTimeout(int timeout);
				int Send(const char* data);
				template<size_t Num>
				int Send(std::array<unsigned char, Num> data);
				template<size_t Num>
				int Send(std::array<unsigned char, Num> data, int offset, int size);
				int SendBufferSize();
				void SendBufferSize(int size);
				int SendTimeout();
				void SendTimeout(int timeout);
			private:
				Socket();
				bool blocking = true;
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

				bytesReceived = recv(this->sock, data.data(), len, 0);

				if(bytesReceived == 0){
					throw "Server disconnected";
				}

				//tmp.swap(data);
				//std::swap(tmp, data);

				return bytesReceived;
			}

			template<size_t Num>
			inline int Socket::Receive(std::array<char, Num>& data, int offset, int size){
				int bytesReceived = 0;
				std::array<char, size> tmp;

				if(Num < (size + offset)){
					throw "Array not long enough!";
				}

				tmp.fill(0);

				bytesReceived = recv(this->sock, tmp.data(), size, 0);

				if(bytesReceived == 0){
					throw "Server disconnected";
				}

				std::copy(tmp.begin(), tmp.end(), data.begin() + offset);

				return bytesReceived;
			}

			template<size_t Num>
			inline int Socket::Send(std::array<unsigned char, Num> data){				
				int bytesSend = 0;

				bytesSend = send(this->sock, data.data(), Num, 0);

				if(bytesSend == 0){
					throw "No bytes send.";
				}
				if(bytesSend != len){
					throw "Not all bytes sent.";
				}

				return bytesSend;
			}

			template<size_t Num>
			inline int Socket::Send(std::array<unsigned char, Num> data, int offset, int size){
				int bytesSend = 0;
				std::array<unsigned char, size> tmp;

				if( Num < (offset + size)){
					throw "Array not big enough.";
				}

				std::copy(data.begin() + offset, data.end() + offset + size, tmp.begin());

				bytesSend = send(this->sock, tmp.data(), size, 0);

				if(bytesSend == 0){
					throw "No bytes send.";
				}
				if(bytesSend != len){
					throw "Not all bytes sent.";
				}

				return bytesSend;
			}


		}
	}
}
#endif // _WIN
#endif // !SOCKET_H