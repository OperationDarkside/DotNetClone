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

void addRows(DataTable& t) {
	DataRow row;

	row = t.NewRow();

	row.SetField(0, String("Peter"));
	row.SetField(1, true);

	t.Rows().Add(row);
}

int main() {

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
	table.Columns().Add(DataColumn("Vorname"));
	table.Columns().Add(DataColumn("Ja/Nein"));

	addRows(table);

	DataRow row = table.Rows()[0];

	Console::WriteLine(&row.Field<String>(0));
	Console::WriteLine(row.Field<bool>(1));

	system("PAUSE");
}