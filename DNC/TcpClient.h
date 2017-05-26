#pragma once

#ifndef TCPCLIENT_H
#define TCPCLIENT_H

#include "String.h"
#include "Socket.h"
#include "LingerOption.h"
#include "NetworkStream.h"

namespace dnc{
	namespace Net{
		namespace Sockets{

			class TcpClient: public Object{
			public:
				TcpClient();
				TcpClient(AddressFamily family);
				TcpClient(IPEndPoint localEP);
				TcpClient(String hostname, int port);
				~TcpClient();

				std::string ToString() override;
				std::string GetTypeString() override;

				int Available();
				Socket Client();
				void Client(Socket socket);
				void Close();
				void Connect(IPEndPoint remoteEP);
				void Connect(IPAddress address, int port);
				void Connect(String hostname, int port);
				bool Connected();
				NetworkStream GetStream();
				LingerOption LingerState();
				void LingerState(LingerOption option);
				bool NoDelay();
				void NoDelay(bool noDelay);
				int ReceiveBufferSize();
				void ReceiveBufferSize(int size);
				int ReceiveTimeout();
				void ReceiveTimeout(int timeout);
				int SendBufferSize();
				void SendBufferSize(int size);
				int SendTimeout();
				void SendTimeout(int timeout);

			private:
				bool discon = true;
				//bool noDel;
				//int recvBufSize;
				//int recvTimeout;
				//int sendBufSize;
				//int sendTimeout;
				//LingerOption lo;
				Socket sock;
				//IPEndPoint endPoint;
			};

		}
	}
}
#endif // !TCPCLIENT_H