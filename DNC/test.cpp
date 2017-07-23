#include "String.h"
#include "DateTime.h"
#include "Console.h"
#include "FileStream.h"
#include "Boolean.h"
#include "DataTable.h"
#include <iostream>
#include <typeinfo>
#include "DataColumnCollection.h"
#include "MySqlConnection.h"
#include "MySqlDataAdapter.h"
#include <my_global.h>
#include "Socket.h"
#include "TestDataClass.h"
#include <functional>
#include <map>
#include "Dictionary.h"
#include "XmlSerializer.h"
#include "JsonSerializer.h"

using namespace dnc;
using namespace dnc::Data;
using namespace dnc::Data::SqlClient;
using namespace dnc::Net;
using namespace dnc::Net::Sockets;

/*void print_num(int i){
	std::cout << i << '\n';
}*/

void foo() {}
void goo(std::string* p) {}
void bar(int& p) {}
int bar2() { return 6; }

String compare_clone() {
	String str("Something");

	String to_compare = str.clone();

	return to_compare;
}

void test_String_Class() {
	Console::WriteLine("Testing String class ----------------------");

	// Constructors
	String str1();
	String str2("Hello");
	if(str2 == "Hello") {
		Console::WriteLine("const char* constructor works!");
	} else {
		Console::WriteLine("Error");
	}
	String str3(&str2);
	if(str2 == "Hello") {
		Console::WriteLine("String pointer constructor works!");
	} else {
		Console::WriteLine("Error");
	}
	String str4(&std::string("World"));
	if(str4 == "World") {
		Console::WriteLine("std::string constructor works!");
	} else {
		Console::WriteLine("Error");
	}


	// Methods
	/*String str_clone = compare_clone();
	if(str_clone == "Something"){
		Console::WriteLine("cloning works!");
	} else{
		Console::WriteLine("Error");
	}*/

	std::string string_value = str2.GetStringValue();
	if(string_value == "Hello") {
		Console::WriteLine("getStringValue works!");
	} else {
		Console::WriteLine("Error");
	}

	String* str_compare = new String("Hello");
	if(str2.compareTo(str_compare) == 0) {
		Console::WriteLine("compareTo works!");
	} else {
		Console::WriteLine("Error");
	}

	if(str2.contains(&String("Hello"))) {
		Console::WriteLine("contains works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_copyToSource("Hello World, my Friends!");
	String str_copyToDest("I need really much");
	str_copyToSource.copyTo(16, &str_copyToDest, 6, 7);
	if(str_copyToDest == "I needFriends really much") {
		Console::WriteLine("copyTo works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_endsWith("Hello world!");
	if(str_endsWith.endsWith(&String("ld!"))) {
		Console::WriteLine("endsWith works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_indexOf1(str2);
	if(str_indexOf1.indexOf('l') == 2) {
		Console::WriteLine("indexOf character works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_indexOf2(str_copyToSource);
	if(str_indexOf2.indexOf('l', 6) == 9) {
		Console::WriteLine("indexOf character with startIndex works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_indexOf3(str_copyToSource);
	if(str_indexOf3.indexOf('l', 6, 5) == 9) {
		Console::WriteLine("indexOf character with startIndex and count works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_indexOf4(str_copyToSource);
	if(str_indexOf4.indexOf(&String("my")) == 13) {
		Console::WriteLine("indexOf String works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_indexOf5(str_copyToSource);
	if(str_indexOf5.indexOf(&String("my"), 10) == 13) {
		Console::WriteLine("indexOf String with startIndex works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_indexOf6(str_copyToSource);
	if(str_indexOf6.indexOf(&String("my"), 10, 16) == 13) {
		Console::WriteLine("indexOf String with startIndex and count works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_insert("Hello !");
	str_insert.insert(6, &String("world"));
	if(str_insert == "Hello world!") {
		Console::WriteLine("insert works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_lastIndexOf1("I'm tired of writing these mf tests!");
	if(str_lastIndexOf1.lastIndexOf('w') == 13) {
		Console::WriteLine("lastIndexOf works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_lastIndexOf2("I'm tired of writing these mf tests!");
	if(str_lastIndexOf2.lastIndexOf('w', 20) == 13) {
		Console::WriteLine("lastIndexOf with startIndex works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_lastIndexOf3("I'm tired of writing these mf tests!");
	if(str_lastIndexOf3.lastIndexOf('w', 20, 16) == 13) {
		Console::WriteLine("lastIndexOf with startIndex and count works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_lastIndexOf4("I'm tired of writing these mf tests!");
	if(str_lastIndexOf4.lastIndexOf(&String("writ")) == 13) {
		Console::WriteLine("lastIndexOf works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_lastIndexOf5("I'm tired of writing these mf tests!");
	if(str_lastIndexOf5.lastIndexOf(&String("writ"), 20) == 13) {
		Console::WriteLine("lastIndexOf with startIndex works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_lastIndexOf6("I'm tired of writing these mf tests!");
	if(str_lastIndexOf6.lastIndexOf(&String("writ"), 20, 16) == 13) {
		Console::WriteLine("lastIndexOf with startIndex and count works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_length("I'm tired ");
	if(str_length.length() == 10) {
		Console::WriteLine("length works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_padLeft("Test");
	str_padLeft = str_padLeft.padLeft(10);
	if(str_padLeft == "      Test") {
		Console::WriteLine("padLeft works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_padLeft2("Test");
	str_padLeft2 = str_padLeft2.padLeft(10, '|');
	if(str_padLeft2 == "||||||Test") {
		Console::WriteLine("padLeft with spec characters works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_padRight("Test");
	str_padRight = str_padRight.padRight(10);
	if(str_padRight == "Test      ") {
		Console::WriteLine("padRight works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_padRight2("Test");
	str_padRight2 = str_padRight2.padRight(10, '|');
	if(str_padRight2 == "Test||||||") {
		Console::WriteLine("padRight with spec characters works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_remove1("Test");
	str_remove1 = str_remove1.remove(2);
	if(str_remove1 == "Te") {
		Console::WriteLine("remove works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_remove2("Test");
	str_remove2 = str_remove2.remove(1, 2);
	if(str_remove2 == "Tt") {
		Console::WriteLine("remove with count works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_replace1("Test");
	str_replace1 = str_replace1.replace('e', 'a');
	if(str_replace1 == "Tast") {
		Console::WriteLine("replace works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_replace2("Test mit Replace");
	str_replace2 = str_replace2.replace(&String("mit"), &String("ohne"));
	if(str_replace2 == "Test ohne Replace") {
		Console::WriteLine("replace works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_split1("Test;mit;Split");
	Collections::Generic::List<String> array_split1 = str_split1.split(';');
	if(array_split1[2] == "Split") {
		Console::WriteLine("split works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_split2("TestlostmitlostSplit");
	Collections::Generic::List<String> array_split2 = str_split2.split("lost");
	if(array_split2[2] == "Split") {
		Console::WriteLine("split mit String works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_startsWith("Test mit Start");
	if(str_startsWith.startsWith(&String("Test"))) {
		Console::WriteLine("startsWith works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_sub("Test mit Substring");
	str_sub = str_sub.substring(5);
	if(str_sub == "mit Substring") {
		Console::WriteLine("substring works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_sub1("Test mit Substring");
	str_sub1 = str_sub1.substring(5, 3);
	if(str_sub1 == "mit") {
		Console::WriteLine("substring with count works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_toCharArr1("Test mit toCharArray");
	char* charArr1 = str_toCharArr1.toCharArray();
	if(strcmp(charArr1, "Test mit toCharArray") == 0) {
		Console::WriteLine("toCharArray works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_toCharArr2("Test mit toCharArray");
	char* charArr2 = str_toCharArr2.toCharArray(5, 3);
	if(strcmp(charArr2, "mit") == 0) {
		Console::WriteLine("toCharArray with startIndex and count works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_toLower("Test mit ToLoWeR");
	str_toLower = str_toLower.toLower();
	if(str_toLower == "test mit tolower") {
		Console::WriteLine("toLower works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_toUpper("Test mit Toupper");
	str_toUpper = str_toUpper.toUpper();
	if(str_toUpper == "TEST MIT TOUPPER") {
		Console::WriteLine("toUpper works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_trim("    Test mit Trim    ");
	str_trim = str_trim.trim();
	if(str_trim == "Test mit Trim") {
		Console::WriteLine("trim works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_trimEnd("Test mit TrimEnd    ");
	str_trimEnd = str_trimEnd.trimEnd();
	if(str_trimEnd == "Test mit TrimEnd") {
		Console::WriteLine("trimEnd works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_trimStart("    Test mit TrimStart");
	str_trimStart = str_trimStart.trimStart();
	if(str_trimStart == "Test mit TrimStart") {
		Console::WriteLine("trimStart works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_operator_add;
	str_operator_add = String("Hallo ") + String("Welt!");
	if(str_operator_add == "Hallo Welt!") {
		Console::WriteLine("operator_add String String works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_operator_add2;
	str_operator_add2 = String("Hallo ") + "Welt!";
	if(str_operator_add2 == "Hallo Welt!") {
		Console::WriteLine("operator_add String const char* works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_operator_add3;
	str_operator_add3 = "Hallo " + String("Welt!");
	if(str_operator_add3 == "Hallo Welt!") {
		Console::WriteLine("operator_add const char* String works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_operator_add4;
	str_operator_add4 = std::string("Hallo ") + String("Welt!");
	if(str_operator_add4 == "Hallo Welt!") {
		Console::WriteLine("operator_add std::string String works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_operator_add5;
	str_operator_add5 = String("Hallo ") + std::string("Welt!");
	if(str_operator_add5 == "Hallo Welt!") {
		Console::WriteLine("operator_add String std::string works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_operator_add6;
	str_operator_add6 = String("Mambo Nr. ") + 5;
	if(str_operator_add6 == "Mambo Nr. 5") {
		Console::WriteLine("operator_add String int works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_operator_add7;
	str_operator_add7 = 5 + String(" Mambos there are");
	if(str_operator_add7 == "5 Mambos there are") {
		Console::WriteLine("operator_add int String works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_operator_add8("Hallo ");
	str_operator_add8 += String("Welt!");
	if(str_operator_add8 == "Hallo Welt!") {
		Console::WriteLine("operator_add += String works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_operator_add9("Hallo ");
	str_operator_add9 += std::string("Welt!");
	if(str_operator_add9 == "Hallo Welt!") {
		Console::WriteLine("operator_add += std::string works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_operator_add10("Hallo ");
	str_operator_add10 += "Welt!";
	if(str_operator_add10 == "Hallo Welt!") {
		Console::WriteLine("operator_add += const char* works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_operator_add11("Mambo Nr. ");
	str_operator_add11 += 5;
	if(str_operator_add11 == "Mambo Nr. 5") {
		Console::WriteLine("operator_add += int works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_operator_assign = "Hallo Welt!";
	if(str_operator_assign == "Hallo Welt!") {
		Console::WriteLine("operator_assign const char* works!");
	} else {
		Console::WriteLine("Error");
	}

	String str_operator_assign2 = String("Hallo Welt!");
	if(str_operator_assign2 == "Hallo Welt!") {
		Console::WriteLine("operator_assign String works!");
	} else {
		Console::WriteLine("Error");
	}

	dnc::Collections::Generic::List<String> listStrings;
	listStrings.Add("Hallo");
	listStrings.Add("Welt");
	listStrings.Add("Noob");

	String joined_string = String::Join(" ", listStrings);
	if(joined_string == "Hallo Welt Noob") {
		Console::WriteLine("join String works!");
	} else {
		Console::WriteLine("Error");
	}
}

int main() {
	test_String_Class();

	/*DateTime dt_wd_test(2017,5,1);
	dt_wd_test.toLongDateString();*/

	DateTime* dt = new DateTime(2017, 2, 4);
	std::cout << dt->Day() << "-" << dt->Month() << "-" << dt->Year() << std::endl;
	std::cout << dt->toLongDateString().GetStringValue() << std::endl << dt->toLongTimeString().GetStringValue() << std::endl;
	dt->Year(2014);
	std::cout << dt->Day() << "-" << dt->Month() << "-" << dt->Year() << std::endl;

	DateTime* dt1 = new DateTime(456734564423L);
	std::cout << dt1->toLongDateString().GetStringValue() << std::endl << dt1->toLongTimeString().GetStringValue() << std::endl;

	Object* o = new Object();
	std::cout << o->ToString() << std::endl;

	TimeSpan* ts = new TimeSpan(4567345745L);
	std::cout << ts->ToString() << std::endl;

	Console::WriteLine("Gimme some money!!!");
	Console::WriteLine(ts);

	String* sssss = new String("Hallo ");
	String* str2 = new String(" Du Horst!");

	*sssss += "Welt Nr." + std::to_string(75) + *str2;

	Console::WriteLine(*sssss);

	String peter("BLUBB PETER");

	peter = peter.toLower();

	Console::WriteLine(peter);

	Console::WriteLine(peter.contains(&String("b")));

	DataTable table("Kohlepfanne");
	table.Columns().Add(DataColumn(String("Vorname"), Type::getType<String>(String())));
	table.Columns().Add(DataColumn("Ja/Nein", Type::getType<bool>(true)));

	DataRow r = table.NewRow();
	r.SetField<String>(0, String("Hallo Welt!"));
	r.SetField(1, true);
	table.Rows().Add(r);

	DataRow row = table.Rows()[0];

	Console::WriteLine(row.Field<String>(0));
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

	// mysql++ ----------------------------------------------

	/*mysqlpp::Connection conn(false);

	bool connected = conn.connect("test", "127.0.0.1", "root", "", 3306);

	if(connected){
		mysqlpp::Query query = conn.query("SELECT * FROM test");

		if(mysqlpp::StoreQueryResult res = query.store()){
			cout << "We have:" << endl;
			mysqlpp::StoreQueryResult::const_iterator it;
			for(it = res.begin(); it != res.end(); ++it){
				mysqlpp::Row row = *it;
				cout << '\t' << row[0] << " | " << row[1] << endl;
			}
		} else{
			cerr << "Failed to get item list: " << query.error() << endl;
			return 1;
		}
	}*/
	int ipaaaa = 0;

	ipaaaa = (127 << 24) | (0 << 16) | (0 << 8) | (1 << 0);

	unsigned char bytes[4];

	bytes[0] = ipaaaa & 0xFF;
	bytes[1] = (ipaaaa >> 8) & 0xFF;
	bytes[2] = (ipaaaa >> 16) & 0xFF;
	bytes[3] = (ipaaaa >> 24) & 0xFF;

	// mysql C API

	std::cout << mysql_get_client_info() << std::endl;

	/*MYSQL* conni = mysql_init(NULL);
	if(mysql_real_connect(conni, "127.0.0.1", "root", "", "test", 3306, NULL, 0)){
		if(!mysql_query(conni, "SELECT * FROM test")){
			MYSQL_RES *ressi = mysql_store_result(conni);
			int num_fields = mysql_num_fields(ressi);

			MYSQL_ROW row;
			MYSQL_FIELD *field;

			while((row = mysql_fetch_row(ressi))){
				for(int i = 0; i < num_fields; i++){
					if(i == 0){
						while(field = mysql_fetch_field(ressi)){
							printf("%s ", field->name);
						}

						printf("\n");
					}
					printf("%s ", row[i] ? row[i] : "NULL");
				}
				printf("\n");
			}

			mysql_free_result(ressi);
			mysql_close(conni);
		} else{
			fprintf(stderr, "%s\n", mysql_error(conni));
			mysql_close(conni);
		}
	} else{
		fprintf(stderr, "%s\n", mysql_error(conni));
		mysql_close(conni);
	}*/

	// SQL Interaction -------------------------------------------

	MySqlConnection con(String("SERVER=127.0.0.1:3306;DATABASE=test;UID=root;PASSWORD="));

	con.Open();

	MySqlCommand cmd(String("SELECT * FROM test WHERE ID = ?"), &con);
	cmd.Parameters().Add(MySqlParameter(MySqlDbTypes::LONG, 3));

	MySqlDataAdapter adapt(cmd);

	DataTable memTable;

	adapt.Fill(memTable);

	con.Close();

	Console::Write("Tablename: ");
	Console::WriteLine(memTable.TableName());

	Console::Write(memTable[0].Field<long>(0));
	Console::Write(" | ");
	Console::Write(memTable[0].Field<String>(1));
	Console::Write(" | "); // 2017-04-02T15:24:44
	DateTime dt_temp = memTable[0].Field<DateTime>(2);
	Console::WriteLine(&dt_temp);

	DateTime dt_date = dt_temp.Date();
	Console::WriteLine(&dt_date);

	memTable.Clear();


	DateTime dt_february_test(2017, 1, 28);
	dt_february_test = dt_february_test.addDays(3);
	Console::WriteLine(dt_february_test.toUtcString());


	// LISTE
	Collections::Generic::List<int> listInt;

	listInt.Add(3);
	listInt.Add(6);
	listInt.Add(234);
	listInt.Add(111111);

	// Socket
	Socket sock(AddressFamily::IPv4, SocketType::Stream, ProtocolType::Tcp);

	sock.Connect(String("127.0.0.1"), 80);
	sock.Send("GET /cgi-bin/CppWebToolkit.exe?prename=Marvin&lastname=%20du%20Pisser http/1.1\r\nHost: 127.0.0.1\r\nConnection: close\r\n\r\n");

	std::array<char, 500> recvData;

	sock.Receive(recvData);
	sock.Close();

	String received(recvData);
	Console::WriteLine(received);

	// Socket Listen
	/*Socket listenSock(AddressFamily::IPv4, SocketType::Stream, ProtocolType::Tcp);

	std::vector<unsigned char> addr;
	addr.push_back(127);
	addr.push_back(0);
	addr.push_back(0);
	addr.push_back(1);

	listenSock.Bind(IPEndPoint(IPAddress(addr), 999));
	listenSock.Listen(10);
	Socket accSock = listenSock.Accept();

	Console::WriteLine();

	while(true){
		//char recvBuffer;
		//std::string recvBufferStr;
		//recvBuffer.resize(10);
		std::array<char, 50> recvBuffer;

		int bytesrecvd = accSock.Receive(recvBuffer);

		//char * d = &recvBuffer;

		String recvBufferStr = recvBuffer;

		Console::Write(recvBuffer);

		if(bytesrecvd != 50){
			break;
		}
	}
	*/
	// Serialization

	double tttt = 5.3;

	Double ddddd = tttt;
	//Object& blabla = tttt;
	dnc::Xml::XmlSerializer serializer;
	dnc::Json::JsonSerializer jSerializer;

	TestDataClass* tmp = new TestDataClass();

	tmp->SetField1(77);
	tmp->SetField2(5.75);
	tmp->SetField3("Fünf");
	tmp->SetField4(tmp);

	TestDataClass testClass;
	testClass.SetField1(55);
	testClass.SetField2(5.5);
	testClass.SetField3("blubb");
	testClass.SetField4(tmp);

	String blubb = serializer.Serialize(testClass);
	String jBlubb = jSerializer.Serialize(testClass);

	Console::WriteLine(blubb);

	// Deserialization
	TestDataClass deserialClass;
	deserialClass.SetField4(new TestDataClass());
	deserialClass = serializer.Deserialize<TestDataClass>(blubb);

	// isType
	Object* tmp_o = new String();
	bool istype = Type::isType<Object, String>(tmp_o);

	String* tmp_str = dynamic_cast<String*>(tmp_o);

	delete tmp_str;

	Console::Write("Object* Is Type of String:");
	Console::WriteLine(istype);

	// Dictionary
	Collections::Generic::Dictionary<int, String> dick;
	dick.Add(0, "Fidely");
	dick.Add(2345, "Blubberbla");
	dick.Add(1111, "NoggNogg");
	
	Console::WriteLine("Dictionary len: " + dick.Count());

	bool contkey = dick.ContainsKey(1111);

	Console::WriteLine("Dictionary Contains 1111: " + contkey);
	

	system("PAUSE");
}