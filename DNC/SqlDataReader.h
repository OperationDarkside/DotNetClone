#pragma once

#ifndef SQLDATAADAPTER_H
#define SQLDATAADAPTER_H

#include "String.h"

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
#endif // !SQLDATAADAPTER_H