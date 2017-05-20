#pragma once
#include "Object.h"
#include <vector>

namespace dnc{
	namespace Net{

		class IPAddress: public Object{
		public:
			IPAddress();
			IPAddress(std::vector<unsigned char> address);
			IPAddress(std::vector<unsigned char> address, long scopeId);
			IPAddress(long address);
			~IPAddress();

			static const char* Any;
			static const char* Loopback;

			std::string ToString();
			std::string getTypeString();

			std::vector<unsigned char> GetAddressBytes();
			long ScopeId();
			void ScopeId(long scopeId);

		private:
			std::vector<unsigned char> ipAddress;
			long scope;
		};

	}
}