#include "Entries.h"
#include "Functions.h"

long currentId = 0;


	void Entries::setName(string name)
	{
		this->name = name;
	}

	void Entries::setTopic(string topic)
	{
		this->topic = topic;
	}

	void Entries::setNotes(string notes)
	{
		this->notes = notes;
	}

	void Entries::setDeadline(Date deadline)
	{
		this->deadline.setYear(deadline.getYear());
		this->deadline.setMonth(deadline.getMonth());
		this->deadline.setDay(deadline.getDay());
	}

	Date Entries::setDeadline(string deadline)
	{
		char delimeter = '-';
		int day;
		int month;
		int year;

		auto pos = deadline.find(delimeter);
		day = stoi(deadline.substr(0, pos));
		deadline.erase(0, pos+1);

		pos = deadline.find(delimeter);
		month = stoi(deadline.substr(0,pos));
		deadline.erase(0, pos+1);

		year = stoi(deadline);

		Date date;

		date.setDay(day);
		date.setMonth(month);
		date.setYear(year);

		return date;
	}

	void Entries::setId()
	{
		id = currentId;
		currentId += 1;
	}


	string Entries::getName()
	{
		return name;
	}

	string Entries::getTopic()
	{
		return topic;
	}

	string Entries::getNotes()
	{
		return notes;
	}

	Date Entries::getDeadline()
	{
		return deadline;
	}

	long Entries::getId()
	{
		return id;
	}

	long Entries::getCurrentId()
	{
		return currentId;
	}






