#include "String.h"
#include "DateTime.h"
#include "Console.h"
#include "FileStream.h"
#include "Boolean.h"
#include "DataTable.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <iostream>
#include <typeinfo>

String compare_clone(){
	String str("Something");

	String to_compare = str.clone();

	return to_compare;
}

void test_String_Class(){
	Console::WriteLine("Testing String class ----------------------");

	// Constructors
	String str1();
	String str2("Hello");
	if(str2 == "Hello"){
		Console::WriteLine("const char* constructor works!");
	} else{
		Console::WriteLine("Error");
	}
	String str3(&str2);
	if(str2 == "Hello"){
		Console::WriteLine("String pointer constructor works!");
	} else{
		Console::WriteLine("Error");
	}
	String str4(&std::string("World"));
	if(str4 == "World"){
		Console::WriteLine("std::string constructor works!");
	} else{
		Console::WriteLine("Error");
	}


	// Methods
	String str_clone = compare_clone();
	if(str_clone == "Something"){
		Console::WriteLine("cloning works!");
	} else{
		Console::WriteLine("Error");
	}

	std::string string_value = str2.getStringValue();
	if(string_value == "Hello"){
		Console::WriteLine("getStringValue works!");
	} else{
		Console::WriteLine("Error");
	}

	String* str_compare = new String("Hello");
	if(str2.compareTo(str_compare) == 0){
		Console::WriteLine("compareTo works!");
	} else{
		Console::WriteLine("Error");
	}

	if(str2.contains(&String("Hello"))){
		Console::WriteLine("contains works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_copyToSource("Hello World, my Friends!");
	String str_copyToDest("I need really much");
	str_copyToSource.copyTo(16, &str_copyToDest, 6, 7);
	if(str_copyToDest == "I needFriends really much"){
		Console::WriteLine("copyTo works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_endsWith("Hello world!");
	if(str_endsWith.endsWith(&String("ld!"))){
		Console::WriteLine("endsWith works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_indexOf1(str2);
	if(str_indexOf1.indexOf('l') == 2){
		Console::WriteLine("indexOf character works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_indexOf2(str_copyToSource);
	if(str_indexOf2.indexOf('l', 6) == 9){
		Console::WriteLine("indexOf character with startIndex works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_indexOf3(str_copyToSource);
	if(str_indexOf3.indexOf('l', 6, 5) == 9){
		Console::WriteLine("indexOf character with startIndex and count works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_indexOf4(str_copyToSource);
	if(str_indexOf4.indexOf(&String("my")) == 13){
		Console::WriteLine("indexOf String works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_indexOf5(str_copyToSource);
	if(str_indexOf5.indexOf(&String("my"), 10) == 13){
		Console::WriteLine("indexOf String with startIndex works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_indexOf6(str_copyToSource);
	if(str_indexOf6.indexOf(&String("my"), 10, 16) == 13){
		Console::WriteLine("indexOf String with startIndex and count works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_insert("Hello !");
	str_insert.insert(6, &String("world"));
	if(str_insert == "Hello world!"){
		Console::WriteLine("insert works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_lastIndexOf1("I'm tired of writing these mf tests!");
	if(str_lastIndexOf1.lastIndexOf('w') == 13){
		Console::WriteLine("lastIndexOf works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_lastIndexOf2("I'm tired of writing these mf tests!");
	if(str_lastIndexOf2.lastIndexOf('w', 20) == 13){
		Console::WriteLine("lastIndexOf with startIndex works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_lastIndexOf3("I'm tired of writing these mf tests!");
	if(str_lastIndexOf3.lastIndexOf('w', 20, 16) == 13){
		Console::WriteLine("lastIndexOf with startIndex and count works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_lastIndexOf4("I'm tired of writing these mf tests!");
	if(str_lastIndexOf4.lastIndexOf(&String("writ")) == 13){
		Console::WriteLine("lastIndexOf works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_lastIndexOf5("I'm tired of writing these mf tests!");
	if(str_lastIndexOf5.lastIndexOf(&String("writ"), 20) == 13){
		Console::WriteLine("lastIndexOf with startIndex works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_lastIndexOf6("I'm tired of writing these mf tests!");
	if(str_lastIndexOf6.lastIndexOf(&String("writ"), 20, 16) == 13){
		Console::WriteLine("lastIndexOf with startIndex and count works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_length("I'm tired ");
	if(str_length.length() == 10){
		Console::WriteLine("length works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_padLeft("Test");
	str_padLeft = str_padLeft.padLeft(10);
	if(str_padLeft == "      Test"){
		Console::WriteLine("padLeft works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_padLeft2("Test");
	str_padLeft2 = str_padLeft2.padLeft(10, '|');
	if(str_padLeft2 == "||||||Test"){
		Console::WriteLine("padLeft with spec characters works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_padRight("Test");
	str_padRight = str_padRight.padRight(10);
	if(str_padRight == "Test      "){
		Console::WriteLine("padRight works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_padRight2("Test");
	str_padRight2 = str_padRight2.padRight(10, '|');
	if(str_padRight2 == "Test||||||"){
		Console::WriteLine("padRight with spec characters works!");
	} else{
		Console::WriteLine("Error");
	}
}

int main(){
	test_String_Class();


	DateTime* dt = new DateTime(2017, 2, 4);
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

	Console::WriteLine(peter.contains(&String("b")));

	/*DataTable table("Kohlepfanne");
	table.Columns().Add(DataColumn("Vorname"));
	table.Columns().Add(DataColumn("Ja/Nein"));

	DataRow row = table.Rows()[0];

	Console::WriteLine(&row.Field<String>(0));
	Console::WriteLine(row.Field<bool>(1));*/

	system("PAUSE");
}