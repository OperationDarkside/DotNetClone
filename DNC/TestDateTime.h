#pragma once

#ifndef TESTDATETIME_H
#define TESTDATETIME_H

#include "Console.h"
#include "DateTime.h"

namespace dnc {

	class TestDateTime {

		TestDateTime() {
			DateTime dt1(1000000000);
			if(dt1.Ticks() == 1000000000) {
				Console::WriteLine("DATETIME: Microsecond constructor and Tick Method work!");
			} else {
				Console::WriteLine("Error");
			}

			DateTime dt2(2017, 8, 15);
			if(dt2.Year() == 2017 && dt2.Month() == 8 && dt2.Day() == 15) {
				Console::WriteLine("DATETIME: Year, Month, Day constructor and respective methods work!");
			} else {
				Console::WriteLine("Error");
			}

			DateTime dt3(2017, 8, 15, 15, 22, 45);
			if(dt3.Year() == 2017 && dt3.Month() == 8 && dt3.Day() == 15 && dt3.Hour() == 15 && dt3.Minute() == 22 && dt3.Second() == 45) {
				Console::WriteLine("DATETIME: Year, Month, Day, Hour, Minute, Second constructor and respective methods work!");
			} else {
				Console::WriteLine("Error");
			}
		}
	};
}
#endif // !TESTDATETIME_H