#include "Object.h"
#include "String.h"
#include "DateTime.h"
#include <iostream>

#pragma once
using namespace std;

/**
Converts between various formats
*/
class Convert
{
public:
	~Convert();
	static bool toBoolean(bool value);
	static bool toBoolean(char value);
	static bool toBoolean(double value);
	static bool toBoolean(float value);
	static bool toBoolean(short value);
	static bool toBoolean(int value);
	static bool toBoolean(long value);
	static bool toBoolean(unsigned short value);
	static bool toBoolean(unsigned int value);
	static bool toBoolean(unsigned long value);
	static bool toBoolean(Object* value);
	static bool toBoolean(String& value);

	static DateTime toDateTime(String& value);

	static double toDouble(String& value);
	static float toFloat(String& value);
	static int toInt(String& value);
	static long toLong(String& value);

	static String toString(bool value);
	static String toString(char value);
	static String toString(double value);
	static String toString(float value);
	static String toString(short value);
	static String toString(int value);
	static String toString(long value);
	static String toString(long long value);
	static String toString(unsigned short value);
	static String toString(unsigned int value);
	static String toString(unsigned long value);
	static String toString(Object* value);
	static String toString(DateTime* value);
private:
	Convert();
};

