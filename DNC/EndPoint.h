#pragma once
#include "Object.h"
#include "AddressFamily.h"

namespace dnc{
	namespace Net{
		class EndPoint: public Object{

			friend class IPEndPoint;
		public:
			EndPoint();

			std::string ToString();
			std::string getTypeString();

			virtual dnc::Net::AddressFamily AddressFamily();
			virtual void AddressFamily(dnc::Net::AddressFamily addressFamily);

		private:
			~EndPoint();
			dnc::Net::AddressFamily af;
		};
	}
}