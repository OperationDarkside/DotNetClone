#include "String.h"

#pragma once

namespace dnc::Data::SqlClient{

	using namespace std;

	class SqlDataReader: public Object{

		friend class SqlCommand;

	public:
		SqlDataReader();
		~SqlDataReader();
	};
}
