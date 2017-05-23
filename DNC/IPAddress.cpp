#include "IPAddress.h"

namespace dnc{
	namespace Net{
		IPAddress::IPAddress(){}
		IPAddress::IPAddress(std::vector<unsigned char> address){
			if(address.size() != 4){
				throw "IP Address length not 4!";
			}
			this->ipAddress = address;
		}

		IPAddress::IPAddress(std::vector<unsigned char> address, long scopeId){
			if(address.size() != 4){
				throw "IP Address length not 4!";
			}
			this->ipAddress = address;
			this->scope = scopeId;
		}

		IPAddress::IPAddress(long address){
			throw "Not implemented yet";
		}

		IPAddress::~IPAddress(){}

		const char* IPAddress::Any = new char[4]{0, 0, 0, 0};
		const char* IPAddress::Loopback = new char[4]{127, 0, 0, 1};

		std::string dnc::Net::IPAddress::ToString(){
			return std::string("IPAddress");
		}

		std::string dnc::Net::IPAddress::GetTypeString(){
			return std::string("System.Net.IPAddress");
		}
		std::vector<unsigned char> IPAddress::GetAddressBytes(){
			return this->ipAddress;
		}
		long IPAddress::ScopeId(){
			return this->scope;
		}
		void IPAddress::ScopeId(long scopeId){
			this->scope = scopeId;
		}
	}
}