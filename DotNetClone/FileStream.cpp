#include "FileStream.h"



FileStream::FileStream()
{
}

FileStream::FileStream(String & path, FileMode fm)
{
	this->path = path;

	switch (fm)
	{
	case Append:
		file.open(path.getStringValue(), ios::app | ios::in | ios::out | ios::binary);
		break;
	case Truncate:
		file.open(path.getStringValue(), ios::trunc | ios::in | ios::out | ios::binary);
		break;
	default:
		file.open(path.getStringValue(), ios::in | ios::out | ios::binary);
		break;
	}
}

FileStream::FileStream(String & path, FileMode fm, FileAccess fa)
{
	this->path = path;

	switch (fm)
	{
	case Append:
		switch (fa)
		{
		case 0:
			file.open(path.getStringValue(), ios::app | ios::in | ios::binary);
			break;
		case 1:
			file.open(path.getStringValue(), ios::app | ios::in | ios::out | ios::binary);
			break;
		case 2:
			file.open(path.getStringValue(), ios::app | ios::out | ios::binary);
			break;
		}
		break;
	case Truncate:
		switch (fa)
		{
		case 0:
			file.open(path.getStringValue(), ios::trunc | ios::in | ios::binary);
			break;
		case 1:
			file.open(path.getStringValue(), ios::trunc | ios::in | ios::out | ios::binary);
			break;
		case 2:
			file.open(path.getStringValue(), ios::trunc | ios::out | ios::binary);
			break;
		}
		break;
	default:
		switch (fa)
		{
		case 0:
			file.open(path.getStringValue(), ios::in | ios::binary);
			break;
		case 1:
			file.open(path.getStringValue(), ios::in | ios::out | ios::binary);
			break;
		case 2:
			file.open(path.getStringValue(), ios::out | ios::binary);
			break;
		}
		break;
	}
}


FileStream::~FileStream()
{
}

void FileStream::Close()
{
	this->file.close();
}

void FileStream::Flush()
{
	this->file.flush();
}

long FileStream::Length()
{
	long pos = 0;
	long len = 0;

	pos = this->file.tellg();

	this->file.seekg(0, this->file.end);
	len = this->file.tellg();
	this->file.seekg(pos);

	return len;
}

String FileStream::Name()
{
	return this->path;
}

long FileStream::Position()
{
	return this->file.tellp();
}

void FileStream::Position(long pos)
{
	this->file.seekg(pos, ios::beg);
}

int FileStream::Read(char * bytes, int offset, int count)
{
	int cntr = 0;
	char* buffer;

	if (bytes != nullptr) {
		// this->file.seekg(offset);
		buffer = new char[count];

		this->file.read(buffer, count);

		if (sizeof(bytes) >= (offset + count)) {
			cntr = offset;

			for (int i = 0; i < count; ++i)
			{
				bytes[cntr++] = buffer[i];
			}

			return sizeof(buffer);
		}
		else {
			cerr << "Buffer is not big enough" << endl;
		}
	}
	else {
		cerr << "Buffer is Null" << endl;
	}
}

long FileStream::Seek(long offset, SeekOrigin origin)
{
	this->file.seekg(offset, origin);

	return this->file.tellg();
}

void FileStream::Write(char * bytes, int offset, int count)
{
	char* tmp;
	int cntr = 0;

	if (sizeof(bytes) >= (offset + count)) {
		tmp = new char[count];
		cntr = offset;

		for (int i = 0; i < count; i++)
		{
			tmp[i] = bytes[cntr++];
		}

		this->file.write(tmp, count);
	}
	else {
		cerr << "Buffer is not big enough" << endl;
	}
}
