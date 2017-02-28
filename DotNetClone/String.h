#pragma once

#ifndef STRING_H
#define STRING_H

#include <string>
#include <algorithm>
#include <locale>
#include <vector>
#include <sstream>
#include <cctype>
#include "Object.h"

using namespace std;

/**
Represents text as a chain of characters. (c++ std::string wrapper)
*/
class String : public Object
{
public:
	/**
	Creates a new empty String class instance
	*/
	String();
	/**
	Creates a new String class instance with the value of str

	@param str the String to copy
	*/
	String(String* str);
	/**
	Creates a new String class instance with the value of str

	@param str the C++ string to copy
	*/
	String(string* str);
	/**
	Creates a new String class instance with the value of str

	@param str the c-string to copy
	*/
	String(char* str);
	~String();

	/**
	Clones this Instance

	@return String with the same value
	*/
	String clone();
	/**
	Returns the C++ string value of this instance

	@return C++ string pointer
	*/
	string getStringValue();
	/**
	Compares this Instance to the given String str in size and char-by-char lexicographically

	@param str String pointer to compare to this instance
	@return < 0, == 0 or > 0
	*/
	int compareTo(String* str);
	/**
	Checks if this Instance contains the given String str

	@param str String pointer to check
	@return true if this instance contains str
	*/
	bool contains(String* str);
	/**
	Copys a substring of this instance to a destination String at a specific position

	@param sourceIndex Position from where to read in this instance
	@param destination String to write to
	@param destinationIndex Position where to write to in the destination String
	@param count How many characters to copy
	*/
	void copyTo(unsigned int sourceIndex, String* destination, unsigned int destinationIndex, unsigned int count);
	/**
	Checks if this Instance ends with the given String str

	@param str String pointer to check
	@return true if this instance ends with str
	*/
	bool endsWith(String* str);
	/**
	Return the position of the occurence of the character c

	@param c character to find
	@return Position where it was found
	*/
	unsigned int indexOf(char c);
	/**
	Return the position of the occurence of the character c starting at a specific position

	@param c character to find
	@param startIndex starting at this position
	@return Position where it was found
	*/
	unsigned int indexOf(char c, unsigned int startIndex);
	/**
	Return the position of the occurence of the character c starting at a specific position for a limitied number of characters

	@param c character to find
	@param startIndex starting at this position
	@param count number of chars to search
	@return Position where it was found
	*/
	unsigned int indexOf(char c, unsigned int startIndex, unsigned int count);
	/**
	Return the position of the occurence of the String str

	@param str String to find
	@return Position where it was found
	*/
	unsigned int indexOf(String* str);
	/**
	Return the position of the occurence of the String str starting at a specific position

	@param str String to find
	@param startIndex starting at this position
	@return Position where it was found
	*/
	unsigned int indexOf(String* str, unsigned int startIndex);
	/**
	Return the position of the occurence of the String str starting at a specific position for a limitied number of characters

	@param str String to find
	@param startIndex starting at this position
	@param count number of chars to search
	@return Position where it was found
	*/
	unsigned int indexOf(String* str, unsigned int startIndex, unsigned int count);
	/**
	Return this instance with the given String attached

	@param startIndex starting at this position
	@param str String to inster
	@return this instance with str attached
	*/
	String insert(unsigned int startIndex, String* str);
	/**
	Return the position of the last occurence of the character c

	@param c character to find
	@return Position where it was found
	*/
	unsigned int lastIndexOf(char c);
	/**
	Return the position of the last occurence of the character c starting at a specific position

	@param c character to find
	@param startIndex starting at this position
	@return Position where it was found
	*/
	unsigned int lastIndexOf(char c, unsigned int startIndex);
	/**
	Return the position of the last occurence of the String str starting at a specific position for a limitied number of characters

	@param str String to find
	@param startIndex starting at this position
	@param count number of chars to search
	@return Position where it was found
	*/
	unsigned int lastIndexOf(char c, unsigned int startIndex, unsigned int count);
	/**
	Return the position of the last occurence of the String str

	@param str String to find
	@return Position where it was found
	*/
	unsigned int lastIndexOf(String* str);
	/**
	Return the position of the last occurence of the String str starting at a specific position

	@param str String to find
	@param startIndex starting at this position
	@return Position where it was found
	*/
	unsigned int lastIndexOf(String* str, unsigned int startIndex);
	/**
	Return the position of the last occurence of the String str starting at a specific position for a limitied number of characters

	@param str String to find
	@param startIndex starting at this position
	@param count number of chars to search
	@return Position where it was found
	*/
	unsigned int lastIndexOf(String* str, unsigned int startIndex, unsigned int count);
	/**
	Character count of the current instance

	@return character count
	*/
	unsigned int length();
	/**
	Fills this String with spaces starting from the beginning to reach the given width

	@param totalWidth target width
	@return this instance with added spaces
	*/
	String padLeft(int totalWidth);
	/**
	Fills this String with padding characters starting from the beginning to reach the given width

	@param totalWidth target width
	@param paddingChar character to insert
	@return this instance with added spaces
	*/
	String padLeft(int totalWidth, char paddingChar);
	/**
	Fills this String with spaces starting at the end to reach the given width

	@param totalWidth target width
	@return this instance with added characters
	*/
	String padRight(int totalWidth);
	/**
	Fills this String with padding characters starting at the end to reach the given width

	@param totalWidth target width
	@param paddingChar character to insert
	@return this instance with added characters
	*/
	String padRight(int totalWidth, char paddingChar);
	/**
	Removes characters starting at the startIndex

	@param startIndex position where to start removing
	@return this instance with removed characters
	*/
	String remove(unsigned int startIndex);
	/**
	Removes characters starting at the startIndex for a limited number

	@param startIndex position where to start removing
	@param count how many characters to remove
	@return this instance with removed characters
	*/
	String remove(unsigned int startIndex, unsigned int count);
	/**
	Replaces all old characters with new characters

	@param oldChar character to replace
	@param newChar character to insert instead
	@return this instance with replaced characters
	*/
	String replace(char oldChar, char newChar);
	/**
	Replaces all old Strings with new String

	@param oldString String to replace
	@param newString String to insert instead
	@return this instance with replaced Strings
	*/
	String replace(String* oldString, String* newString);
	/**
	Splits this instance String into a list(vector) with a character as separator

	@param separator The character that splits 2 Strings
	@return vector of Strings 
	*/
	vector<String*> split(char separator);
	/**
	Splits this instance String into a list(vector) with a String as separator

	@param separator The String that splits 2 Strings
	@return vector of Strings
	*/
	vector<String*> split(String* separator);
	/**
	Checks if this Instance starts with the given String str

	@param str String pointer to check
	@return true if this instance starts with str
	*/
	bool startsWith(String* str);
	/**
	Returns the characters of this instance as a String between the given position and the end

	@param startIndex Position in the current instance where to start writing the substring
	@return String that contains the substring
	*/
	String substring(unsigned int startIndex);
	/**
	Returns the characters of this instance as a String between the given position and length

	@param startIndex Position in the current instance where to start writing the substring
	@param length Number of characters to copy
	@return String that contains the substring
	*/
	String substring(unsigned int startIndex, unsigned int length);
	/**
	Returns the characters of this instance as a c-string

	@return char pointer that contains the Strings characters
	*/
	char* toCharArray();
	/**
	Returns the characters of this instance as a c-string limited by a startIndex and length

	@param startIndex Position in the current instance where to start writing the substring
	@param length Number of characters to copy
	@return char pointer that contains the Sub-Strings characters
	*/
	char* toCharArray(unsigned int startIndex, unsigned int length);
	/**
	Returns the characters of this String as lowercase

	@return String of lowercase characters
	*/
	String toLower();
	/**
	Returns the c++ string representation of this instance

	@return c++ string
	*/
	string toString();
	string getTypeString();
	/**
	Returns the characters of this String as uppercase

	@return String of uppercase characters
	*/
	String toUpper();
	/**
	Returns this instance with the spaces cut off at the beginning and end

	@return Trimmed String
	*/
	String trim();
	/**
	Returns this instance with the spaces cut off at the end

	@return Trimmed String
	*/
	String trimEnd();
	/**
	Returns this instance with the spaces cut off at the beginning

	@return Trimmed String
	*/
	String trimStart();

	friend String& operator+(String& str1, String& str2);
	friend String& operator+(String& str, const char* str2);
	friend String& operator+(const char* str, String& str2);
	friend String& operator+(string& str, String& str2);
	friend String& operator+(String& str, string& str2);
	friend String& operator+(String& str, int number);
	friend String& operator+(int number, String& str);
	String& operator+=(String& str);
	String& operator+=(string& str);
	String& operator+=(const char* str);
	String& operator+=(int number);
	bool operator==(String& str);
	bool operator==(const char* str);
	String operator=(const char* str);
	String operator=(string& str);
private:
	std::string value;
};

#endif