#include "date_time.h"

void Date_time::set_year()
{
	year = time_now->tm_year;
	year = year + 1900;
}

void Date_time::set_month()
{
	month = time_now->tm_mon;
	month += 1;
}

void Date_time::set_day()
{
	day = time_now->tm_mday;
}

void Date_time::set_hour()
{	
	hour = time_now->tm_hour;
}

bool Date_time::check_if_not_weekend()
{
	day_of_week = time_now->tm_wday;

	if (day_of_week == 0) 
	{
		day =- 2;
		std::cout << "Today is Sunday, printing data from: " << day << " " << month << " " << year << "\n";
		return true;
	}
	else if (day_of_week == 6)
	{
		day -= 1;
		std::cout << "Today is Saturday, printing data from: " << day << " " << month << " " << year << "\n";
		return true;
	}
	return false;
	
}

bool Date_time::check_if_not_day_off()
{
	if ((day == 1) && (month == 1))
	{
		day = 31;
		month = 12;
		year -= 1;
		std::cout << "Today is a public holiday, printing data from: " << day << " " << month << " " << year << "\n";
		return true;
	}
	else if ((day == 6) && (month == 1))
	{
		day -= 1;
		std::cout << "Today is a public holiday, printing data from: " << day << " " << month << " " << year << "\n";
		return true;
	}
	else if (((day == 17) && (month == 4)) || ((day == 18) && (month == 4)))
	{
		day = 15;
		std::cout << "Today is a public holiday, printing data from: " << day << " " << month << " " << year << "\n";
		return true;
	}
	else if ((day == 1) && (month == 5))
	{
		day = 29;
		month = 4;
		std::cout << "Today is a public holiday, printing data from: " << day << " " << month << " " << year << "\n";
		return true;
	}
	else if ((day == 3) && (month == 5))
	{
		day -= 1;
		std::cout << "Today is a public holiday, printing data from: " << day << " " << month << " " << year << "\n";
		return true;
	}
	else if ((day == 5) && (month == 6))
	{
		day = 3;
		std::cout << "Today is a public holiday, printing data from: " << day << " " << month << " " << year << "\n";
		return true;
	}
	else if ((day == 16) && (month == 6))
	{
		day -= 1;
		std::cout << "Today is a public holiday, printing data from: " << day << " " << month << " " << year << "\n";
		return true;
	}
	else if ((day == 15) && (month == 8))
	{
		day = 12;
		std::cout << "Today is a public holiday, printing data from: " << day << " " << month << " " << year << "\n";
		return true;
	}
	else if ((day == 1) && (month == 11))
	{
		day = 31;
		month = 10;
		std::cout << "Today is a public holiday, printing data from: " << day << " " << month << " " << year << "\n";
		return true;
	}
	else if ((day == 11) && (month == 11))
	{
		day -= 1;
		std::cout << "Today is a public holiday, printing data from: " << day << " " << month << " " << year << "\n";
		return true;
	}
	else if (((day == 25) && (month == 12)) || ((day == 26) && (month == 12)))
	{
		day = 23;
		std::cout << "Today is a public holiday, printing data from: " << day << " " << month << " " << year << "\n";
		return true;
	}
	return false;
}

void Date_time::set_date_to_last_busisnes_day()
{
	if (!((check_if_not_day_off()) || (check_if_not_weekend())))
	{
		if (day == 1)
		{
			if ((day == 1) && (month == 3))
			{
				if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
				{
					day = 29;
					month = 2;
					check_if_not_day_off();
					check_if_not_weekend();
				}
				else
				{
					day = 28;
					month = 2;
					check_if_not_day_off();
					check_if_not_weekend();
				}
			}
			else if (month % 2 == 0)
			{
				day = 30;
				month -= 1;
				check_if_not_day_off();
				check_if_not_weekend();
			}
			else
			{
				day = 31;
				month -= 1;
				check_if_not_day_off();
				check_if_not_weekend();
			}
		}
		else
		{
			day -= 1;
			check_if_not_day_off();
			check_if_not_weekend();
		}
	}
}

Date_time::Date_time()
{
	set_year();
	set_month();
	set_day();
	set_hour();
}

Date_time::~Date_time()
{}

void Date_time::set_year(const int& year)
{
	this->year = year;
}

void Date_time::set_month(const int& month)
{
	this->month = month;
}

void Date_time::set_day(const int& day)
{
	this->day = day;
}

std::string Date_time::get_year()
{
	std::string string_year = std::to_string(year);
	return string_year;
}

std::string Date_time::get_month()
{
	std::string string_month = std::to_string(month);
	return string_month;
}

std::string Date_time::get_day()
{
	std::string string_day = std::to_string(day);
	return string_day;
}

bool Date_time::validate_date(const int& year, const int& month, const int& day)
{
	if (year > this->year)
	{
		return false;
	}
	else if (year < this->year)
	{
		return true;
	}
	else if (year == this->year)
	{
		if (month > this->month)
		{
			return false;
		}
		else if (month < this->month)
		{
			return true;
		}
		else if (month == this->month)
		{
			if (day < this->day)
			{
				return true;
			}
			else if (day > this->day)
			{
				return false;
			}
			else if (day == this->day)
			{
				return true;
			}
		}
	}
	return false;
}

int Date_time::get_hour()
{
	return hour;
}

std::string Date_time::make_date_to_url()
{
	if (month <= 10)
	{
		if (day < 10)
		{
			date_to_url = std::to_string(year) + "-0" + std::to_string(month) + "-0" + std::to_string(day);
		}
		else
		{
			date_to_url = std::to_string(year) + "-0" + std::to_string(month) + "-" + std::to_string(day);
		}
	}
	else
	{
		if (day < 10)
		{
			date_to_url = std::to_string(year) + "-0" + std::to_string(month) + "-0" + std::to_string(day);
		}
		else
		{
			date_to_url = std::to_string(year) + "-" + std::to_string(month) + "-" + std::to_string(day);
		}
	}
	return date_to_url;
}
