#pragma once

#ifndef ULONG_H
#define ULONG_H

#include "String.h"

namespace dnc{

	class ULong: public Object{

		friend class Serializable;

	public:
		ULong();
		ULong(unsigned long ul);
		~ULong();

		std::string ToString() override;
		std::string GetTypeString() override;

		ULong operator=(unsigned long l);
		operator unsigned long();
	private:
		unsigned long value;

		void FromString(std::string val) override;
	};
}
#endif // !ULONG_H