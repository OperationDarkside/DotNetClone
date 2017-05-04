#include <fstream>

#pragma once

enum FileMode
{
	Append,
	Create,
	CreateNew,
	Open,
	OpenOrCreate,
	Truncate
};
enum FileAccess
{
	Read = 0,
	ReadWrite = 1,
	Write = 2
};
enum SeekOrigin
{
	Begin = std::ios::beg,
	Current = std::ios::cur,
	End = std::ios::end
};