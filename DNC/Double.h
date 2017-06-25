#pragma once

#ifndef DOUBLE_H
#define DOUBLE_H

#include "String.h"

namespace dnc{

	/**
	Object related wrapper for the double type
	*/
	class Double: public Object{

		friend class Serializable;

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

		void FromString(std::string val) override;
	};
}
#endif // !DOUBLE_H