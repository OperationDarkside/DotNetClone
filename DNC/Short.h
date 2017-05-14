#pragma once

#ifndef SHORT_H
#define SHORT_H

#include "String.h"

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
#endif // !SHORT_H