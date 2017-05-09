#include "String.h"

#pragma once
namespace dnc{
	namespace Data{
		namespace SqlClient{



			class SqlDataReader: public Object{

				friend class SqlCommand;

			public:
				SqlDataReader();
				~SqlDataReader();
			};
		}
	}
}