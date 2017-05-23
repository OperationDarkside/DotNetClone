#include "TcpClient.h"


namespace dnc{
	namespace Net{
		namespace Sockets{

			TcpClient::TcpClient(){}


			TcpClient::~TcpClient(){}

			std::string TcpClient::ToString(){
				return std::string();
			}

			std::string TcpClient::GetTypeString(){
				return std::string();
			}

			int TcpClient::Available(){
				return 0;
			}

			Socket TcpClient::Client(){
				return Socket();
			}

			void TcpClient::Client(Socket socket){}

			void TcpClient::Close(){}

			void TcpClient::Connect(IPEndPoint remoteEP){}

			void TcpClient::Connect(IPAddress address, int port){}

			void TcpClient::Connect(String hostname, int port){}

			bool TcpClient::Connected(){
				return false;
			}

			NetworkStream TcpClient::GetStream(){
				return NetworkStream();
			}

			LingerOption TcpClient::LingerState(){
				return LingerOption();
			}

			void TcpClient::LingerState(LingerOption option){}

			bool TcpClient::NoDelay(){
				return false;
			}

			void TcpClient::NoDelay(bool noDelay){}

			int TcpClient::ReceiveBufferSize(){
				return 0;
			}

			void TcpClient::ReceiveBufferSize(int size){}

			int TcpClient::ReceiveTimeout(){
				return 0;
			}

			void TcpClient::ReceiveTimeout(int timeout){}

			int TcpClient::SendBufferSize(){
				return 0;
			}

			void TcpClient::SendBufferSize(int size){}

			int TcpClient::SendTimeout(){
				return 0;
			}

			void TcpClient::SendTimeout(int timeout){}

		}
	}
}