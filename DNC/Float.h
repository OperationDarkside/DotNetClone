#pragma once

#ifndef FLOAT_H
#define FLOAT_H

#include "String.h"

namespace dnc{

	/**
	Object related wrapper for the float type
	*/
	class Float: public Object{

		friend class Serializable;

	public:
		Float();
		Float(float f);
		~Float();

		std::string ToString() override;
		std::string GetTypeString() override;

		Float operator=(float f);
		operator float();
	private:
		float value;

		void FromString(std::string val) override;
	};
}
#endif // !FLOAT_H