#pragma once

#ifndef SQLPARAMETER_H
#define SQLPARAMETER_H

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
#endif // !SQLPARAMETER_H