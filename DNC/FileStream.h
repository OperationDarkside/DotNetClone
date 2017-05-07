#include "Object.h"
#include "String.h"
#include "FileTools.h"
#include <iostream>
#include <fstream>

#pragma once

namespace dnc::IO{

	/**
	Provides methods to access and manipulate files
	*/
	class FileStream: public Object{
	public:
		/**
		Creates a new FileStream instance
		*/
		FileStream();
		//FileStream(FileStream& stream);
		/**
		Creates a new FileStream instance with a file connection

		@param path File path to the file
		@param fm FileMode how to open/create the file
		*/
		FileStream(String& path, FileMode fm);
		/**
		Creates a new FileStream instance with a file connection

		@param path File path to the file
		@param fm FileMode how to open/create the file
		@param fa Sets the Read/Write access
		*/
		FileStream(String& path, FileMode fm, FileAccess fa);
		~FileStream();

		string toString();
		string getTypeString();

		/**
		Closes the current FileStream
		*/
		void Close();
		/**
		Flushes the stream
		*/
		void Flush();
		/**
		Returns the file's size

		@return file's size
		*/
		long Length();
		/**
		Returns the file path

		@return file path
		*/
		String Name();
		/**
		Returns the current position of this file

		@return Position in this file
		*/
		long Position();
		/**
		Sets the position on the file

		@param pos Position where to Read/Write
		*/
		void Position(long pos);
		/**
		Reads a certain amount of chars/bytes into the buffer

		@param bytes Where to write the bytes to
		@param offset Where to start to write in "bytes"
		@param count How many bytes to write
		@return how many bytes where read
		*/
		int Read(char* bytes, int offset, int count);
		/**
		Sets the Read/Write position

		@param offset Position
		@param origin From where the offset position will be
		@return The position which was set
		*/
		long Seek(long offset, SeekOrigin origin);
		/**
		Writes a certain amount of chars/bytes from the buffer to the file

		@param bytes Where to write the bytes to
		@param offset Where to start to write in "bytes"
		@param count How many bytes to write
		*/
		void Write(char* bytes, int offset, int count);

	private:
		fstream& fs;
		String path;
	};
}