#include "FileStream.h"

namespace dnc::IO{

	FileStream::FileStream(): fs(fstream()), path(String()){}

	FileStream::FileStream(String & path, FileMode fm) : fs(fstream()), path(String()){
		this->path = path;
		this->fs = fstream();

		switch(fm){
			case Append:
				this->fs.open(path.getStringValue(), ios::app | ios::in | ios::out | ios::binary);
				break;
			case Truncate:
				this->fs.open(path.getStringValue(), ios::trunc | ios::in | ios::out | ios::binary);
				break;
			default:
				this->fs.open(path.getStringValue(), ios::in | ios::out | ios::binary);
				break;
		}
	}

	FileStream::FileStream(String & path, FileMode fm, FileAccess fa): fs(fstream()), path(String()){
		this->path = path;
		this->fs = fstream();

		switch(fm){
			case Append:
				switch(fa){
					case 0:
						this->fs.open(path.getStringValue(), ios::app | ios::in | ios::binary);
						break;
					case 1:
						this->fs.open(path.getStringValue(), ios::app | ios::in | ios::out | ios::binary);
						break;
					case 2:
						this->fs.open(path.getStringValue(), ios::app | ios::out | ios::binary);
						break;
				}
				break;
			case Truncate:
				switch(fa){
					case 0:
						this->fs.open(path.getStringValue(), ios::trunc | ios::in | ios::binary);
						break;
					case 1:
						this->fs.open(path.getStringValue(), ios::trunc | ios::in | ios::out | ios::binary);
						break;
					case 2:
						this->fs.open(path.getStringValue(), ios::trunc | ios::out | ios::binary);
						break;
				}
				break;
			default:
				switch(fa){
					case 0:
						this->fs.open(path.getStringValue(), ios::in | ios::binary);
						break;
					case 1:
						this->fs.open(path.getStringValue(), ios::in | ios::out | ios::binary);
						break;
					case 2:
						this->fs.open(path.getStringValue(), ios::out | ios::binary);
						break;
				}
				break;
		}
	}


	FileStream::~FileStream(){}

	string FileStream::toString(){
		return string("System.IO.FileStream");
	}

	string FileStream::getTypeString(){
		return string("FileStream");
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
		this->fs.seekg(pos, ios::beg);
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
				cerr << "Buffer is not big enough" << endl;
			}
		} else{
			cerr << "Buffer is Null" << endl;
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
			cerr << "Buffer is not big enough" << endl;
		}
	}
}