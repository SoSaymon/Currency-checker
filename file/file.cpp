#include "file.h"
using json = nlohmann::json;
File::~File()
{
	if (handler.is_open())
	{
		handler.close();
	}
}

void File::save_json_to_file(const std::string& content, const std::string& date)
{
	const char* user = getenv("username");
	std::string user_str = std::string(user);
	std::string path_str = "C:\\Users\\" + user_str + "\\Documents\\Currency-checker";
	const char* path = path_str.c_str();
	_mkdir(path);
	
	try
	{
		handler.open("C:\\Users\\"+ user_str +"\\Documents\\Currency-checker\\Average-exchange-rate-"+ date +".txt", std::ios::out | std::ios::binary);
		if (handler.is_open())
		{
			auto output = json::parse(content);
			auto dump = output.dump(4);
			handler << dump;
			handler << "\n";
		}
		else
		{
			throw "ERROR! You can't open this file";
		}
	}
	catch (const std::string& e)
	{
		std::cerr << e << "\n";
	}
}
