#include "TestDataClass.h"

namespace dnc{

	TestDataClass::TestDataClass(){

		Object& f1 = this->field1;
		Object& f2 = this->field2;
		Object& f3 = this->field3;

		this->name = "TestDataClass";
		this->attributes.Add(SerializableAttribute(String("Field1"), f1));
		this->attributes.Add(SerializableAttribute(String("Field2"), f2));
		this->attributes.Add(SerializableAttribute(String("Field3"), f3));
	}


	TestDataClass::~TestDataClass(){}

	int TestDataClass::GetField1(){
		return this->field1;
	}

	void TestDataClass::SetField1(int val){
		this->field1 = val;
	}

	double TestDataClass::GetField2(){
		return this->field2;
	}

	void TestDataClass::SetField2(double val){
		this->field2 = val;
	}

	String TestDataClass::GetField3(){
		return this->field3;
	}

	void TestDataClass::SetField3(String val){
		this->field3 = val;
	}

}