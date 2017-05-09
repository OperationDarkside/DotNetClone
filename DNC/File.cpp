#include "File.h"

namespace dnc{
	namespace IO{

		File::File(){}

		File::~File(){}

		void File::AppenAllLines(String & path, std::vector<String*>& contents){
			size_t len = 0;
			std::ofstream ofs;
			String* line;

			ofs.open(path.getStringValue(), std::ios::out | std::ios::app);

			if(!ofs.is_open()){
				std::cerr << "File could not be opened!" << std::endl;
				return;
			}

			len = contents.size();
			for(size_t i = 0; i < len; i++){
				line = contents[i];

				if(line != nullptr){
					ofs << line->getStringValue() << std::endl;
				} else{
					std::cerr << "Line is null" << std::endl;
				}
			}

			ofs.close();

		}

		void File::AppenAllText(String & path, String & contents){
			std::ofstream ofs;

			ofs.open(path.getStringValue(), std::ios::out | std::ios::app);

			if(!ofs.is_open()){
				std::cerr << "File could not be opened!" << std::endl;
				return;
			}

			ofs << contents.getStringValue();

			ofs.close();
		}

		FileStream File::AppendText(String& path){
			std::fstream ofs;

			ofs.open(path.getStringValue(), std::ios::out | std::ios::app);

			FileStream res(path, FileMode::Append);

			return res;
		}

		void File::Copy(String & sourceFileName, String & destFileName){
			std::ifstream ifs;
			std::ofstream ofs;

			ifs.open(sourceFileName.getStringValue(), std::ios::binary);
			ofs.open(destFileName.getStringValue(), std::ios::binary);

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
			std::fstream fs(path.getStringValue());

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

		std::vector<String*> File::ReadAllLines(String & path){
			std::string temp;
			std::vector<String*> res;
			std::ifstream fs(path.getStringValue(), std::ios::in);

			while(getline(fs, temp)){
				res.push_back(new String(&temp));
			}

			fs.close();

			return res;
		}

		String File::ReadAllText(String & path){
			std::string temp;
			std::string res;
			std::ifstream fs(path.getStringValue(), std::ios::in);

			while(getline(fs, temp)){
				res += temp;
			}

			fs.close();

			return String(&res);
		}

		void File::WriteAllBytes(String & path, char * bytes){
			std::ofstream fs(path.getStringValue(), std::ios::out);

			fs << bytes;

			fs.close();
		}

		void File::WriteAllLines(String & path, std::vector<String*> contents){
			long len = 0;
			String* line;
			std::ofstream fs(path.getStringValue(), std::ios::out);

			len = contents.size();

			for(long i = 0; i < len; i++){
				line = contents[i];

				if(line != nullptr){
					fs << (*line).getStringValue() << std::endl;
				}
			}

			fs.close();
		}

		void File::WriteAllText(String & path, String & contents){
			std::ofstream fs(path.getStringValue(), std::ios::out);

			fs << contents.getStringValue();

			fs.close();
		}
	}
}