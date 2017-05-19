#include "Socket.h"

#ifdef _WIN32
namespace dnc{
	namespace Net{
		namespace Sockets{

			Socket::Socket(){
				long rc = 0;
				WSADATA wsa;

				rc = WSAStartup(MAKEWORD(2, 0), &wsa);

				if(rc != 0){
					throw "Fehler: startWinsock, fehler code: " + rc;
				}

				sock = socket(AF_INET, SOCK_STREAM, 0);
				if(sock == INVALID_SOCKET){
					String strErr = "Fehler: Der Socket konnte nicht erstellt werden, fehler code: ";
					strErr += WSAGetLastError();
					throw strErr.getStringValue();
				}
			}


			Socket::~Socket(){}

			void Socket::Connect(String host, int port){
				long rc = 0;

				memset(&addr, 0, sizeof(SOCKADDR_IN)); // zuerst alles auf 0 setzten
				addr.sin_family = AF_INET;
				addr.sin_port = htons(port); // wir verwenden mal port 12345
				addr.sin_addr.s_addr = inet_addr(host.toCharArray()); // zielrechner ist unser eigener

				rc = connect(sock, (SOCKADDR*)&addr, sizeof(SOCKADDR));
				if(rc == SOCKET_ERROR){
					String strErr = "Fehler: Der Socket konnte nicht erstellt werden, fehler code: ";
					strErr += WSAGetLastError();
					throw strErr.getStringValue();
				}
			}

			void Socket::Disconnect(){
				closesocket(sock);
			}

			void Socket::Close(){
				WSACleanup();
			}

			int Socket::Send(char * data){
				int bytesSend = 0;
				size_t len = 0;

				len = strlen(data);

				bytesSend = send(sock, data, len, 0);

				if(bytesSend == 0){
					throw "Not send.";
				}
				if(bytesSend != len){
					throw "Not all bytes sent.";
				}


				return bytesSend;
			}

			int Socket::Receive(char * data){
				int bytesReceived = 0;
				size_t len = 0;

				len = strlen(data);

				bytesReceived = recv(sock, data, len, 0);

				if(bytesReceived == 0){
					throw "Server disconnected";
				}

				return bytesReceived;
			}

		}
	}
}
#endif // _WIN