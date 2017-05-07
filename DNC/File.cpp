#include "File.h"

namespace dnc::IO{

	File::File(){}

	File::~File(){}

	void File::AppenAllLines(String & path, vector<String*>& contents){
		size_t len = 0;
		ofstream ofs;
		String* line;

		ofs.open(path.getStringValue(), ios::out | ios::app);

		if(!ofs.is_open()){
			cerr << "File could not be opened!" << endl;
			return;
		}

		len = contents.size();
		for(size_t i = 0; i < len; i++){
			line = contents[i];

			if(line != nullptr){
				ofs << line->getStringValue() << endl;
			} else{
				cerr << "Line is null" << endl;
			}
		}

		ofs.close();

	}

	void File::AppenAllText(String & path, String & contents){
		ofstream ofs;

		ofs.open(path.getStringValue(), ios::out | ios::app);

		if(!ofs.is_open()){
			cerr << "File could not be opened!" << endl;
			return;
		}

		ofs << contents.getStringValue();

		ofs.close();
	}

	FileStream File::AppendText(String& path){
		fstream ofs;

		ofs.open(path.getStringValue(), ios::out | ios::app);

		FileStream res(path, FileMode::Append);

		return res;
	}

	void File::Copy(String & sourceFileName, String & destFileName){
		ifstream ifs;
		ofstream ofs;

		ifs.open(sourceFileName.getStringValue(), ios::binary);
		ofs.open(destFileName.getStringValue(), ios::binary);

		ofs << ifs.rdbuf();

		ifs.close();
		ofs.close();
	}

	void File::Copy(String & sourceFileName, String & destFileName, bool overwrite){}

	FileStream File::Create(String & path){
		FileStream* fs = new FileStream(path, FileMode::Append);

		return *fs;
	}

	bool File::Exists(String & path){
		fstream fs(path.getStringValue());

		bool ex = fs.good();

		fs.close();

		return ex;
	}

	void File::Move(String & sourceFileName, String & destFileName){}

	char * File::ReadAllBytes(String & path){
		long len = 0;
		char* buffer;
		FileStream fs(path, FileMode::Open);

		len = fs.Length();

		buffer = new char[len];

		fs.Read(buffer, 0, len);

		fs.Close();

		return buffer;
	}

	vector<String*> File::ReadAllLines(String & path){
		string temp;
		vector<String*> res;
		ifstream fs(path.getStringValue(), ios::in);

		while(getline(fs, temp)){
			res.push_back(new String(&temp));
		}

		fs.close();

		return res;
	}

	String File::ReadAllText(String & path){
		string temp;
		string res;
		ifstream fs(path.getStringValue(), ios::in);

		while(getline(fs, temp)){
			res += temp;
		}

		fs.close();

		return String(&res);
	}

	void File::WriteAllBytes(String & path, char * bytes){
		ofstream fs(path.getStringValue(), ios::out);

		fs << bytes;

		fs.close();
	}

	void File::WriteAllLines(String & path, vector<String*> contents){
		long len = 0;
		String* line;
		ofstream fs(path.getStringValue(), ios::out);

		len = contents.size();

		for(long i = 0; i < len; i++){
			line = contents[i];

			if(line != nullptr){
				fs << (*line).getStringValue() << endl;
			}
		}

		fs.close();
	}

	void File::WriteAllText(String & path, String & contents){
		ofstream fs(path.getStringValue(), ios::out);

		fs << contents.getStringValue();

		fs.close();
	}
}