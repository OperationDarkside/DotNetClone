#include "String.h"
#include "DateTime.h"
#include "Console.h"
#include "FileStream.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <iostream>

int main() {
	
	DateTime* dt = new DateTime(2017,2,4);
	std::cout << dt->Day() << "-" << dt->Month() << "-" << dt->Year() << std::endl;
	std::cout << dt->toLongDateString().getStringValue() << std::endl << dt->toLongTimeString().getStringValue() << std::endl;
	dt->Year(2014);
	std::cout << dt->Day() << "-" << dt->Month() << "-" << dt->Year() << std::endl;

	DateTime* dt1 = new DateTime(456734564423L);
	std::cout << dt1->toLongDateString().getStringValue() << std::endl << dt1->toLongTimeString().getStringValue() << std::endl;
	
	Object* o = new Object();
	std::cout << o->toString() << std::endl;

	TimeSpan* ts = new TimeSpan(4567345745L);
	std::cout << ts->toString() << std::endl;

	Console::WriteLine("Gimme some money!!!");
	Console::WriteLine(ts);

	String* sssss = new String("Hallo ");
	String* str2 = new String(" Du Horst!");

	*sssss += "Welt Nr." + std::to_string(75) + *str2;

	Console::WriteLine(sssss);

	String peter("BLUBB PETER");

	peter = peter.toLower();

	Console::WriteLine(&peter);
	
	/*
	fstream fs;
	fs.open("peter.txt", ios::in | ios::out | ios::binary);

	fs << "Hallo Welt, ihr Pisser!";

	long pos1 = fs.tellg();
	long pos2 = fs.tellp();

	fs.close();

	fstream ifs;
	ifs.open("peter.txt", ios::in | ios::binary);

	char* buffer = new char[10];

	ifs.read(buffer, 10);

	pos1 = ifs.tellg();
	pos2 = ifs.tellp();

	ifs.close();

	fstream ofs;
	ofs.open("peter.txt", ios::out | ios::binary);

	ofs.seekg(10);
	ofs << "Blubb";
	pos1 = ofs.tellg();

	ofs.close();
	*/
	system("PAUSE");
}