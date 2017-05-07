#include "String.h"

#pragma once

namespace dnc{

	/**
	Object related wrapper for the float type
	*/
	class Float: public Object{
	public:
		Float();
		Float(float f);
		~Float();

		string toString();
		string getTypeString();

		Float operator=(float f);
		operator float();
	private:
		float value;
	};
}