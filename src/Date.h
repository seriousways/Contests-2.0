#ifndef DATE_H_
#define DATE_H_

#include<string>

using namespace std;

class Date {

private:
	int year;
	int month;
	int day;

public:
	int getYear();
	int getMonth();
	int getDay();
	void setYear(int year);
	void setMonth(int month);
	void setDay(int day);
	string getFullDeadline();
};

#endif /* DATE_H_ */
