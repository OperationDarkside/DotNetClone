#include <fstream>

#pragma once

enum FileMode
{
	Append = 0,
	Create = 1,
	CreateNew = 2,
	Open = 3,
	OpenOrCreate = 4,
	Truncate = 5
};

enum FileAccess
{
	Read = 0,
	ReadWrite = 1,
	Write = 2
};

enum SeekOrigin
{
	Begin = ios::beg,
	Current = ios::cur,
	End = ios::end
};