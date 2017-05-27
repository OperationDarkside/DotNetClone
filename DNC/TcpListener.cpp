#include "TcpListener.h"

namespace dnc{
	namespace Net{
		namespace Sockets{

			TcpListener::TcpListener(IPAddress address, int port): sock(AddressFamily::IPv4, SocketType::Stream, ProtocolType::Tcp), ep(address, port){
				this->sock.Bind(this->ep);
				this->sock.Listen(10);
				this->active = true;
			}

			TcpListener::TcpListener(IPEndPoint endPoint): sock(AddressFamily::IPv4, SocketType::Stream, ProtocolType::Tcp), ep(endPoint){
				this->sock.Bind(this->ep);
			}

			TcpListener::~TcpListener(){}

			std::string TcpListener::ToString(){
				return std::string("System.Net.Sockets.TcpListener");
			}

			std::string TcpListener::GetTypeString(){
				return std::string("TcpListener");
			}
			bool TcpListener::Active(){
				return this->active;
			}
			Socket TcpListener::AcceptSocket(){
				return this->sock.Accept();
			}
			TcpClient TcpListener::AcceptTcpClient(){
				TcpClient client;

				client.Client(this->sock);

				return client;
			}
			TcpListener TcpListener::Create(int port){
				return TcpListener(IPAddress::Any, port);
			}
			IPEndPoint TcpListener::LocalEndPoint(){
				return this->ep;
			}
			bool TcpListener::Pending(){
				throw "Not implemented yet";

				return false;
			}
			Socket TcpListener::Server(){
				return this->sock;
			}
			void TcpListener::Start(){
				if(!this->active){
					this->sock.Bind(this->ep);
					this->sock.Listen(10);

					this->active = true;
				}
			}
			void TcpListener::Start(int backlog){
				if(!this->active){
					this->sock.Bind(this->ep);
					this->sock.Listen(backlog);
					this->active = true;
				}
			}
			void TcpListener::Stop(){
				this->sock.Close();
				this->active = false;
			}
		}
	}
}