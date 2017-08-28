#pragma once
#include "String.h"
#include "Long.h"
#include "DateTime.h"
#include "Serializable.h"

namespace dnc {
	class TestSqlClass : public Serializable {
	public:
		TestSqlClass();
		~TestSqlClass();

		Long id;
		DateTime uatsaid;
		String bla_name;
	};

}