#pragma once

#ifndef ULONG_H
#define ULONG_H

#include "String.h"

namespace dnc{

	class ULong: public Object{
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
	};
}
#endif // !ULONG_H