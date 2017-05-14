#pragma once

#ifndef DECIMAL_H
#define DECIMAL_H

#include "Object.h"

namespace dnc{

	/**
	Object related wrapper for the long double type
	*/
	class Decimal: public Object{
	public:
		Decimal();
		Decimal(long double ld);
		~Decimal();

		std::string toString();
		std::string getTypeString();

		Decimal operator=(long double ld);
		operator long double();
	private:
		long double value;
	};
}
#endif // !DECIMAL_H