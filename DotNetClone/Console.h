#pragma once
#include "String.h"
#include <iostream>

using namespace std;

class Console : public Object
{
public:

	string getTypeString();
	string toString();
	/**
	Reads a single sign from the standard input stream

	@return Integer that represents a sign
	*/
	static int Read();
	/**
	Reads a String from the standard input stream

	@return The given String
	*/
	static String ReadLine();

	/**
	Writes the boolean value to the standard outputstream

	@param value writes "true" or "false"
	*/
	static void Write(bool value);
	/**
	Writes the character c to the standard outputstream

	@param c character to write
	*/
	static void Write(char c);
	/**
	Writes the c_string buffer to the standard outputstream

	@param buffer c_string to write
	*/
	static void Write(char* buffer);
	/**
	Writes the double value to the standard outputstream

	@param value double to write
	*/
	static void Write(double value);
	/**
	Writes the float value to the standard outputstream

	@param value float to write
	*/
	static void Write(float value);
	/**
	Writes the integer value to the standard outputstream

	@param value integer to write
	*/
	static void Write(int value);
	/**
	Writes the long value to the standard outputstream

	@param value long to write
	*/
	static void Write(long value);
	/**
	Calls the Objects toString() method and writes the result to the standard outputstream

	@param value Object to write
	*/
	static void Write(Object* value);
	/**
	Writes the String value to the standard outputstream

	@param value String to write
	*/
	static void Write(String* value);
	/**
	Writes a c_string's substring to the standard outputstream

	@param buffer c_string source
	@param startIndex where to begin in the buffer
	@param count how many characters to extract
	*/
	static void Write(char* buffer, long startIndex, long count);
	/**
	Writes a new Line to the standard outputstreamn
	*/
	static void WriteLine();
	/**
	Writes the bool value with a new line to the standard outputstreamn

	@param value bool can be "true" or "false"
	*/
	static void WriteLine(bool value);
	/**
	Writes the character c with a new line to the standard outputstreamn

	@param value bool can be "true" or "false"
	*/
	static void WriteLine(char c);
	/**
	Writes the c_string buffer with a new line to the standard outputstreamn

	@param buffer c_string to write
	*/
	static void WriteLine(char* buffer);
	/**
	Writes the double value with a new line to the standard outputstreamn

	@param value double to write
	*/
	static void WriteLine(double value);
	/**
	Writes the float value with a new line to the standard outputstreamn

	@param value float to write
	*/
	static void WriteLine(float value);
	/**
	Writes the integer value with a new line to the standard outputstreamn

	@param value integer to write
	*/
	static void WriteLine(int value);
	/**
	Writes the long integer value with a new line to the standard outputstreamn

	@param value long integer to write
	*/
	static void WriteLine(long value);
	/**
	Writes the Objects toString() value with a new line to the standard outputstreamn

	@param value Object to write
	*/
	static void WriteLine(Object* value);
	/**
	Writes the String value with a new line to the standard outputstreamn

	@param value String to write
	*/
	static void WriteLine(String* value);
	/**
	Writes a c_string's substring with a new line to the standard outputstream

	@param buffer c_string source
	@param startIndex where to begin in the buffer
	@param count how many characters to extract
	*/
	static void WriteLine(char* buffer, long startIndex, long count);

	~Console();
private:
	Console() {}
};

