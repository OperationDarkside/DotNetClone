#pragma once

#ifndef LONG_H
#define LONG_H

#include "String.h"

namespace dnc{

	class Long: public Object{
	public:
		Long();
		Long(long l);
		~Long();

		std::string toString();
		std::string getTypeString();

		Long operator=(long l);
		operator long();
	private:
		long value;
	};
}
#endif // !LONG_H