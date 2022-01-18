#ifndef _DATE_TIME_GUARD
#define _DATE_TIME_GUARD
#include <iostream>
#include <ctime>
#include <string>
class Date_time
{
	private:
	time_t t = time(0);
	tm* time_now = gmtime(&t);
	int year, month, day, hour, day_of_week = 0;
	std::string date_to_url;

	void set_year();
	void set_month();
	void set_day();
	void set_hour();
	public:
	Date_time();
	~Date_time();
	
	void set_year(const int& year);
	void set_month(const int& month);
	void set_day(const int& day);
	bool check_if_not_weekend();
	bool check_if_not_day_off();
	void set_date_to_last_busisnes_day();
	std::string get_year();
	std::string get_month();
	std::string get_day();
	bool validate_date(const int& year, const int& month, const int& day);
	int get_hour();
	std::string make_date_to_url();
};


#endif // !_DATE_TIME_GUARD

