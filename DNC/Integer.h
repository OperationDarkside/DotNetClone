#include "String.h"

#pragma once

namespace dnc{

	/**
	Object related wrapper for the int type
	*/
	class Integer: public Object{
	public:
		Integer();
		Integer(int i);
		~Integer();

		string toString();
		string getTypeString();

		Integer operator=(int i);
		operator int();
	private:
		int value;
	};

}