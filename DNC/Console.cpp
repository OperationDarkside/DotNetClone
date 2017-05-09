#include "Console.h"

namespace dnc{

	Console::~Console(){}

	std::string Console::getTypeString(){
		return std::string("Console");
	}

	std::string Console::toString(){
		return std::string("System.Console");
	}

	int Console::Read(){
		int val = 0;

		std::cin >> val;

		return val;
	}

	String Console::ReadLine(){
		std::string res;

		std::getline(std::cin, res);

		return String(&res);
	}

	void Console::Write(bool value){
		std::cout << (value ? "true" : "false");
	}

	void Console::Write(char c){
		std::cout << c;
	}

	void Console::Write(char * buffer){
		std::cout << buffer;
	}

	void Console::Write(double value){
		std::cout << std::to_string(value);
	}

	void Console::Write(float value){
		std::cout << std::to_string(value);
	}

	void Console::Write(int value){
		std::cout << std::to_string(value);
	}

	void Console::Write(long value){
		std::cout << std::to_string(value);
	}

	void Console::Write(Object * value){
		std::cout << value->toString();
	}

	void Console::Write(String& value){
		std::cout << value.getStringValue();
	}

	void Console::Write(char * buffer, long startIndex, long count){
		long pos_tmp = 0;
		size_t len;
		char* tmp;

		len = strlen(buffer);
		tmp = new char[count];

		if(len < (startIndex + count)){
			std::cout << "Array not big enough!" << std::endl;
			return;
		}

		for(size_t i = startIndex; i < count; ++i){
			tmp[pos_tmp] = buffer[i];
			++pos_tmp;
		}

		std::cout << tmp;
	}

	void Console::WriteLine(){
		std::cout << std::endl;
	}

	void Console::WriteLine(bool value){
		Write(value);
		std::cout << std::endl;
	}

	void Console::WriteLine(char c){
		Write(c);
		std::cout << std::endl;
	}

	void Console::WriteLine(char * buffer){
		Write(buffer);
		std::cout << std::endl;
	}

	void Console::WriteLine(double value){
		Write(value);
		std::cout << std::endl;
	}

	void Console::WriteLine(float value){
		Write(value);
		std::cout << std::endl;
	}

	void Console::WriteLine(int value){
		Write(value);
		std::cout << std::endl;
	}

	void Console::WriteLine(long value){
		Write(value);
		std::cout << std::endl;
	}

	void Console::WriteLine(Object * value){
		Write(value);
		std::cout << std::endl;
	}

	void Console::WriteLine(String& value){
		Write(value);
		std::cout << std::endl;
	}

	void Console::WriteLine(char * buffer, long startIndex, long count){
		Write(buffer, startIndex, count);
		std::cout << std::endl;
	}
}