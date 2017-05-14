#pragma once

#ifndef FILETOOLS_H
#define FILETOOLS_H

#include <fstream>

namespace dnc{
	namespace IO{

		/**
		Collection of filemode options
		*/
		enum FileMode{
			Append,
			Create,
			CreateNew,
			Open,
			OpenOrCreate,
			Truncate
		};
		/**
		Collection of file access options
		*/
		enum FileAccess{
			Read = 0,
			ReadWrite = 1,
			Write = 2
		};

		/**
		Collection of positions in a stream
		*/
		enum SeekOrigin{
			Begin = std::ios::beg,
			Current = std::ios::cur,
			End = std::ios::end
		};
	}
}
#endif // !FILETOOLS_H