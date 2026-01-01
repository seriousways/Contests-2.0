#ifndef ENTRIES_H_
#define ENTRIES_H_

#include<string>
#include<iostream>
#include "Date.h"

using namespace std;

class Entries {

public:
	string getName();
	string getTopic();
	string getNotes();
	Date getDeadline();
	long getId();
	void setName(string name);
	void setTopic(string topic);
	void setNotes(string notes);
	void setDeadline(Date deadline);
	Date setDeadline(string deadline);
	void setId();
	long getCurrentId();

private:
	string name;
	string topic;
	string notes;
	Date deadline;
	long id;
};

#endif /* ENTRIES_H_ */
