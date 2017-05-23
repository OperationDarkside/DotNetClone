#pragma once

#ifndef NETWORKSTREAM_H
#define NETWORKSTREAM_H

#include "String.h"

namespace dnc{
	namespace Net{
		namespace Sockets{

			class NetworkStream: public Object{
			public:
				NetworkStream();
				~NetworkStream();

				std::string ToString() override;
				std::string GetTypeString() override;
			};
		}
	}
}
#endif
