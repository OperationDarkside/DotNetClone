#pragma once

#ifndef LONGLONG_H
#define LONGLONG_H

#include "String.h"

namespace dnc{

	class LongLong: public Object{
	public:
		LongLong();
		LongLong(long long ll);
		~LongLong();

		std::string ToString() override;
		std::string GetTypeString() override;

		LongLong operator=(long long ll);
		operator long long();
	private:
		long long value;
	};
}
#endif // !LONGLONG_H