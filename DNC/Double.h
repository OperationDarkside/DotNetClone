#pragma once

#ifndef DOUBLE_H
#define DOUBLE_H

#include "String.h"

namespace dnc{

	/**
	Object related wrapper for the double type
	*/
	class Double: public Object{
	public:
		Double();
		Double(double d);
		~Double();

		std::string ToString() override;
		std::string GetTypeString() override;

		Double operator=(double d);
		operator double();
	private:
		double value;
	};
}
#endif // !DOUBLE_H