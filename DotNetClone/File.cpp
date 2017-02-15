#include "File.h"



File::File()
{
}

File::~File()
{
}

void File::AppenAllLines(String & path, vector<String*>& contents)
{
	size_t len = 0;
	ofstream ofs;
	String* line;

	ofs.open(path.getStringValue(), ios::out | ios::app);

	if (!ofs.is_open()) {
		cerr << "File could not be opened!" << endl;
		return;
	}

	len = contents.size();
	for (size_t i = 0; i < len; i++) {
		line = contents[i];

		if (line != nullptr) {
			ofs << line->getStringValue() << endl;
		}
		else {
			cerr << "Line is null" << endl;
		}
	}

	ofs.close();

}

void File::AppenAllText(String & path, String & contents)
{
	ofstream ofs;

	ofs.open(path.getStringValue(), ios::out | ios::app);

	if (!ofs.is_open()) {
		cerr << "File could not be opened!" << endl;
		return;
	}

	ofs << contents.getStringValue();

	ofs.close();
}

FileStream File::AppendText(String& path)
{
	fstream ofs;

	ofs.open(path.getStringValue(), ios::out | ios::app);

	FileStream res(path, FileMode::Append);

	return res;
}

void File::Copy(String & sourceFileName, String & destFileName)
{
	ifstream ifs;
	ofstream ofs;

	ifs.open(sourceFileName.getStringValue(), ios::binary);
	ofs.open(destFileName.getStringValue(), ios::binary);

	ofs << ifs.rdbuf();

	ifs.close();
	ofs.close();
}

void File::Copy(String & sourceFileName, String & destFileName, bool overwrite)
{
}

FileStream File::Create(String & path)
{
	FileStream* fs = new FileStream(path, FileMode::Append);

	return *fs;
}

bool File::Exists(String & path)
{
	fstream fs(path.getStringValue());

	bool ex = fs.good();

	fs.close();

	return ex;
}

void File::Move(String & sourceFileName, String & destFileName)
{
}

char * File::ReadAllBytes(String & path)
{
	return nullptr;
}

vector<String*> File::ReadAllLines(String & path)
{
	return vector<String*>();
}

String File::ReadAllText(String & path)
{
	return String();
}

void File::WriteAllBytes(String & path, char * bytes)
{
}

void File::WriteAllLines(String & path, vector<String*> contents)
{
}

void File::WriteAllText(String & path, String & contents)
{
}
