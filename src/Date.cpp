#include "Date.h"

void Date::setYear(int year)
{
	this->year = year;
}

void Date::setMonth(int month)
{
	this->month = month;
}

void Date::setDay(int day)
{
	this->day = day;
}

int Date::getYear()
{
	return year;
}

int Date::getMonth()
{
	return month;
}

int Date::getDay()
{
	return day;
}

string Date::getFullDeadline()
{
	string fullDeadline;

	fullDeadline += to_string(day) + "-" + to_string(month) + "-" + to_string(year);

	return fullDeadline;
}
