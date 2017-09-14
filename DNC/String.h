#pragma once

#ifndef STRING_H
#define STRING_H

#include <algorithm>
#include <locale>
#include <sstream>
#include <cctype>
#include <array>
#include "List.h"

namespace dnc{

	/**
	Represents text as a chain of characters. (c++ std::string wrapper)
	*/
	class String: public Object{

		friend class Serializable;

	public:
		/**
		Creates a new empty String class instance
		*/
		String();
		String(const String& str);
		String(String&& str);
		String(Object& str);
		/**
		Creates a new String class instance with the value of str

		@param str the String to copy
		*/
		String(String* str);;
		/**
		Creates a new String class instance with the value of str

		@param str the C++ string to copy
		*/
		String(std::string* str);
		/**
		Creates a new String class instance with the value of str

		@param str the c-string to copy
		*/
		String(char* str);
		/**
		Creates a new String class instance with the value of str

		@param str the c++ array of chars to copy
		*/
		template<size_t num>
		String(std::array<char, num> str);

		~String();

		/**
		Clones this Instance

		@return String with the same value
		*/
		String Clone();
		/**
		Returns the C++ string value of this instance

		@return C++ string pointer
		*/
		std::string GetStringValue();
		/**
		Compares this Instance to the given String str in size and char-by-char lexicographically

		@param str String pointer to compare to this instance
		@return < 0, == 0 or > 0
		*/
		int CompareTo(String* str);
		/**
		Checks if this Instance contains the given String str

		@param str String pointer to check
		@return true if this instance contains str
		*/
		bool Contains(String str);
		/**
		Copys a substring of this instance to a destination String at a specific position

		@param sourceIndex Position from where to read in this instance
		@param destination String to write to
		@param destinationIndex Position where to write to in the destination String
		@param count How many characters to copy
		*/
		void CopyTo(unsigned int sourceIndex, String* destination, unsigned int destinationIndex, unsigned int count);
		/**
		Checks if this Instance ends with the given String str

		@param str String pointer to check
		@return true if this instance ends with str
		*/
		bool EndsWith(String* str);
		/**
		Return the position of the occurence of the character c

		@param c character to find
		@return Position where it was found
		*/
		unsigned int IndexOf(char c);
		/**
		Return the position of the occurence of the character c starting at a specific position

		@param c character to find
		@param startIndex starting at this position
		@return Position where it was found
		*/
		unsigned int IndexOf(char c, unsigned int startIndex);
		/**
		Return the position of the occurence of the character c starting at a specific position for a limitied number of characters

		@param c character to find
		@param startIndex starting at this position
		@param count number of chars to search
		@return Position where it was found
		*/
		unsigned int IndexOf(char c, unsigned int startIndex, unsigned int count);
		/**
		Return the position of the occurence of the String str

		@param str String to find
		@return Position where it was found
		*/
		unsigned int IndexOf(String* str);
		/**
		Return the position of the occurence of the String str starting at a specific position

		@param str String to find
		@param startIndex starting at this position
		@return Position where it was found
		*/
		unsigned int IndexOf(String* str, unsigned int startIndex);
		/**
		Return the position of the occurence of the String str starting at a specific position for a limitied number of characters

		@param str String to find
		@param startIndex starting at this position
		@param count number of chars to search
		@return Position where it was found
		*/
		unsigned int IndexOf(String* str, unsigned int startIndex, unsigned int count);
		/**
		Return this instance with the given String attached

		@param startIndex starting at this position
		@param str String to inster
		@return this instance with str attached
		*/
		String Insert(unsigned int startIndex, String* str);

		/**
		Returns a String consisting of the collections contents separated by the separator

		@param separator String that separates the list values
		@param values Strings to join
		*/
		static String Join(String separator, Collections::Generic::List<String> values);

		/**
		Return the position of the last occurence of the character c

		@param c character to find
		@return Position where it was found
		*/
		unsigned int LastIndexOf(char c);
		/**
		Return the position of the last occurence of the character c starting at a specific position

		@param c character to find
		@param startIndex starting at this position
		@return Position where it was found
		*/
		unsigned int LastIndexOf(char c, unsigned int startIndex);
		/**
		Return the position of the last occurence of the String str starting at a specific position for a limitied number of characters

		@param str String to find
		@param startIndex starting at this position
		@param count number of chars to search
		@return Position where it was found
		*/
		unsigned int LastIndexOf(char c, unsigned int startIndex, unsigned int count);
		/**
		Return the position of the last occurence of the String str

		@param str String to find
		@return Position where it was found
		*/
		unsigned int LastIndexOf(String* str);
		/**
		Return the position of the last occurence of the String str starting at a specific position

		@param str String to find
		@param startIndex starting at this position
		@return Position where it was found
		*/
		unsigned int LastIndexOf(String* str, unsigned int startIndex);
		/**
		Return the position of the last occurence of the String str starting at a specific position for a limitied number of characters

		@param str String to find
		@param startIndex starting at this position
		@param count number of chars to search
		@return Position where it was found
		*/
		unsigned int LastIndexOf(String* str, unsigned int startIndex, unsigned int count);
		/**
		Character count of the current instance

		@return character count
		*/
		unsigned int Length();
		/**
		Fills this String with spaces starting from the beginning to reach the given width

		@param totalWidth target width
		@return this instance with added spaces
		*/
		String PadLeft(int totalWidth);
		/**
		Fills this String with padding characters starting from the beginning to reach the given width

		@param totalWidth target width
		@param paddingChar character to insert
		@return this instance with added spaces
		*/
		String PadLeft(int totalWidth, char paddingChar);
		/**
		Fills this String with spaces starting at the end to reach the given width

		@param totalWidth target width
		@return this instance with added characters
		*/
		String PadRight(int totalWidth);
		/**
		Fills this String with padding characters starting at the end to reach the given width

		@param totalWidth target width
		@param paddingChar character to insert
		@return this instance with added characters
		*/
		String PadRight(int totalWidth, char paddingChar);
		/**
		Removes characters starting at the startIndex

		@param startIndex position where to start removing
		@return this instance with removed characters
		*/
		String Remove(unsigned int startIndex);
		/**
		Removes characters starting at the startIndex for a limited number

		@param startIndex position where to start removing
		@param count how many characters to remove
		@return this instance with removed characters
		*/
		String Remove(unsigned int startIndex, unsigned int count);
		/**
		Replaces all old characters with new characters

		@param oldChar character to replace
		@param newChar character to insert instead
		@return this instance with replaced characters
		*/
		String Replace(char oldChar, char newChar);
		/**
		Replaces all old Strings with new String

		@param oldString String to replace
		@param newString String to insert instead
		@return this instance with replaced Strings
		*/
		String Replace(String* oldString, String* newString);
		/**
		Splits this instance String into a list(vector) with a character as separator

		@param separator The character that splits 2 Strings
		@return vector of Strings
		*/
		Collections::Generic::List<String> Split(char separator);
		/**
		Splits this instance String into a list(vector) with a String as separator

		@param separator The String that splits 2 Strings
		@return vector of Strings
		*/
		Collections::Generic::List<String> Split(String separator);
		/**
		Checks if this Instance starts with the given String str

		@param str String pointer to check
		@return true if this instance starts with str
		*/
		bool StartsWith(String str);
		/**
		Returns the characters of this instance as a String between the given position and the end

		@param startIndex Position in the current instance where to start writing the substring
		@return String that contains the substring
		*/
		String Substring(unsigned int startIndex);
		/**
		Returns the characters of this instance as a String between the given position and length

		@param startIndex Position in the current instance where to start writing the substring
		@param length Number of characters to copy
		@return String that contains the substring
		*/
		String Substring(unsigned int startIndex, unsigned int length);
		/**
		Returns the characters of this instance as a c-string

		@return char pointer that contains the Strings characters
		*/
		char* ToCharArray();
		/**
		Returns the characters of this instance as a c-string limited by a startIndex and length

		@param startIndex Position in the current instance where to start writing the substring
		@param length Number of characters to copy
		@return char pointer that contains the Sub-Strings characters
		*/
		char* ToCharArray(unsigned int startIndex, unsigned int length);
		/**
		Returns the characters of this String as lowercase

		@return String of lowercase characters
		*/
		String ToLower();
		/**
		Returns the c++ string representation of this instance

		@return c++ string
		*/
		std::string ToString() override;
		std::string GetTypeString() override;
		/**
		Returns the characters of this String as uppercase

		@return String of uppercase characters
		*/
		String ToUpper();
		/**
		Returns this instance with the spaces cut off at the beginning and end

		@return Trimmed String
		*/
		String Trim();
		/**
		Returns this instance with the spaces cut off at the end

		@return Trimmed String
		*/
		String TrimEnd();
		/**
		Returns this instance with the spaces cut off at the beginning

		@return Trimmed String
		*/
		String TrimStart();

		friend String operator+(String str1, String str2);
		friend String operator+(String& str, const char* str2);
		friend String operator+(char* str, String& str2);
		friend String operator+(std::string& str, String& str2);
		friend String operator+(String& str, std::string& str2);
		friend String operator+(String& str, int number);
		friend String operator+(int number, String& str);
		friend String operator+(String& str, unsigned long long number);
		friend String operator+(unsigned long long number, String& str);
		String operator+=(String& str);
		String operator+=(std::string& str);
		String operator+=(const char* str);
		String operator+=(int number);
		bool operator==(String& str);
		bool operator==(const char* str);
		bool operator!=(String& str);
		bool operator!=(const char* str);
		template<size_t num>
		String operator=(std::array<char, num> str);
		String operator=(const char* str);
		String operator=(std::string& str);
		String& operator=(String& str);
		String& operator=(String&& str);
		operator std::string();
		char operator[](unsigned int index);

	private:
		std::string value;

		void FromString(std::string val) override;
	};

	template<size_t num>
	inline String::String(std::array<char, num> str){

		this->value.append(str.begin(), str.end());
	}

	template<size_t num>
	inline String String::operator=(std::array<char, num> str){

		this->value.append(str.begin(), str.end());

		return *this;
	}
}

#endif