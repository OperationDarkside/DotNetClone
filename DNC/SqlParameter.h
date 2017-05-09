#pragma once
#include "Object.h"

namespace dnc{
	namespace Data{
		namespace SqlClient{

			class SqlParameter: public Object{
			public:
				SqlParameter();
				~SqlParameter();
			};
		}
	}
}