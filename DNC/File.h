#pragma once

#ifndef FILE_H
#define FILE_H

//#include "Object.h"
#include "String.h"
#include "FileStream.h"

namespace dnc{
	namespace IO{

		/**
		Method collection for interaction with the file system
		*/
		class File: public Object{
		public:
			~File();

			/**
			Adds the given lines to a file

			@param path Address to the file
			@param contents List of strings to add
			*/
			void AppenAllLines(String& path, Collections::Generic::List<String> contents);
			/**
			Adds the given string to a file

			@param path Address to the file
			@param contents String to write
			*/
			void AppenAllText(String& path, String& contents);
			/**
			Returns a FileStream for the file with the given path

			@param path Address to the file
			*/
			FileStream AppendText(String& path);
			/**
			Copys the contents of the source file, creates a new file and writes the contents to it

			@param sourceFileName Address to the source file
			@param destFileName Address to the destination file
			*/
			void Copy(String& sourceFileName, String& destFileName);
			/**
			NIY --- Copys the contents of the source file, creates a new file and writes the contents to it

			@param sourceFileName Address to the source file
			@param destFileName Address to the destination file
			@overwrite If the destination should be overwritten if already existing
			*/
			void Copy(String& sourceFileName, String& destFileName, bool overwrite);
			/**
			Creates a new file and returns its FileStream

			@param path Address to the file
			*/
			FileStream Create(String& path);
			/**
			Checks if the given file exists

			@param path Address to the file
			*/
			bool Exists(String& path);
			/**
			NIY --- Moves the file from source to destination, deleting the source

			@param sourceFileName Address to the source file
			@param destFileName Address to the destination file
			*/
			void Move(String& sourceFileName, String& destFileName);
			/**
			Returns the files contents of the given filepath

			@param path Address to the file
			*/
			char* ReadAllBytes(String& path);
			/**
			Reads the files contents of the given filepath and returns its lines

			@param path Address to the file
			*/
			Collections::Generic::List<String> ReadAllLines(String& path);
			/**
			Returns the files contents of the given filepath

			@param path Address to the file
			*/
			String ReadAllText(String& path);
			/**
			Writes the bytes to the given file

			@param path Address to the file
			*/
			void WriteAllBytes(String& path, char* bytes);
			/**
			Writes the lines to the given file

			@param path Address to the file
			*/
			void WriteAllLines(String& path, Collections::Generic::List<String> contents);
			/**
			Writes the string to the given file

			@param path Address to the file
			*/
			void WriteAllText(String& path, String& contents);
		private:
			File();
		};
	}
}
#endif // !FILE_H