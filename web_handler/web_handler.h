#ifndef _WEB_HANDLER_GUARD
#define _WEB_HANDLER_GUARD
#include <cpr/cpr.h>
#include <string>
#include <iostream>
#include <vector>
class HTTP_con_handler
{
	private:
	std::string currency;
	std::string text;
	public:
	HTTP_con_handler() {};
	~HTTP_con_handler() {};
	void set_currency(const std::string& currency);
	void make_GET_request_today();
	std::string get_text();
	void make_GET_request_with_date(const std::string& date);
	
};
#endif // !_WEB_HANDLER_GUARD

