#pragma once

#ifndef LONG_H
#define LONG_H

#include "String.h"

namespace dnc{

	class Long: public Object{

		friend class Serializable;

	public:
		Long();
		Long(long l);
		~Long();

		std::string ToString() override;
		std::string GetTypeString() override;

		Long& operator=(long l);
		operator long();
	private:
		long value = 0;

		void FromString(std::string val) override;
	};
}
#endif // !LONG_H