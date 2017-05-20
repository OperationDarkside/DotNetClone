#pragma once
#include "EndPoint.h"
#include "IPAddress.h"

namespace dnc{
	namespace Net{

		class IPEndPoint: public EndPoint{
		public:
			IPEndPoint(long address, int port);
			IPEndPoint(IPAddress address, int port);
			~IPEndPoint();

			std::string ToString();
			std::string getTypeString();

			int Port();
			void Port(int p);

			IPAddress Address();
			void Address(IPAddress adr);
		private:
			int port;
			IPAddress addr;
		};
	}
}