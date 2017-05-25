#pragma once
#include "EndPoint.h"
#include "IPAddress.h"

namespace dnc{
	namespace Net{

		class IPEndPoint: public EndPoint{
		public:
			//IPEndPoint();
			IPEndPoint(long address, int port);
			IPEndPoint(IPAddress address, int port);
			~IPEndPoint();

			std::string ToString() override;
			std::string GetTypeString() override;

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