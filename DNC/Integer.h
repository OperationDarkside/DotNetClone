#pragma once

#ifndef INTEGER_H
#define INTEGER_H

#include "String.h"

namespace dnc{

	/**
	Object related wrapper for the int type
	*/
	class Integer: public Object{

		friend class Serializable;

	public:
		Integer();
		Integer(int i);
		Integer(Object& o);
		~Integer();

		std::string ToString() override;
		std::string GetTypeString() override;

		Integer operator=(int i);
		operator int();
	private:
		int value = 0;

		void FromString(std::string val) override;
	};

}
#endif // !INTEGER_H