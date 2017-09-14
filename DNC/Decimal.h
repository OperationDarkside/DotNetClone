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

		std::string ToString() override;
		std::string GetTypeString() override;

		Decimal operator=(long double ld);
		operator long double();
	private:
		long double value = 0;
	};
}
#endif // !DECIMAL_H