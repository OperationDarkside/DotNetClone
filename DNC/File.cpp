#include "File.h"

namespace dnc{
	namespace IO{

		File::File(){}

		File::~File(){}

		void File::AppenAllLines(String & path, Collections::Generic::List<String> contents){
			size_t len = 0;
			std::ofstream ofs;
			String line;

			ofs.open(path.GetStringValue(), std::ios::out | std::ios::app);

			if(!ofs.is_open()){
				std::cerr << "File could not be opened!" << std::endl;
				return;
			}

			len = contents.Count();
			for(size_t i = 0; i < len; i++){
				line = contents[i];

				if(line != nullptr){
					ofs << line.GetStringValue() << std::endl;
				} else{
					std::cerr << "Line is null" << std::endl;
				}
			}

			ofs.close();

		}

		void File::AppenAllText(String & path, String & contents){
			std::ofstream ofs;

			ofs.open(path.GetStringValue(), std::ios::out | std::ios::app);

			if(!ofs.is_open()){
				std::cerr << "File could not be opened!" << std::endl;
				return;
			}

			ofs << contents.GetStringValue();

			ofs.close();
		}

		FileStream File::AppendText(String& path){
			std::fstream ofs;

			ofs.open(path.GetStringValue(), std::ios::out | std::ios::app);

			FileStream res(path, FileMode::Append);

			return res;
		}

		void File::Copy(String & sourceFileName, String & destFileName){
			std::ifstream ifs;
			std::ofstream ofs;

			ifs.open(sourceFileName.GetStringValue(), std::ios::binary);
			ofs.open(destFileName.GetStringValue(), std::ios::binary);

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
			std::fstream fs(path.GetStringValue());

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

		Collections::Generic::List<String> File::ReadAllLines(String & path){
			std::string temp;
			Collections::Generic::List<String> res;
			std::ifstream fs(path.GetStringValue(), std::ios::in);

			while(getline(fs, temp)){
				res.Add(String(&temp));
			}

			fs.close();

			return res;
		}

		String File::ReadAllText(String & path){
			std::string temp;
			std::string res;
			std::ifstream fs(path.GetStringValue(), std::ios::in);

			while(getline(fs, temp)){
				res += temp;
			}

			fs.close();

			return String(&res);
		}

		void File::WriteAllBytes(String & path, char * bytes){
			std::ofstream fs(path.GetStringValue(), std::ios::out);

			fs << bytes;

			fs.close();
		}

		void File::WriteAllLines(String & path, Collections::Generic::List<String> contents){
			long len = 0;
			String line;
			std::ofstream fs(path.GetStringValue(), std::ios::out);

			len = contents.Count();

			for(long i = 0; i < len; i++){
				line = contents[i];

				if(line != nullptr){
					fs << line.GetStringValue() << std::endl;
				}
			}

			fs.close();
		}

		void File::WriteAllText(String & path, String & contents){
			std::ofstream fs(path.GetStringValue(), std::ios::out);

			fs << contents.GetStringValue();

			fs.close();
		}
	}
}