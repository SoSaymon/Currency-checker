#include "web_handler.h"

void HTTP_con_handler::set_currency(const std::string& currency)
{
	this->currency = currency;
}

void HTTP_con_handler::make_GET_request_today()
{
	try
	{
		cpr::Response r = cpr::Get(cpr::Url {"http://api.nbp.pl/api/exchangerates/rates/a/" + currency + "/today/?format=json"});

		if (r.status_code != 200)
		{
			throw r.status_code;
		}
		text = r.text;
	}
	catch (const long& e)
	{
		std::cerr << "HTTP request returned this code: " << e << "\n";
	}
}

std::string HTTP_con_handler::get_text()
{
	return text;
}

void HTTP_con_handler::make_GET_request_with_date(const std::string& date)
{
	
	try
	{
		cpr::Response r = cpr::Get(cpr::Url {"http://api.nbp.pl/api/exchangerates/rates/a/" + currency + "/" + date + "/" + "?format=json"});

		if (r.status_code != 200)
		{
			throw r.status_code;
		}
		text = r.text;
	}
	catch (const long& e)
	{
		std::cerr << "HTTP request returned this code: " << e << "\n";
	}
}

