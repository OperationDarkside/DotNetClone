#include "NetworkStream.h"

namespace dnc{
	namespace Net{
		namespace Sockets{

			NetworkStream::NetworkStream(Socket socket):sock(socket){

			}

			NetworkStream::~NetworkStream(){}

			std::string NetworkStream::ToString(){
				return std::string("System.Net.Sockets.NetworkStream");
			}
			std::string NetworkStream::GetTypeString(){
				return std::string("NetworkStream");
			}

			void NetworkStream::Close(){
				this->sock.Close();
			}

			bool NetworkStream::DataAvailable(){
				return this->sock.Available() > 0;
			}
			Socket NetworkStream::GetSocket(){
				return this->sock;
			}
			unsigned char NetworkStream::ReadByte(){
				char bt;
				short res;

				res = this->sock.Receive(&bt, 1, SocketFlags::None);

				return bt;
			}
			void NetworkStream::WriteByte(unsigned char value){
				char val = (char)value;

				this->sock.Send(&val);
			}
		}
	}
}