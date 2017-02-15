#include "Object.h"
#include "String.h"
#include "FileStream.h"

#pragma once
class File : public Object
{
public:
	~File();

	void AppenAllLines(String& path, vector<String*>& contents);
	void AppenAllText(String& path, String& contents);
	FileStream AppendText(String& path);
	void Copy(String& sourceFileName, String& destFileName);
	void Copy(String& sourceFileName, String& destFileName, bool overwrite);
	FileStream Create(String& path);
	bool Exists(String& path);
	void Move(String& sourceFileName, String& destFileName);
	char* ReadAllBytes(String& path);
	vector<String*> ReadAllLines(String& path);
	String ReadAllText(String& path);
	void WriteAllBytes(String& path, char* bytes);
	void WriteAllLines(String& path, vector<String*> contents);
	void WriteAllText(String& path, String& contents);
private:
	File();
};

