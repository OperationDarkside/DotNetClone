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

			void Socket::Connect(String host, int port){
				long rc = 0;

				memset(&this->addr, 0, sizeof(SOCKADDR_IN)); // zuerst alles auf 0 setzten
				this->addr.sin_family = this->addressFamily;
				this->addr.sin_port = htons(port); // wir verwenden mal port 12345
				this->addr.sin_addr.s_addr = inet_addr(host.toCharArray()); // zielrechner ist unser eigener

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

			void Socket::Listen(int backlog){
				long rc = 0;

				rc = listen(this->sock, backlog);
				if(rc == SOCKET_ERROR){
					String strErr = "Fehler: Der Socket konnte nicht erstellt werden, fehler code: ";
					strErr += WSAGetLastError();
					throw strErr.GetStringValue();
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

			int Socket::Receive(char * buffer, int size, SocketFlags socketFlags){
				int bytesReceived = 0;

				bytesReceived = recv(this->sock, buffer, size, socketFlags);

				if(bytesReceived == 0){
					throw "Server disconnected";
				}

				return bytesReceived;
			}

		}
	}
}
#endif // _WIN