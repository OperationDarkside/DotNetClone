#include "NetworkStream.h"

namespace dnc{
	namespace Net{
		namespace Sockets{

			NetworkStream::NetworkStream(){}

			NetworkStream::~NetworkStream(){}

			std::string NetworkStream::ToString(){
				return std::string("System.Net.Sockets.NetworkStream");
			}
			std::string NetworkStream::GetTypeString(){
				return std::string("NetworkStream");
			}
		}
	}
}