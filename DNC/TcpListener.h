#pragma once

#ifndef TCPLISTENER_H
#define TCPLISTENER_H

#include "Socket.h"
#include "TcpClient.h"

namespace dnc{
	namespace Net{
		namespace Sockets{

			class TcpListener: public Object{
			public:
				TcpListener(IPAddress address, int port);
				TcpListener(IPEndPoint endPoint);
				~TcpListener();

				std::string ToString() override;
				std::string GetTypeString() override;

				bool Active();
				Socket AcceptSocket();
				TcpClient AcceptTcpClient();
				static TcpListener Create(int port);
				IPEndPoint LocalEndPoint();
				bool Pending();
				Socket Server();
				void Start();
				void Start(int backlog);
				void Stop();

			private:
				bool active;
				IPEndPoint ep;
				Socket sock;
			};

		}
	}
}
#endif // !TCPLISTENER_H