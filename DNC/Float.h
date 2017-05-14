#pragma once

#ifndef FLOAT_H
#define FLOAT_H

#include "String.h"

namespace dnc{

	/**
	Object related wrapper for the float type
	*/
	class Float: public Object{
	public:
		Float();
		Float(float f);
		~Float();

		std::string toString();
		std::string getTypeString();

		Float operator=(float f);
		operator float();
	private:
		float value;
	};
}
#endif // !FLOAT_H