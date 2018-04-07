#pragma once

#include <string>
#include <vector>

#include "SerializationObject.h"

class SerializationTestClass {
public:

	std::string& getVar1 () {
		return var1;
	}

	int& getVar2 () {
		return var2;
	}

	double& getVar3 () {
		return var3;
	}

	std::vector<SerializationTestClass>& getVar4 () {
		return var4;
	}

	void setVar1 (const std::string _var1) {
		var1 = _var1;
	}

	void setVar2 (const int _var2) {
		var2 = _var2;
	}

	void setVar3 (const double _var3) {
		var3 = _var3;
	}

	void setVar4 (const std::vector<SerializationTestClass> _var4) {
		var4 = _var4;
	}

	void deserialize (SerializationObject& serObj) {
		var1 = serObj.get<std::string> ("var1");
		var2 = serObj.get<int> ("var2");
		var3 = serObj.get<double> ("var3");

		var4 = serObj.getArray<SerializationTestClass> ("var4");
	}

	SerializationObject serialize () {
		SerializationObject res;

		res.set ("var1", var1);
		res.set ("var2", var2);
		res.set ("var3", var3);
		res.set ("var4", var4);

		return res;
	}

private:
	std::string var1;
	int var2 = 0;
	double var3 = 0;

	std::vector<SerializationTestClass> var4;
};