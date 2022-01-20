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
	std::string user_str = std::string(user), currency_code, currency_svalue, buffor;
	std::string path_str = "C:\\Users\\" + user_str + "\\Documents\\Currency-checker";
	const char* path = path_str.c_str();
	double currency_value = 0;
	short i=0,j=0;
	_mkdir(path);
	
	try
	{
		handler.open("tmp.json", std::ios::out | std::ios::binary);
		if (handler.is_open())
		{
			auto output = json::parse(content);
			auto dump = output.dump(4);
			handler << dump;
			handler << "\n";
			handler.close();
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
	try
	{
		handler.open("tmp.json", std::ios::in | std::ios::binary);
		if (handler.is_open())
		{
			handler.seekg(0);
			while (!handler.eof())
			{
				std::getline(handler ,buffor);
				if (i==1)
				{
					currency_code = buffor.substr(13, 3);
				}
				else if (i == 6)
				{
					currency_svalue = buffor.substr(19, 6);
					currency_value = atof(currency_svalue.c_str());
					break;
				}
				i++;
			}
			handler.close();
		}
		else
		{
			throw "We have problem with tmp.json file";
		}
	}
	catch (const std::string& e)
	{
		std::cerr << e << "\n";
	}
	try
	{
		handler.open("C:\\Users\\" + user_str + "\\Documents\\Currency-checker\\Average-exchange-rate-" + date + ".txt", std::ios::out | std::ios::binary);
		if (handler.is_open())
		{
			handler << "Currency code: " << currency_code << "\n";
			handler << "Value: " << currency_value << "\n\n";
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
