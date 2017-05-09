#include "String.h"

#pragma once

namespace dnc{

	class Short: public Object{
	public:
		Short();
		Short(short s);
		~Short();

		std::string toString();
		std::string getTypeString();

		Short operator=(short s);
		operator short();

	private:
		short value;
	};
}
