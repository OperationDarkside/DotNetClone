#include "FileStream.h"

namespace dnc{
	namespace IO{

		FileStream::FileStream(): fs(std::fstream()), path(String()){}

		FileStream::FileStream(String & path, FileMode fm) : fs(std::fstream()), path(String()){
			this->path = path;
			this->fs = std::fstream();

			switch(fm){
				case Append:
					this->fs.open(path.GetStringValue(), std::ios::app | std::ios::in | std::ios::out | std::ios::binary);
					break;
				case Truncate:
					this->fs.open(path.GetStringValue(), std::ios::trunc | std::ios::in | std::ios::out | std::ios::binary);
					break;
				default:
					this->fs.open(path.GetStringValue(), std::ios::in | std::ios::out | std::ios::binary);
					break;
			}
		}

		FileStream::FileStream(String & path, FileMode fm, FileAccess fa): fs(std::fstream()), path(String()){
			this->path = path;
			this->fs = std::fstream();

			switch(fm){
				case Append:
					switch(fa){
						case 0:
							this->fs.open(path.GetStringValue(), std::ios::app | std::ios::in | std::ios::binary);
							break;
						case 1:
							this->fs.open(path.GetStringValue(), std::ios::app | std::ios::in | std::ios::out | std::ios::binary);
							break;
						case 2:
							this->fs.open(path.GetStringValue(), std::ios::app | std::ios::out | std::ios::binary);
							break;
					}
					break;
				case Truncate:
					switch(fa){
						case 0:
							this->fs.open(path.GetStringValue(), std::ios::trunc | std::ios::in | std::ios::binary);
							break;
						case 1:
							this->fs.open(path.GetStringValue(), std::ios::trunc | std::ios::in | std::ios::out | std::ios::binary);
							break;
						case 2:
							this->fs.open(path.GetStringValue(), std::ios::trunc | std::ios::out | std::ios::binary);
							break;
					}
					break;
				default:
					switch(fa){
						case 0:
							this->fs.open(path.GetStringValue(), std::ios::in | std::ios::binary);
							break;
						case 1:
							this->fs.open(path.GetStringValue(), std::ios::in | std::ios::out | std::ios::binary);
							break;
						case 2:
							this->fs.open(path.GetStringValue(), std::ios::out | std::ios::binary);
							break;
					}
					break;
			}
		}


		FileStream::~FileStream(){}

		std::string FileStream::ToString(){
			return std::string("System.IO.FileStream");
		}

		std::string FileStream::GetTypeString(){
			return std::string("FileStream");
		}

		void FileStream::Close(){
			this->fs.close();
		}

		void FileStream::Flush(){
			this->fs.flush();
		}

		long FileStream::Length(){
			long pos = 0;
			long len = 0;

			pos = this->fs.tellg();

			this->fs.seekg(0, this->fs.end);
			len = this->fs.tellg();
			this->fs.seekg(pos);

			return len;
		}

		String FileStream::Name(){
			return this->path;
		}

		long FileStream::Position(){
			return this->fs.tellp();
		}

		void FileStream::Position(long pos){
			this->fs.seekg(pos, std::ios::beg);
		}

		int FileStream::Read(char * bytes, int offset, int count){
			int cntr = 0;
			int sz = 0;
			char* buffer;

			if(bytes != nullptr){
				// this->file.seekg(offset);
				buffer = new char[count];

				this->fs.read(buffer, count);

				if(sizeof(bytes) >= (offset + count)){
					cntr = offset;

					for(int i = 0; i < count; ++i){
						bytes[cntr++] = buffer[i];
					}

					sz = sizeof(buffer);

					delete[] buffer;

					return sz;
				} else{
					std::cerr << "Buffer is not big enough" << std::endl;
				}
			} else{
				std::cerr << "Buffer is Null" << std::endl;
			}
		}

		long FileStream::Seek(long offset, SeekOrigin origin){
			this->fs.seekg(offset, origin);

			return this->fs.tellg();
		}

		void FileStream::Write(char * bytes, int offset, int count){
			char* tmp;
			int cntr = 0;

			if(sizeof(bytes) >= (offset + count)){
				tmp = new char[count];
				cntr = offset;

				for(int i = 0; i < count; i++){
					tmp[i] = bytes[cntr++];
				}

				this->fs.write(tmp, count);

				delete[] tmp;
			} else{
				std::cerr << "Buffer is not big enough" << std::endl;
			}
		}
	}
}