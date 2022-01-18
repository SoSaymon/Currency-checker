#ifndef _FILE_GUARD
#define _FILE_GUARD
#include <fstream>
#include <string>
#include <vector>
#include <iostream>
#include <nlohmann/json.hpp>
#include <direct.h>
class File
{
	private:
	std::fstream handler;
	public:
	File() {};
	~File();
	void save_json_to_file(const std::string& content, const std::string& date);
};

#endif // !_FILE_GUARD
