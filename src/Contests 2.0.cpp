#include <iostream>
#include <string>
#include <list>
#include <ctime>
#include "Functions.h"
#include "Entries.h"
#include "Date.h"

using namespace std;

int main() {

	//Variables
	bool runProgram = true;
	int choice;
	list<Entries> currentEntries;
	Entries entry;
	string data;
	Date enteredDeadline;
	string defaultSaveLocation;
	string filename;

	char currentYear[10];
	char currentMonth[10];
	char currentDay[10];
	time_t now = time(nullptr);
	auto localTime = localtime(&now);

	strftime(currentYear, 10, "%Y", localTime);
	strftime(currentMonth, 10, "%m", localTime);
	strftime(currentDay, 10, "%d", localTime);

	int currentYearInt = atoi(currentYear);
	int currentMonthInt = atoi(currentMonth);
	int currentDayInt = atoi(currentDay);

	//Classes
	Functions functions;

	//Code

	cout<<"Welcome to Contests 2.0"<<endl;

	while(runProgram)
	{
		cout<<"Choose an Option:"<<endl;
		cout<<"1. Create New Entry"<<endl;
		cout<<"2  Display Single Entry"<<endl;
		cout<<"3. View All Entries"<<endl;
		cout<<"4. Edit Entry"<<endl;
		cout<<"5. Delete Entry"<<endl;
		cout<<"6. Save Data"<<endl;
		cout<<"7. Load Data"<<endl;
		cout<<"8. Exit Program"<<endl;

		choice = functions.inputChoice();

		switch(choice)
		{
			case 1:

				cout<<"Enter contest name"<<endl;
				data = functions.enterData();
				entry.setName(data);

				cout<<"Enter contest topic"<<endl;
				data = functions.enterData();
				entry.setTopic(data);

				cout<<"Enter contest-related notes"<<endl;
				data = functions.enterData();
				entry.setNotes(data);

				cout<<"Enter contest deadline dd-mm-YYYY format"<<endl;
				enteredDeadline = functions.enterDate();
				entry.setDeadline(enteredDeadline);

				entry.setId();

				currentEntries.push_back(entry);

				break;

			case 2:
				functions.displaySingleEntryMenu(currentEntries);

				break;

			case 3:
				functions.displayEntries(currentEntries);

				break;

			case 4:
				functions.editEntry(currentEntries);

				break;

			case 5:
				functions.deleteEntry(currentEntries);

				break;

			case 6:
				if(currentEntries.size() > 0)
				{

					cout<<"Choose a filename for the save. This will overwrite all previous data in that file!"<<endl;
					getline(cin, filename);

					defaultSaveLocation = filename;

					functions.saveData(currentEntries, filename);
				}
				else
				{
					cout<<"There is nothing to save."<<endl<<endl;
				}

				break;

			case 7:

				cout<<"Enter the name of the file you want to load from."<<endl;
				getline(cin, filename);

				functions.loadData(currentEntries, filename);

				functions.checkNearing(currentEntries, currentYearInt, currentMonthInt, currentDayInt);

				break;

			case 8:
				runProgram = false;

				if(currentEntries.size() > 0)
				{
					functions.quickSave(currentEntries, defaultSaveLocation);
				}

				cout<<"Bye, bye!";

				break;

			default:
				cout<<"No such command available!"<<endl<<endl;

				break;
		}
	}
	return 0;
}
