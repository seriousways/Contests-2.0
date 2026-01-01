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
	Date enterDate();
};

#endif /* FUNCTIONS_H_ */
