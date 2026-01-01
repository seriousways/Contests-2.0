#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <list>
#include "Entries.h"
#include "Date.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Functions {
public:
	int inputChoice();
	string enterData();
	void displayEntries(list<Entries> list);
	void deleteEntry(list<Entries> &list);
	void editEntry(list<Entries> &list);
	void saveData(list<Entries> list, string filename);
	void quickSave(list<Entries> list, string filename);
	void loadData(list<Entries>&list, string filename);
	void checkNearing(list<Entries> list, int currentYear, int currentMonth, int currentDay);
	void displaySingleEntry(list<Entries> list, int id);
	void displaySingleEntry(list <Entries> list, string name);
	void displaySingleEntryMenu(list<Entries> list);
	Date enterDate();
};

#endif /* FUNCTIONS_H_ */
