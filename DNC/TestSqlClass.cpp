#include "TestSqlClass.h"

namespace dnc {

	TestSqlClass::TestSqlClass() {
		Object& f1_id = this->id;
		Object& f2_name = this->bla_name;
		Object& f3_uatsaid = this->uatsaid;

		this->name = "TestDataClass";
		this->attributes.Add(SerializableAttribute(String("ID"), f1_id));
		this->attributes.Add(SerializableAttribute(String("Name"), f2_name));
		this->attributes.Add(SerializableAttribute(String("Uatsaid"), f3_uatsaid));
	}


	TestSqlClass::~TestSqlClass() {}

}