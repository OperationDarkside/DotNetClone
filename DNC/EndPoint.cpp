#include "EndPoint.h"

namespace dnc{
	namespace Net{

		EndPoint::EndPoint(){}


		EndPoint::~EndPoint(){}

		std::string EndPoint::ToString(){
			return std::string("EndPoint");
		}

		std::string EndPoint::GetTypeString(){
			return std::string("System.Net.EndPoint");
		}

		dnc::Net::AddressFamily EndPoint::AddressFamily(){
			return this->af;
		}

		void dnc::Net::EndPoint::AddressFamily(dnc::Net::AddressFamily addressFamily){
			this->af = addressFamily;
		}
	}
}