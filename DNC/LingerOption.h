#pragma once
#ifndef LINGEROPTION_H
#define LINGEROPTION_H

#include "String.h"
//#include "Socket.h"

namespace dnc{
	namespace Net{
		namespace Sockets{

			class LingerOption: public Object{
			public:
				LingerOption();
				LingerOption(bool enable, int sec);
				~LingerOption();

				std::string ToString() override;
				std::string GetTypeString() override;

				bool Enabled();
				void Enabled(bool value);
				int LingerTime();
				void LingerTime(int sec);

			private:
				bool enabled;
				int seconds;
			};
		}
	}
}
#endif