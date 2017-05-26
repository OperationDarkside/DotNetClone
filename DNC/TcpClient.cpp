#include "TcpClient.h"


namespace dnc{
	namespace Net{
		namespace Sockets{

			TcpClient::TcpClient(){
				this->sock = Socket(AddressFamily::IPv4, SocketType::Stream, ProtocolType::Tcp);
			}

			TcpClient::TcpClient(AddressFamily family){
				this->sock = Socket(family, SocketType::Stream, ProtocolType::Tcp);
			}

			TcpClient::TcpClient(IPEndPoint localEP){
				//endPoint = localEP;
				this->sock = Socket(AddressFamily::IPv4, SocketType::Stream, ProtocolType::Tcp);
				this->sock.Bind(localEP);
			}

			TcpClient::TcpClient(String hostname, int port){
				this->sock = Socket(AddressFamily::IPv4, SocketType::Stream, ProtocolType::Tcp);
				this->sock.Connect(hostname, port);
				this->discon = false;
			}


			TcpClient::~TcpClient(){}

			std::string TcpClient::ToString(){
				return std::string("System.Net.Sockets.TcpClient");
			}

			std::string TcpClient::GetTypeString(){
				return std::string("TcpClient");
			}

			int TcpClient::Available(){
				return this->sock.Available();
			}

			Socket TcpClient::Client(){
				return this->sock;
			}

			void TcpClient::Client(Socket socket){
				this->sock = socket;
			}

			void TcpClient::Close(){
				this->sock.Close();
				this->discon = true;
			}

			void TcpClient::Connect(IPEndPoint remoteEP){
				this->sock.Connect(remoteEP);
				this->discon = false;
			}

			void TcpClient::Connect(IPAddress address, int port){
				this->sock.Connect(address, port);
				this->discon = false;
			}

			void TcpClient::Connect(String hostname, int port){
				this->sock.Connect(hostname, port);
				this->discon = false;
			}

			bool TcpClient::Connected(){
				return !this->discon;
			}

			NetworkStream TcpClient::GetStream(){
				return NetworkStream(this->sock);
			}

			LingerOption TcpClient::LingerState(){
				return this->sock.LingerState();
			}

			void TcpClient::LingerState(LingerOption option){
				this->sock.LingerState(option);
			}

			bool TcpClient::NoDelay(){
				return this->sock.NoDelay();
			}

			void TcpClient::NoDelay(bool noDelay){
				this->sock.NoDelay(noDelay);
			}

			int TcpClient::ReceiveBufferSize(){
				return this->sock.ReceiveBufferSize();
			}

			void TcpClient::ReceiveBufferSize(int size){
				this->sock.ReceiveBufferSize(size);
			}

			int TcpClient::ReceiveTimeout(){
				return this->sock.ReceiveTimeout();
			}

			void TcpClient::ReceiveTimeout(int timeout){
				this->sock.ReceiveTimeout(timeout);
			}

			int TcpClient::SendBufferSize(){
				return this->sock.SendBufferSize();
			}

			void TcpClient::SendBufferSize(int size){
				this->sock.SendBufferSize(size);
			}

			int TcpClient::SendTimeout(){
				return this->sock.SendTimeout();
			}

			void TcpClient::SendTimeout(int timeout){
				this->sock.SendTimeout(timeout);
			}

		}
	}
}