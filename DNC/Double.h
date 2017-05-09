#include "String.h"

#pragma once

namespace dnc{

	/**
	Object related wrapper for the double type
	*/
	class Double: public Object{
	public:
		Double();
		Double(double d);
		~Double();

		std::string toString();
		std::string getTypeString();

		Double operator=(double d);
		operator double();
	private:
		double value;
	};
}
