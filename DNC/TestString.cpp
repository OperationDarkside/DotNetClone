#ifndef TEST_STRING_CLASS_H
#define TEST_STRING_CLASS_H

#include "Console.h"
#include "DateTime.h"

namespace dnc {
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
		String str4(std::string("World"));
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
		if(str2.CompareTo(str_compare) == 0) {
			Console::WriteLine("compareTo works!");
		} else {
			Console::WriteLine("Error");
		}

		if(str2.Contains(&String("Hello"))) {
			Console::WriteLine("contains works!");
		} else {
			Console::WriteLine("Error");
		}

		String str_copyToSource("Hello World, my Friends!");
		String str_copyToDest("I need really much");
		str_copyToSource.CopyTo(16, &str_copyToDest, 6, 7);
		if(str_copyToDest == "I needFriends really much") {
			Console::WriteLine("copyTo works!");
		} else {
			Console::WriteLine("Error");
		}

		String str_endsWith("Hello world!");
		if(str_endsWith.EndsWith(&String("ld!"))) {
			Console::WriteLine("endsWith works!");
		} else {
			Console::WriteLine("Error");
		}

		String str_indexOf1(str2);
		if(str_indexOf1.IndexOf('l') == 2) {
			Console::WriteLine("indexOf character works!");
		} else {
			Console::WriteLine("Error");
		}

		String str_indexOf2(str_copyToSource);
		if(str_indexOf2.IndexOf('l', 6) == 9) {
			Console::WriteLine("indexOf character with startIndex works!");
		} else {
			Console::WriteLine("Error");
		}

		String str_indexOf3(str_copyToSource);
		if(str_indexOf3.IndexOf('l', 6, 5) == 9) {
			Console::WriteLine("indexOf character with startIndex and count works!");
		} else {
			Console::WriteLine("Error");
		}

		String str_indexOf4(str_copyToSource);
		if(str_indexOf4.IndexOf(&String("my")) == 13) {
			Console::WriteLine("indexOf String works!");
		} else {
			Console::WriteLine("Error");
		}

		String str_indexOf5(str_copyToSource);
		if(str_indexOf5.IndexOf(&String("my"), 10) == 13) {
			Console::WriteLine("indexOf String with startIndex works!");
		} else {
			Console::WriteLine("Error");
		}

		String str_indexOf6(str_copyToSource);
		if(str_indexOf6.IndexOf(&String("my"), 10, 16) == 13) {
			Console::WriteLine("indexOf String with startIndex and count works!");
		} else {
			Console::WriteLine("Error");
		}

		String str_insert("Hello !");
		str_insert.Insert(6, &String("world"));
		if(str_insert == "Hello world!") {
			Console::WriteLine("insert works!");
		} else {
			Console::WriteLine("Error");
		}

		String str_lastIndexOf1("I'm tired of writing these mf tests!");
		if(str_lastIndexOf1.LastIndexOf('w') == 13) {
			Console::WriteLine("lastIndexOf works!");
		} else {
			Console::WriteLine("Error");
		}

		String str_lastIndexOf2("I'm tired of writing these mf tests!");
		if(str_lastIndexOf2.LastIndexOf('w', 20) == 13) {
			Console::WriteLine("lastIndexOf with startIndex works!");
		} else {
			Console::WriteLine("Error");
		}

		String str_lastIndexOf3("I'm tired of writing these mf tests!");
		if(str_lastIndexOf3.LastIndexOf('w', 20, 16) == 13) {
			Console::WriteLine("lastIndexOf with startIndex and count works!");
		} else {
			Console::WriteLine("Error");
		}

		String str_lastIndexOf4("I'm tired of writing these mf tests!");
		if(str_lastIndexOf4.LastIndexOf(&String("writ")) == 13) {
			Console::WriteLine("lastIndexOf works!");
		} else {
			Console::WriteLine("Error");
		}

		String str_lastIndexOf5("I'm tired of writing these mf tests!");
		if(str_lastIndexOf5.LastIndexOf(&String("writ"), 20) == 13) {
			Console::WriteLine("lastIndexOf with startIndex works!");
		} else {
			Console::WriteLine("Error");
		}

		String str_lastIndexOf6("I'm tired of writing these mf tests!");
		if(str_lastIndexOf6.LastIndexOf(&String("writ"), 20, 16) == 13) {
			Console::WriteLine("lastIndexOf with startIndex and count works!");
		} else {
			Console::WriteLine("Error");
		}

		String str_length("I'm tired ");
		if(str_length.Length() == 10) {
			Console::WriteLine("length works!");
		} else {
			Console::WriteLine("Error");
		}

		String str_padLeft("Test");
		str_padLeft = str_padLeft.PadLeft(10);
		if(str_padLeft == "      Test") {
			Console::WriteLine("padLeft works!");
		} else {
			Console::WriteLine("Error");
		}

		String str_padLeft2("Test");
		str_padLeft2 = str_padLeft2.PadLeft(10, '|');
		if(str_padLeft2 == "||||||Test") {
			Console::WriteLine("padLeft with spec characters works!");
		} else {
			Console::WriteLine("Error");
		}

		String str_padRight("Test");
		str_padRight = str_padRight.PadRight(10);
		if(str_padRight == "Test      ") {
			Console::WriteLine("padRight works!");
		} else {
			Console::WriteLine("Error");
		}

		String str_padRight2("Test");
		str_padRight2 = str_padRight2.PadRight(10, '|');
		if(str_padRight2 == "Test||||||") {
			Console::WriteLine("padRight with spec characters works!");
		} else {
			Console::WriteLine("Error");
		}

		String str_remove1("Test");
		str_remove1 = str_remove1.Remove(2);
		if(str_remove1 == "Te") {
			Console::WriteLine("remove works!");
		} else {
			Console::WriteLine("Error");
		}

		String str_remove2("Test");
		str_remove2 = str_remove2.Remove(1, 2);
		if(str_remove2 == "Tt") {
			Console::WriteLine("remove with count works!");
		} else {
			Console::WriteLine("Error");
		}

		String str_replace1("Test");
		str_replace1 = str_replace1.Replace('e', 'a');
		if(str_replace1 == "Tast") {
			Console::WriteLine("replace works!");
		} else {
			Console::WriteLine("Error");
		}

		String str_replace2("Test mit Replace");
		str_replace2 = str_replace2.Replace(&String("mit"), &String("ohne"));
		if(str_replace2 == "Test ohne Replace") {
			Console::WriteLine("replace works!");
		} else {
			Console::WriteLine("Error");
		}

		String str_split1("Test;mit;Split");
		Collections::Generic::List<String> array_split1 = str_split1.Split(';');
		if(array_split1[2] == "Split") {
			Console::WriteLine("split works!");
		} else {
			Console::WriteLine("Error");
		}

		String str_split2("TestlostmitlostSplit");
		Collections::Generic::List<String> array_split2 = str_split2.Split("lost");
		if(array_split2[2] == "Split") {
			Console::WriteLine("split mit String works!");
		} else {
			Console::WriteLine("Error");
		}

		String str_startsWith("Test mit Start");
		if(str_startsWith.StartsWith(&String("Test"))) {
			Console::WriteLine("startsWith works!");
		} else {
			Console::WriteLine("Error");
		}

		String str_sub("Test mit Substring");
		str_sub = str_sub.Substring(5);
		if(str_sub == "mit Substring") {
			Console::WriteLine("substring works!");
		} else {
			Console::WriteLine("Error");
		}

		String str_sub1("Test mit Substring");
		str_sub1 = str_sub1.Substring(5, 3);
		if(str_sub1 == "mit") {
			Console::WriteLine("substring with count works!");
		} else {
			Console::WriteLine("Error");
		}

		String str_toCharArr1("Test mit toCharArray");
		char* charArr1 = str_toCharArr1.ToCharArray();
		if(strcmp(charArr1, "Test mit toCharArray") == 0) {
			Console::WriteLine("toCharArray works!");
		} else {
			Console::WriteLine("Error");
		}

		String str_toCharArr2("Test mit toCharArray");
		char* charArr2 = str_toCharArr2.ToCharArray(5, 3);
		if(strcmp(charArr2, "mit") == 0) {
			Console::WriteLine("toCharArray with startIndex and count works!");
		} else {
			Console::WriteLine("Error");
		}

		String str_toLower("Test mit ToLoWeR");
		str_toLower = str_toLower.ToLower();
		if(str_toLower == "test mit tolower") {
			Console::WriteLine("toLower works!");
		} else {
			Console::WriteLine("Error");
		}

		String str_toUpper("Test mit Toupper");
		str_toUpper = str_toUpper.ToUpper();
		if(str_toUpper == "TEST MIT TOUPPER") {
			Console::WriteLine("toUpper works!");
		} else {
			Console::WriteLine("Error");
		}

		String str_trim("    Test mit Trim    ");
		str_trim = str_trim.Trim();
		if(str_trim == "Test mit Trim") {
			Console::WriteLine("trim works!");
		} else {
			Console::WriteLine("Error");
		}

		String str_trimEnd("Test mit TrimEnd    ");
		str_trimEnd = str_trimEnd.TrimEnd();
		if(str_trimEnd == "Test mit TrimEnd") {
			Console::WriteLine("trimEnd works!");
		} else {
			Console::WriteLine("Error");
		}

		String str_trimStart("    Test mit TrimStart");
		str_trimStart = str_trimStart.TrimStart();
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

		DateTime dt = 25;
		String object_template_string = String("Peters age is ") + dt;
		if(object_template_string == "Peters age is 25") {
			Console::WriteLine("Object Template String works!");
		} else {
			Console::WriteLine("Error");
		}
	}
}
#endif // !TEST_STRING_CLASS_H