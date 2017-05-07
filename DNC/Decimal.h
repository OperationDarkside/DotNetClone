#pragma once
#include "String.h"

namespace dnc{

	/**
	Object related wrapper for the long double type
	*/
	class Decimal: public Object{
	public:
		Decimal();
		Decimal(long double ld);
		~Decimal();

		string toString();
		string getTypeString();

		Decimal operator=(long double ld);
		operator long double();
	private:
		long double value;
	};
}
