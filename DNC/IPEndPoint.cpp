#include "IPEndPoint.h"

namespace dnc{
	namespace Net{

		IPEndPoint::IPEndPoint(long address, int port): port(port){
			std::vector<unsigned char> ad;

			ad.push_back((address & (0xff << 24)) >> 24);
			ad.push_back((address & (0xff << 16)) >> 16);
			ad.push_back((address & (0xff << 8)) >> 8);
			ad.push_back(address & 0xff);

			this->addr = IPAddress(ad);
		}

		IPEndPoint::IPEndPoint(IPAddress address, int port) :addr(address) ,port(port){
		
		}

		IPEndPoint::~IPEndPoint(){}

		std::string IPEndPoint::ToString(){
			return std::string("IPEndPoint");
		}
		std::string IPEndPoint::getTypeString(){
			return std::string("System.Net.IPEndPoint");
		}
		int IPEndPoint::Port(){
			return this->port;
		}
		void IPEndPoint::Port(int p){
			this->port = p;
		}
		IPAddress IPEndPoint::Address(){
			return this->addr;
		}
		void IPEndPoint::Address(IPAddress adr){
			this->addr = adr;
		}
	}
}