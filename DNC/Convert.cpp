#include "Convert.h"

namespace dnc{

	Convert::Convert(){}


	Convert::~Convert(){}

	bool Convert::toBoolean(bool value){
		return value;
	}

	bool Convert::toBoolean(char value){
		return value == 0 ? false : true;
	}

	bool Convert::toBoolean(double value){
		return value == 0 ? false : true;
	}

	bool Convert::toBoolean(float value){
		return value == 0 ? false : true;
	}

	bool Convert::toBoolean(short value){
		return value == 0 ? false : true;
	}

	bool Convert::toBoolean(int value){
		return value == 0 ? false : true;
	}

	bool Convert::toBoolean(long value){
		return value == 0 ? false : true;
	}

	bool Convert::toBoolean(unsigned short value){
		return value == 0 ? false : true;
	}

	bool Convert::toBoolean(unsigned int value){
		return value == 0 ? false : true;
	}

	bool Convert::toBoolean(unsigned long value){
		return value == 0 ? false : true;
	}

	bool Convert::toBoolean(Object* value){
		if(value == nullptr){
			return false;
		}

		return true;
	}

	bool Convert::toBoolean(String & value){
		String* tmp = &value.toLower();
		if(*tmp == "true"){
			return true;
		} else if(*tmp == "false"){
			return false;
		} else{
			std::cerr << "wrong format" << std::endl;
		}

		return false;
	}

	DateTime Convert::toDateTime(String & value){
		unsigned short year = 0;
		unsigned short month = 0;
		unsigned short day = 0;
		unsigned short hour = 0;
		unsigned short min = 0;
		unsigned short sec = 0;
		unsigned short ms = 0;
		std::vector<String*> dates;
		std::vector<String*> times;
		std::vector<String*> tmp;
		DateTime* dt;

		try{
			tmp = value.split('T');
			dates = tmp[0]->split('-');
			times = tmp[1]->split(':');

			if(dates.size() == 3 && times.size() == 4){
				year = std::stoi(dates[0]->getStringValue().c_str());
				month = std::stoi(dates[1]->getStringValue().c_str());
				day = std::stoi(dates[2]->getStringValue().c_str());
				hour = std::stoi(times[0]->getStringValue().c_str());
				min = std::stoi(times[1]->getStringValue().c_str());
				sec = std::stoi(times[2]->getStringValue().c_str());
				ms = std::stoi(times[3]->getStringValue().c_str());

				dt = new DateTime(year, month, day, hour, min, sec, ms);

				return *dt;
			} else{
				std::cerr << "Wrong format";
			}
		} catch(std::exception ex){
			std::cerr << ex.what();
		}

		return NULL;
	}

	double Convert::toDouble(String & value){
		double res = 0;

		res = std::stod(value.getStringValue().c_str());

		return res;
	}

	float Convert::toFloat(String & value){
		float res = 0;

		res = std::stof(value.getStringValue().c_str());

		return res;
	}

	int Convert::toInt(String & value){
		int res = 0;

		res = std::stoi(value.getStringValue().c_str());

		return res;
	}

	long Convert::toLong(String & value){
		long res = 0;

		res = std::stol(value.getStringValue().c_str());

		return res;
	}

	String Convert::toString(bool value){
		String* res;

		res = new String(value ? "true" : "false");

		return res;
	}

	String Convert::toString(char value){
		return new String(&value);
	}

	String Convert::toString(double value){
		return new String(&std::to_string(value));
	}

	String Convert::toString(float value){
		return new String(&std::to_string(value));
	}

	String Convert::toString(short value){
		return new String(&std::to_string(value));
	}

	String Convert::toString(int value){
		return new String(&std::to_string(value));
	}

	String Convert::toString(long value){
		return new String(&std::to_string(value));
	}

	String Convert::toString(long long value){
		return new String(&std::to_string(value));
	}

	String Convert::toString(unsigned short value){
		return new String(&std::to_string(value));
	}

	String Convert::toString(unsigned int value){
		return new String(&std::to_string(value));
	}

	String Convert::toString(unsigned long value){
		return new String(&std::to_string(value));
	}

	String Convert::toString(Object * value){
		return new String(&value->toString());
	}

	String Convert::toString(DateTime * value){
		return new String(&value->toString());
	}
}