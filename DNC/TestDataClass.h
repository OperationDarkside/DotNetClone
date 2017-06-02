#pragma once
#include "Serializable.h"
#include "String.h"
#include "Integer.h"
#include "Double.h"

namespace dnc{

	class TestDataClass: public Serializable<TestDataClass>{
	public:
		TestDataClass();
		~TestDataClass();

		int GetField1();
		void SetField1(int val);

		double GetField2();
		void SetField2(double val);

		String& GetField3();
		void SetField3(String val);

		TestDataClass* GetField4();
		void SetField4(TestDataClass* val);

	private:
		Integer field1;
		Double field2;
		String field3;
		TestDataClass* field4;
	};

}