#include "String.h"
//#include "TestString.cpp"
#include "DateTime.h"
#include "TestDateTime.h"
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
#include "TestSqlClass.h"
#include <functional>
#include <map>
#include "Dictionary.h"
#include "XmlSerializer.h"
#include "JsonSerializer.h"
#include "CsvSerializer.h"

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

	String to_compare = str.Clone();

	return to_compare;
}

int main() {
	//test_String_Class();
	TestDateTime test_dt();

	/*DateTime dt_wd_test(2017,5,1);
	dt_wd_test.toLongDateString();*/

	DateTime dt(2017, 2, 4);
	std::cout << dt.Day() << "-" << dt.Month() << "-" << dt.Year() << std::endl;
	std::cout << dt.ToLongDateString().GetStringValue() << std::endl << dt.ToLongTimeString().GetStringValue() << std::endl;
	dt.AddYears(4);
	std::cout << dt.Day() << "-" << dt.Month() << "-" << dt.Year() << std::endl;

	DateTime dt1(456734564423L);
	std::cout << dt1.ToLongDateString().GetStringValue() << std::endl << dt1.ToLongTimeString().GetStringValue() << std::endl;

	Object* o = new Object();
	std::cout << o->ToString() << std::endl;
	delete o;

	TimeSpan ts(4567345745L);
	std::cout << ts.ToString() << std::endl;

	Console::WriteLine("Gimme some money!!!");
	Console::WriteLine(&ts);

	String sssss("Hallo ");
	String str2(" Du Horst!");

	sssss += "Welt Nr." + std::to_string(75) + str2;

	Console::WriteLine(sssss);

	String peter("BLUBB PETER");

	peter = peter.ToLower();

	Console::WriteLine(peter);

	Console::WriteLine(peter.Contains(&String("b")));

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

	MySqlCommand cmd(String("SELECT * FROM test"), &con);
	cmd.Parameters().Add(MySqlParameter(MySqlDbTypes::LONG, 3));

	MySqlDataAdapter adapt(cmd);

	MySqlDataReader reader = cmd.ExecuteReader();

	Collections::Generic::List<TestSqlClass> serialized = reader.Deserialize<TestSqlClass>();

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
	dt_february_test = dt_february_test.AddDays(3);
	Console::WriteLine(dt_february_test.ToUtcString());


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
	dnc::CSV::CsvSerializer csvSerializer;

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

	TestDataClass testClass1;
	testClass1.SetField1(42);
	testClass1.SetField2(1.1);
	testClass1.SetField3("bla");
	testClass1.SetField4(tmp);

	String blubb = serializer.Serialize(testClass);
	String jBlubb = jSerializer.Serialize(testClass);

	Console::WriteLine(blubb);

	// Deserialization
	TestDataClass deserialClass;
	deserialClass.SetField4(new TestDataClass());
	deserialClass = serializer.Deserialize<TestDataClass>(blubb);

	dnc::Collections::Generic::List<TestDataClass> tdList;
	tdList.Add(*tmp);
	tdList.Add(testClass);
	tdList.Add(testClass1);

	String csv = csvSerializer.Serialize(tdList);

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