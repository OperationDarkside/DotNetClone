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
#include "DataColumnCollection.h"
#include "SqlDataReader.h"
#include "MySqlConnection.h"
#include "MySqlCommand.h"
#include "MySqlDataAdapter.h"



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

	String str_remove1("Test");
	str_remove1 = str_remove1.remove(2);
	if(str_remove1 == "Te"){
		Console::WriteLine("remove works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_remove2("Test");
	str_remove2 = str_remove2.remove(1, 2);
	if(str_remove2 == "Tt"){
		Console::WriteLine("remove with count works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_replace1("Test");
	str_replace1 = str_replace1.replace('e', 'a');
	if(str_replace1 == "Tast"){
		Console::WriteLine("replace works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_replace2("Test mit Replace");
	str_replace2 = str_replace2.replace(&String("mit"), &String("ohne"));
	if(str_replace2 == "Test ohne Replace"){
		Console::WriteLine("replace works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_split1("Test;mit;Split");
	vector<String*> array_split1 = str_split1.split(';');
	if(*array_split1[2] == "Split"){
		Console::WriteLine("split works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_split2("TestlostmitlostSplit");
	vector<String*> array_split2 = str_split2.split(&String("lost"));
	if(*array_split2[2] == "Split"){
		Console::WriteLine("split mit String works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_startsWith("Test mit Start");
	if(str_startsWith.startsWith(&String("Test"))){
		Console::WriteLine("startsWith works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_sub("Test mit Substring");
	str_sub = str_sub.substring(5);
	if(str_sub == "mit Substring"){
		Console::WriteLine("substring works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_sub1("Test mit Substring");
	str_sub1 = str_sub1.substring(5, 3);
	if(str_sub1 == "mit"){
		Console::WriteLine("substring with count works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_toCharArr1("Test mit toCharArray");
	char* charArr1 = str_toCharArr1.toCharArray();
	if(strcmp(charArr1, "Test mit toCharArray") == 0){
		Console::WriteLine("toCharArray works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_toCharArr2("Test mit toCharArray");
	char* charArr2 = str_toCharArr2.toCharArray(5, 3);
	if(strcmp(charArr2, "mit") == 0){
		Console::WriteLine("toCharArray with startIndex and count works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_toLower("Test mit ToLoWeR");
	str_toLower = str_toLower.toLower();
	if(str_toLower == "test mit tolower"){
		Console::WriteLine("toLower works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_toUpper("Test mit Toupper");
	str_toUpper = str_toUpper.toUpper();
	if(str_toUpper == "TEST MIT TOUPPER"){
		Console::WriteLine("toUpper works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_trim("    Test mit Trim    ");
	str_trim = str_trim.trim();
	if(str_trim == "Test mit Trim"){
		Console::WriteLine("trim works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_trimEnd("Test mit TrimEnd    ");
	str_trimEnd = str_trimEnd.trimEnd();
	if(str_trimEnd == "Test mit TrimEnd"){
		Console::WriteLine("trimEnd works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_trimStart("    Test mit TrimStart");
	str_trimStart = str_trimStart.trimStart();
	if(str_trimStart == "Test mit TrimStart"){
		Console::WriteLine("trimStart works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_operator_add;
	str_operator_add = String("Hallo ") + String("Welt!");
	if(str_operator_add == "Hallo Welt!"){
		Console::WriteLine("operator_add String String works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_operator_add2;
	str_operator_add2 = String("Hallo ") + "Welt!";
	if(str_operator_add2 == "Hallo Welt!"){
		Console::WriteLine("operator_add String const char* works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_operator_add3;
	str_operator_add3 = "Hallo " + String("Welt!");
	if(str_operator_add3 == "Hallo Welt!"){
		Console::WriteLine("operator_add const char* String works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_operator_add4;
	str_operator_add4 = string("Hallo ") + String("Welt!");
	if(str_operator_add4 == "Hallo Welt!"){
		Console::WriteLine("operator_add std::string String works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_operator_add5;
	str_operator_add5 = String("Hallo ") + string("Welt!");
	if(str_operator_add5 == "Hallo Welt!"){
		Console::WriteLine("operator_add String std::string works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_operator_add6;
	str_operator_add6 = String("Mambo Nr. ") + 5;
	if(str_operator_add6 == "Mambo Nr. 5"){
		Console::WriteLine("operator_add String int works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_operator_add7;
	str_operator_add7 = 5 + String(" Mambos there are");
	if(str_operator_add7 == "5 Mambos there are"){
		Console::WriteLine("operator_add int String works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_operator_add8("Hallo ");
	str_operator_add8 += String("Welt!");
	if(str_operator_add8 == "Hallo Welt!"){
		Console::WriteLine("operator_add += String works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_operator_add9("Hallo ");
	str_operator_add9 += string("Welt!");
	if(str_operator_add9 == "Hallo Welt!"){
		Console::WriteLine("operator_add += std::string works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_operator_add10("Hallo ");
	str_operator_add10 += "Welt!";
	if(str_operator_add10 == "Hallo Welt!"){
		Console::WriteLine("operator_add += const char* works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_operator_add11("Mambo Nr. ");
	str_operator_add11 += 5;
	if(str_operator_add11 == "Mambo Nr. 5"){
		Console::WriteLine("operator_add += int works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_operator_assign = "Hallo Welt!";
	if(str_operator_assign == "Hallo Welt!"){
		Console::WriteLine("operator_assign const char* works!");
	} else{
		Console::WriteLine("Error");
	}

	String str_operator_assign2 = String("Hallo Welt!");
	if(str_operator_assign2 == "Hallo Welt!"){
		Console::WriteLine("operator_assign String works!");
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

	DataTable table("Kohlepfanne");
	table.Columns().Add(DataColumn(String("Vorname"), Type::getType<String>(String())));
	table.Columns().Add(DataColumn("Ja/Nein", Type::getType<bool>(true)));

	DataRow r = table.NewRow();
	r.SetField<String>(0, String("Hallo Welt!"));
	r.SetField(1, true);
	table.Rows().Add(r);

	DataRow row = table.Rows()[0];

	Console::WriteLine(&row.Field<String>(0));
	Console::WriteLine(row.Field<bool>(1));


	DataTable table2("dsfgdfg");
	table2.Columns().Add(DataColumn("Vorname", Type::getType<String>(String())));

	DataColumn col2("Nachname", Type::getType<String>(String()));
	table2.Columns().Add(col2);
	table2.Columns().Add(DataColumn("Pisse", Type::getType<String>(String())));

	DataRow row2 = table2.NewRow();
	row2.SetField<String>(0, String("Heinz"));
	row2.SetField<String>(1, String("Herrmann"));
	row2.SetField<String>(2, String("aus dem Arsch"));
	table2.Rows().Add(row2);

	DataRow row3 = table2.NewRow();
	row3.SetField<String>(0, String("Peter"));
	row3.SetField<String>(1, String("Norbert"));
	row3.SetField<String>(2, String("Fehler"));
	table2.Rows().Add(row3);

	table2.Columns().Remove(&col2);

	//SqlDataReader reader;

	MySqlConnection con(String("SERVER=tcp://127.0.0.1:3306;DATABASE=test;UID=root;PASSWORD="));

	con.Open();

	MySqlCommand cmd(String("SELECT * FROM test"), &con);

	MySqlDataAdapter adapt(cmd);

	DataTable memTable;

	adapt.Fill(memTable);

	system("PAUSE");
}