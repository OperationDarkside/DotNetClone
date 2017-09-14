#include "Socket.h"

#ifdef _WIN32
namespace dnc{
	namespace Net{
		namespace Sockets{

			Socket::Socket(){}

			Socket::Socket(AddressFamily af, SocketType st, ProtocolType pt): addressFamily(af), sockType(st), protocolType(pt){
				long rc = 0;
				WSADATA wsa;

				rc = WSAStartup(MAKEWORD(2, 0), &wsa);

				if(rc != 0){
					throw "Fehler: startWinsock, fehler code: " + rc;
				}

				sock = socket(af, st, pt);
				if(sock == INVALID_SOCKET){
					String strErr = "Socket could not be created. Error code: ";
					strErr += WSAGetLastError();
					throw strErr.GetStringValue();
				}
			}


			Socket::~Socket(){}

			std::string Socket::ToString(){
				return std::string("System.Net.Sockets.Socket");
			}

			std::string Socket::GetTypeString(){
				return std::string("Socket");
			}


			Socket Socket::Accept(){
				long rc = 0;
				int addrLen = 0;
				SOCKET acceptSocket;
				SOCKADDR_IN addrSock;

				addrLen = sizeof(addrSock);

				acceptSocket = accept(this->sock, (SOCKADDR*)&addrSock, &addrLen);

				Socket resSocket;

				resSocket.sock = acceptSocket;
				resSocket.addr = addrSock;
				resSocket.addressFamily = this->addressFamily;
				resSocket.sockType = this->sockType;
				resSocket.protocolType = this->protocolType;

				return resSocket;
			}

			int Socket::Available(){
				long rc = 0;
				unsigned long recvable;

				rc = ioctlsocket(this->sock, FIONREAD, &recvable);

				return recvable;
			}

			void Socket::Bind(IPEndPoint ep){
				long rc = 0;
				long lAddr = 0;
				std::vector<unsigned char> tmp;

				tmp = ep.Address().GetAddressBytes();

				lAddr = (tmp[3] << 24) | (tmp[2] << 16) | (tmp[1] << 8) | tmp[0];

				memset(&this->addr, 0, sizeof(SOCKADDR_IN));
				this->addr.sin_family = this->addressFamily;
				this->addr.sin_port = htons(ep.Port());
				this->addr.sin_addr.s_addr = /*inet_addr("127.0.0.1")*/ lAddr;

				rc = bind(this->sock, (SOCKADDR*)&this->addr, sizeof(SOCKADDR_IN));
				if(rc == SOCKET_ERROR){
					String strErr = "Socket could not be bound. Error code: ";
					strErr += WSAGetLastError();
					throw strErr.GetStringValue();
				}
			}

			void Socket::Connect(IPEndPoint ep){
				long rc = 0;
				long lAddr = 0;
				std::vector<unsigned char> tmp;

				tmp = ep.Address().GetAddressBytes();

				lAddr = (tmp[3] << 24) | (tmp[2] << 16) | (tmp[1] << 8) | tmp[0];

				memset(&this->addr, 0, sizeof(SOCKADDR_IN)); // zuerst alles auf 0 setzten
				this->addr.sin_family = this->addressFamily;
				this->addr.sin_port = htons(ep.Port()); // wir verwenden mal port 12345
				this->addr.sin_addr.s_addr = lAddr; // zielrechner ist unser eigener

				rc = connect(sock, (SOCKADDR*)&addr, sizeof(SOCKADDR));
				if(rc == SOCKET_ERROR){
					String strErr = "Could not connect. Error code: ";
					strErr += WSAGetLastError();
					throw strErr.GetStringValue();
				}
			}

			void Socket::Connect(IPAddress address, int port){
				long rc = 0;
				long lAddr = 0;
				std::vector<unsigned char> tmp;

				tmp = address.GetAddressBytes();

				lAddr = (tmp[3] << 24) | (tmp[2] << 16) | (tmp[1] << 8) | tmp[0];

				memset(&this->addr, 0, sizeof(SOCKADDR_IN));
				this->addr.sin_family = this->addressFamily;
				this->addr.sin_port = htons(port);
				this->addr.sin_addr.s_addr = lAddr;

				rc = connect(sock, (SOCKADDR*)&addr, sizeof(SOCKADDR));
				if(rc == SOCKET_ERROR){
					String strErr = "Could not connect. Error code: ";
					strErr += WSAGetLastError();
					throw strErr.GetStringValue();
				}
			}

			void Socket::Connect(String host, int port){
				long rc = 0;

				memset(&this->addr, 0, sizeof(SOCKADDR_IN)); // zuerst alles auf 0 setzten
				this->addr.sin_family = this->addressFamily;
				this->addr.sin_port = htons(port); // wir verwenden mal port 12345
				this->addr.sin_addr.s_addr = inet_addr(host.ToCharArray()); // zielrechner ist unser eigener

				rc = connect(sock, (SOCKADDR*)&addr, sizeof(SOCKADDR));
				if(rc == SOCKET_ERROR){
					String strErr = "Could not connect. Error code: ";
					strErr += WSAGetLastError();
					throw strErr.GetStringValue();
				}
			}

			void Socket::Disconnect(){
				closesocket(sock);
			}

			void Socket::Close(){
				WSACleanup();
			}

			LingerOption Socket::LingerState(){
				int res;
				int len = sizeof(LINGER);
				LINGER ling;

				res = getsockopt(this->sock, SOL_SOCKET, SO_LINGER, (char*)&ling, &len);
				if(res < 0){
					throw "Couldn't get LingerOption";
				}

				return LingerOption(ling.l_onoff,ling.l_linger);
			}

			void Socket::LingerState(LingerOption option){
				int res;
				int len = sizeof(LINGER);
				LINGER ling;

				memset(&ling, 0, len);
				ling.l_onoff = option.Enabled();
				ling.l_linger = option.LingerTime();

				res = setsockopt(this->sock, SOL_SOCKET, SO_LINGER, (char*)&ling, len);
				if(res < 0){
					throw "Couldn't set NoDelay";
				}
			}

			void Socket::Listen(int backlog){
				long rc = 0;

				rc = listen(this->sock, backlog);
				if(rc == SOCKET_ERROR){
					String strErr = "Fehler: Der Socket konnte nicht erstellt werden, fehler code: ";
					strErr += WSAGetLastError();
					throw strErr.GetStringValue();
				}
			}

			bool Socket::NoDelay(){
				bool nodel;
				int flag;
				int res;
				int len = sizeof(int);

				res = getsockopt(this->sock, IPPROTO_TCP, TCP_NODELAY, (char*)&flag, &len);
				if(res < 0){
					throw "Couldn't get NoDelay value";
				}

				return flag;
			}

			void Socket::NoDelay(bool noDelay){
				int res;
				int len = sizeof(int);

				res = setsockopt(this->sock, IPPROTO_TCP, TCP_NODELAY, (char*)noDelay, len);
				if(res < 0){
					throw "Couldn't set NoDelay";
				}
			}

			int Socket::Send(char * data){
				int bytesSend = 0;
				size_t len = 0;

				len = strlen(data);

				bytesSend = send(this->sock, data, len, 0);

				if(bytesSend == 0){
					throw "Not send.";
				}
				if(bytesSend != len){
					throw "Not all bytes sent.";
				}


				return bytesSend;
			}

			int Socket::SendBufferSize(){
				int flag;
				int res;
				int len = sizeof(int);

				res = getsockopt(this->sock, SOL_SOCKET, SO_SNDBUF, (char*)&flag, &len);
				if(res < 0){
					throw "Couldn't get Send Buffer Size";
				}

				return flag;
			}

			void Socket::SendBufferSize(int size){
				int res;
				int len = sizeof(int);

				res = setsockopt(this->sock, SOL_SOCKET, SO_SNDBUF, (char*)size, len);
				if(res < 0){
					throw "Couldn't set Send Buffer Size";
				}
			}

			int Socket::SendTimeout(){
				int flag;
				int res;
				int len = sizeof(int);

				res = getsockopt(this->sock, SOL_SOCKET, SO_SNDTIMEO, (char*)&flag, &len);
				if(res < 0){
					throw "Couldn't get Send Timeout";
				}

				return flag;
			}

			void Socket::SendTimeout(int timeout){
				int res;
				int len = sizeof(int);

				res = setsockopt(this->sock, SOL_SOCKET, SO_SNDTIMEO, (char*)timeout, len);
				if(res < 0){
					throw "Couldn't set Send Timeout";
				}
			}

			int Socket::Receive(char * buffer, int size, SocketFlags socketFlags){
				int bytesReceived = 0;

				bytesReceived = recv(this->sock, buffer, size, socketFlags);

				if(bytesReceived == 0){
					throw "Server disconnected";
				}

				return bytesReceived;
			}

			int Socket::ReceiveBufferSize(){
				int flag;
				int res;
				int len = sizeof(int);

				res = getsockopt(this->sock, SOL_SOCKET, SO_RCVBUF, (char*)&flag, &len);
				if(res < 0){
					throw "Couldn't get Receive Buffer Size";
				}

				return flag;
			}

			void Socket::ReceiveBufferSize(int size){
				int res;
				int len = sizeof(int);

				res = setsockopt(this->sock, SOL_SOCKET, SO_RCVBUF, (char*)size, len);
				if(res < 0){
					throw "Couldn't set Receive Buffer Size";
				}
			}

			int Socket::ReceiveTimeout(){
				int flag;
				int res;
				int len = sizeof(int);

				res = getsockopt(this->sock, SOL_SOCKET, SO_RCVTIMEO, (char*)&flag, &len);
				if(res < 0){
					throw "Couldn't get Receive Timeout";
				}

				return flag;
			}

			void Socket::ReceiveTimeout(int timeout){
				int res;
				int len = sizeof(int);

				res = setsockopt(this->sock, SOL_SOCKET, SO_RCVTIMEO, (char*)timeout, len);
				if(res < 0){
					throw "Couldn't set Receive Timeout";
				}
			}

		}
	}
}
#endif // _WIN