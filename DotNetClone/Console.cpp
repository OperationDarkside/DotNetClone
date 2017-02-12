#include "Console.h"

Console::~Console()
{
}

string Console::getTypeString()
{
	return string("Console");
}

string Console::toString()
{
	return string("System.Console");
}

int Console::Read()
{
	int val = 0;

	cin >> val;

	return val;
}

String Console::ReadLine()
{
	string res;

	getline(cin, res);

	return new String(&res);
}

void Console::Write(bool value)
{
	cout << (value ? "true" : "false");
}

void Console::Write(char c)
{
	cout << c;
}

void Console::Write(char * buffer)
{
	cout << buffer;
}

void Console::Write(double value)
{
	cout << to_string(value);
}

void Console::Write(float value)
{
	cout << to_string(value);
}

void Console::Write(int value)
{
	cout << to_string(value);
}

void Console::Write(long value)
{
	cout << to_string(value);
}

void Console::Write(Object * value)
{
	cout << value->toString();
}

void Console::Write(String * value)
{
	cout << value->getStringValue();
}

void Console::Write(char * buffer, long startIndex, long count)
{
	long pos_tmp = 0;
	size_t len;
	char* tmp;

	len = strlen(buffer);
	tmp = new char[count];

	if (len < (startIndex + count)) {
		cout << "Array not big enough!" << endl;
		return;
	}

	for (size_t i = startIndex; i < count; ++i)
	{
		tmp[pos_tmp] = buffer[i];
		++pos_tmp;
	}

	cout << tmp;
}

void Console::WriteLine()
{
	cout << endl;
}

void Console::WriteLine(bool value)
{
	Write(value);
	cout << endl;
}

void Console::WriteLine(char c)
{
	Write(c);
	cout << endl;
}

void Console::WriteLine(char * buffer)
{
	Write(buffer);
	cout << endl;
}

void Console::WriteLine(double value)
{
	Write(value);
	cout << endl;
}

void Console::WriteLine(float value)
{
	Write(value);
	cout << endl;
}

void Console::WriteLine(int value)
{
	Write(value);
	cout << endl;
}

void Console::WriteLine(long value)
{
	Write(value);
	cout << endl;
}

void Console::WriteLine(Object * value)
{
	Write(value);
	cout << endl;
}

void Console::WriteLine(String * value)
{
	Write(value);
	cout << endl;
}

void Console::WriteLine(char * buffer, long startIndex, long count)
{
	Write(buffer, startIndex, count);
	cout << endl;
}
