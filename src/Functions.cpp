#include "Functions.h"


//Menu Input
	int Functions::inputChoice()
	{
		int choice;
		string input;

		getline(cin, input);

		if(input.size() != 1)
		{
			choice = 0;
		}
		else
		{
			try
			{
				choice = stoi(input);
			}

			catch(invalid_argument e)
			{
				choice = 0;
			}
		}

		return choice;
	}

	void Functions::displaySingleEntry(list<Entries> list, int id)
	{
		bool success = false;

		for(Entries item : list)
		{
			if(item.getId() == id)
			{
				cout<<"Entry found!"<<endl<<endl;
				cout<<"Id: "<<item.getId()<<endl;
				cout<<"Name: "<<item.getName()<<endl;
				cout<<"Topic: "<<item.getTopic()<<endl;
				cout<<"Notes: "<<item.getNotes()<<endl<<endl;

				success = true;
			}
		}

		if (success == false)
		{
			cout<<"No such record has been found!"<<endl;
		}
	}

	void Functions::displaySingleEntry(list<Entries> list, string name)
	{
		bool success = false;

		for(Entries item : list)
		{
			if(!item.getName().compare(name))
			{
				cout<<"Entry found!"<<endl<<endl;
				cout<<"Id: "<<item.getId()<<endl;
				cout<<"Name: "<<item.getName()<<endl;
				cout<<"Topic: "<<item.getTopic()<<endl;
				cout<<"Notes: "<<item.getNotes()<<endl<<endl;

				success = true;
			}
		}

		if (success == false)
		{
			cout<<"No such record has been found!"<<endl;
		}
	}

	void Functions::displaySingleEntryMenu(list<Entries> list)
	{
		int id;
		int choice;
		string input;

		cout<<"1. Display an entry by id"<<endl;
		cout<<"2. Display an entry by name"<<endl;

		choice = Functions::inputChoice();

		switch(choice)
		{
			case 1:
				cout<<"Enter the id of the entry you want to display."<<endl;
				getline(cin, input);

				try
				{
					id = stoi(input);
					Functions::displaySingleEntry(list, id);
				}
				catch(invalid_argument e)
				{
					cout<<"This id is invalid!"<<endl<<endl;
					break;
				}

				break;

			case 2:
				cout<<"Enter the name of the entry you want to display."<<endl;
				getline(cin, input);

				Functions::displaySingleEntry(list, input);

				break;

			default:
				cout<<"No such choice available."<<endl<<endl;

				break;
		}

	}

//Display Entries
	void Functions::displayEntries(list<Entries> list)
	{
		if(list.size() == 0)
		{
			cout<<"Nothing to display"<<endl<<endl;
		}
		else
		{
			for(std::list<Entries>::iterator i = list.begin(); i != list.end(); i++)
			{
				cout<<"Id: "<<i->getId()<<endl;
				cout<<"Name: "<<i->getName()<<endl;
				cout<<"Topic: "<<i->getTopic()<<endl;
				cout<<"Notes: "<<i->getNotes()<<endl;
				cout<<"Deadline: "<<i->getDeadline().getFullDeadline()<<endl<<endl;
			}
		}
	}

	//Data entry and validation
	string Functions::enterData()
	{
		string input;
		bool pass = false;

		while(!pass)
		{
			std::getline(std::cin, input);

			if(input.size() <= 0)
			{
				cout<<"The field cannot be empty!"<<endl;
			}
			else
			{
				pass = true;
			}
		}

		return input;
	}

	Date Functions::enterDate()
	{
		Date newDeadline;
		string deadline;
		char delimeter = '-';

		int day;
		int month;
		int year;

		bool valid = false;
		bool bigMonth;
		bool leapYear;

		while(!valid)
		{
			valid = true;

			try
			{
				getline(cin, deadline);

				auto pos = deadline.find(delimeter);
				day = stoi(deadline.substr(0, pos));
				deadline.erase(0, pos+1);

				pos = deadline.find(delimeter);
				month = stoi(deadline.substr(0,pos));
				deadline.erase(0, pos+1);

				year = stoi(deadline);
			}
			catch(std::invalid_argument e)
			{
				cout<<"Invalid date! Enter a new deadline in dd-mm-YYYY format."<<endl;
				valid = false;
				continue;
			}

			if(month < 1 || month > 12)
			{
				cout<<"Invalid month! Enter a new deadline in dd-mm-YYYY format."<<endl;
				valid = false;
				continue;
			}

			//Check if month has 31 days
			if(month%2 == 1 || month == 8)
			{
				bigMonth = true;
			}
			else
			{
				bigMonth = false;
			}

			if(year < 1)
			{
				cout<<"Invalid year! Enter a new deadline in dd-mm-YYYY format."<<endl;
				valid = false;
				continue;
			}

			//Check if year is leap
			if(year % 4 == 0)
			{
				leapYear = true;
			}
			else
			{
				leapYear = false;
			}

			//If February
			if(month == 2 && leapYear)
			{
				if(day < 1 || day > 29)
				{
					cout<<"Invalid day! Enter a new deadline in dd-mm-YYYY format."<<endl;
					valid = false;
					continue;
				}
			}
			else if(month == 2 && !leapYear)
			{
				if(day < 1 || day > 28)
				{
					cout<<"Invalid day! Enter a new deadline in dd-mm-YYYY format."<<endl;
					valid = false;
					continue;
				}
			}
			else if(bigMonth == false)
			{
				if(day < 1 || day > 30)
				{
					cout<<"Invalid day! Enter a new deadline in dd-mm-YYYY format."<<endl;
					valid = false;
					continue;
				}
			}
			else if(bigMonth == true)
			{
				if(day < 1 || day > 31)
				{
					cout<<"Invalid day! Enter a new deadline in dd-mm-YYYY format."<<endl;
					valid = false;
					continue;
				}
			}
		}

		newDeadline.setDay(day);
		newDeadline.setMonth(month);
		newDeadline.setYear(year);

		return newDeadline;
	}

//Edit Entry
	void Functions::editEntry(list<Entries> &list)
	{
		cout<<"1. Edit entry by name."<<endl;
		cout<<"2. Edit entry by id."<<endl;

		int choice;
		int innerChoice;
		choice = Functions::inputChoice();
		bool found = false;
		string input;

		string oldName;
		string newName;
		string oldTopic;
		string newTopic;
		string oldNotes;
		string newNotes;
		Date oldDeadline;
		Date newDeadline;

		std::list<Entries>::iterator position;

		switch(choice)
		{
			case 1:
				cout<<"Enter the name of the entry you want to edit."<<endl;
				input = Functions::enterData();

				for(std::list<Entries>::iterator it = list.begin(); it != list.end(); it++)
				{
					if(!it->getName().compare(input))
					{
						cout<<"1. Edit name."<<endl;
						cout<<"2. Edit topic."<<endl;
						cout<<"3. Edit notes."<<endl;
						cout<<"4. Edit deadline."<<endl;
						cout<<"5. Edit everything."<<endl;

						innerChoice = Functions::inputChoice();

						found = true;

						switch(innerChoice)
						{
							case 1:
								cout<<"Enter the new name"<<endl;
								input = Functions::enterData();
								oldName = it->getName();
								it->setName(input);
								cout<<oldName<<" has been changed to "<<input<<endl<<endl;

								break;

							case 2:
								cout<<"Enter the new topic."<<endl;
								input = Functions::enterData();
								oldTopic = it->getTopic();
								it->setTopic(input);
								cout<<oldTopic<<" has been changed to "<<input<<endl<<endl;

								break;

							case 3:
								cout<<"Enter the new notes."<<endl;
								input = Functions::enterData();
								oldNotes = it->getNotes();
								it->setNotes(input);
								cout<<oldNotes<<" changed to "<<input<<endl<<endl;

								break;

							case 4:
								cout<<"Enter the new deadline in dd-mm-YYYY format."<<endl;
								newDeadline = Functions::enterDate();
								oldDeadline = it->getDeadline();
								it->setDeadline(newDeadline);
								cout<<oldDeadline.getFullDeadline()<<" changed to "<<it->getDeadline().getFullDeadline()<<endl<<endl;;

								break;

							case 5:
								cout<<"Enter the new name."<<endl;
								newName = Functions::enterData();
								oldName = it->getName();

								cout<<"Enter the new topic."<<endl;
								newTopic = Functions::enterData();
								oldTopic = it->getTopic();

								cout<<"Enter the new notes."<<endl;
								newNotes = Functions::enterData();
								oldNotes = it->getNotes();

								cout<<"Enter the new deadline in dd-mm-YYYY format."<<endl;
								newDeadline = Functions::enterDate();
								oldDeadline = it->getDeadline();

								it->setName(newName);
								it->setTopic(newTopic);
								it->setNotes(newNotes);
								it->setDeadline(newDeadline);

								cout<<oldName<<" has been changed to "<<newName<<endl;
								cout<<oldTopic<<" has been changed to "<<newTopic<<endl;
								cout<<oldNotes<<" has been changed to "<<newNotes<<endl;
								cout<<oldDeadline.getFullDeadline()<<" has been changed to "<<it->getDeadline().getFullDeadline()<<endl<<endl;;

								break;

							default:
								cout<<"Invalid choice."<<endl<<endl;

								break;
						}
					}

				}

				if(found == true)
					break;


				if(found == false)
				{
					cout<<"No such entry has been found!"<<endl<<endl;
				}

				break;

			case 2:
				int choice;

				cout<<"Enter the id of the entry you want to edit."<<endl;
				getline(cin, input);

				try
				{
					choice = stoi(input);
				}
				catch(invalid_argument e)
				{
					cout<<"Invalid id."<<endl<<endl;
					break;
				}

				for(std::list<Entries>::iterator it = list.begin(); it != list.end(); it++)
				{
					if(it->getId() == choice)
					{
						found = true;

						cout<<"1. Edit name."<<endl;
						cout<<"2. Edit topic."<<endl;
						cout<<"3. Edit notes."<<endl;
						cout<<"4. Edit deadline."<<endl;
						cout<<"5. Edit everything."<<endl;

						choice = Functions::inputChoice();

						switch(choice)
						{
						case 1:
								cout<<"Enter the new name"<<endl;
								input = Functions::enterData();
								oldName = it->getName();
								it->setName(input);
								cout<<oldName<<" has been changed to "<<input<<endl<<endl;

								break;

							case 2:
								cout<<"Enter the new topic."<<endl;
								input = Functions::enterData();
								oldTopic = it->getTopic();
								it->setTopic(input);
								cout<<oldTopic<<" has been changed to "<<input<<endl<<endl;

								break;

							case 3:
								cout<<"Enter the new notes."<<endl;
								input = Functions::enterData();
								oldNotes = it->getNotes();
								it->setNotes(input);
								cout<<oldNotes<<" changed to "<<input<<endl<<endl;

								break;

							case 4:
								cout<<"Enter the new deadline in dd-mm-YYYY format."<<endl;
								newDeadline = Functions::enterDate();
								oldDeadline = it->getDeadline();
								it->setDeadline(newDeadline);
								cout<<oldDeadline.getFullDeadline()<<" has been changed to "
																		<<it->getDeadline().getFullDeadline()<<endl<<endl;

								break;

							case 5:
								cout<<"Enter the new name."<<endl;
								newName = Functions::enterData();
								oldName = it->getName();

								cout<<"Enter the new topic."<<endl;
								newTopic = Functions::enterData();
								oldTopic = it->getTopic();

								cout<<"Enter the new notes."<<endl;
								newNotes = Functions::enterData();
								oldNotes = it->getNotes();

								cout<<"Enter the new deadline in dd-mm-YYYY format."<<endl;
								newDeadline = Functions::enterDate();
								oldDeadline = it->getDeadline();

								it->setName(newName);
								it->setTopic(newTopic);
								it->setNotes(newNotes);
								it->setDeadline(newDeadline);

								cout<<oldName<<" has been changed to "<<newName<<endl;
								cout<<oldTopic<<" has been changed to "<<newTopic<<endl;
								cout<<oldNotes<<" has been changed to "<<newNotes<<endl;
								cout<<oldDeadline.getDay()<<"-"<<oldDeadline.getMonth()<<"-"<<oldDeadline.getYear()<<" has been changed to "
										<<newDeadline.getDay()<<"-"<<newDeadline.getMonth()<<"-"<<newDeadline.getYear()<<endl<<endl;

								break;

							default:
								cout<<"Invalid choice."<<endl<<endl;

								break;
						}
					}

					if(found == true)
					{
						break;
					}
				}

				if(found == false)
				{
					cout<<"No such entry has been found."<<endl<<endl;
				}

				break;

			default:
				cout<<"Invalid choice."<<endl<<endl;
				break;
		}

	}


//Deleting Entries
	void Functions::deleteEntry(list<Entries> &list)
	{
		cout<<"1. Delete entry by name."<<endl;
		cout<<"2. Delete entry by id"<<endl;

		int choice = Functions::inputChoice();
		string input;

		bool found = false;

		switch(choice)
		{
			case 1:
				cout<<"Enter the name of the entry you want to delete."<<endl;
				input = Functions::enterData();

				for(std::list<Entries>::iterator it = list.begin(); it != list.end(); it++)
				{
					if(!it->getName().compare(input))
					{
						list.erase(it);
						cout<<"Element successfully deleted"<<endl<<endl;
						found = true;
					}

					if(found == true)
						break;
				}

				if(found == false)
				{
					cout<<"No such entry has beem found!"<<endl<<endl;
				}

				break;

			case 2:
				cout<<"Enter the id of the entry you want to delete."<<endl;
				getline(cin, input);
				found = false;

				try
				{
					choice = stoi(input);
				}
				catch(invalid_argument e)
				{
					cout<<"Invalid id"<<endl<<endl;
					break;
				}

				for(std::list<Entries>::iterator it = list.begin(); it != list.end(); it++)
				{
					if(it->getId() == choice)
					{
						list.erase(it);
						cout<<"Entry successfully deleted."<<endl<<endl;
						found = true;
						break;
					}
				}

				if(found == false)
				{
					cout<<"No such id found."<<endl<<endl;
				}

				break;

			default:
				cout<<"Invalid choice!"<<endl<<endl;

				break;
		}

	}

	void Functions::saveData(list<Entries> list, string filename)
	{
		string cryptid;

		ofstream writer(filename+".zom");

		if(writer.is_open())
		{

			for(Entries item : list)
			{
				writer << item.getId()<<endl;

				cryptid = item.getName();
				for(char &letter : cryptid)
				{
					letter += 1;
				}

				writer << cryptid << endl;

				cryptid = item.getTopic();
				for(char &letter : cryptid)
				{
					letter += 1;
				}

				writer << cryptid << endl;


				cryptid = item.getNotes();
				for(char &letter : cryptid)
				{
					letter += 1;
				}

				writer << cryptid << endl;

				cryptid = item.getDeadline().getFullDeadline();
				for(char &letter : cryptid)
				{
					letter += 1;
				}

				writer << cryptid << endl;
			}

			cout<<"Data successfully saved to "<<filename<<"!"<<endl<<endl;

			writer.close();
		}
		else
		{
			cout<<"Problem encountered while saving!"<<endl<<endl;
		}
	}

	void Functions::quickSave(list<Entries> list, string filename)
	{
		//In case there is no name for the save file at exit
		if(filename == "")
		{
			filename = "contests";
			cout<<"Data saving to "<<filename<<"!"<<endl;
		}

		ofstream writer(filename+".zom");

		if(writer.is_open())
		{

			string cryptid;

			for(Entries item : list)
			{
				writer << item.getId()<<endl;

				cryptid = item.getName();
				for(char &letter : cryptid)
				{
					letter += 1;
				}

				writer << cryptid << endl;

				cryptid = item.getTopic();
				for(char &letter : cryptid)
				{
					letter += 1;
				}

				writer << cryptid << endl;


				cryptid = item.getNotes();
				for(char &letter : cryptid)
				{
					letter += 1;
				}

				writer << cryptid << endl;

				cryptid = item.getDeadline().getFullDeadline();
				for(char &letter : cryptid)
				{
					letter += 1;
				}

				writer << cryptid << endl;
			}

			cout<<"Data successfully saved to "<<filename<<"!"<<endl<<endl;

			writer.close();
		}
		else
		{
			cout<<"Problem encountered while saving!"<<endl<<endl;
		}
	}

	void Functions::loadData(list<Entries> &list, string filename)
	{
		ifstream reader;
		reader.clear();

		reader.open(filename+".zom");

		if(reader.is_open())
		{
			while(reader.peek() != EOF)
			{
				string id;
				reader >> id;

				string name;
				reader >> name;

				for(char &letter : name)
				{
					letter -=1;
				}

				string topic;
				reader >> topic;

				for(char &letter : topic)
				{
					letter -=1;
				}

				string notes;
				reader >> notes;

				for(char &letter : notes)
				{
					letter -=1;
				}

				string deadline;
				reader >> deadline;

				for(char &letter : deadline)
				{
					letter -=1;
				}

				Entries entry;

				cout<<id<<endl;
				cout<<name<<endl;
				cout<<topic<<endl;
				cout<<notes<<endl;
				cout<<deadline<<endl;

				entry.setId();
				entry.setName(name);
				entry.setTopic(topic);
				entry.setNotes(notes);
				entry.setDeadline(entry.setDeadline(deadline));

				list.push_back(entry);

				//Solving the problem with the final endl getting read and starting a new cycle
				if(reader.peek() == 10)
				{
					int index = reader.tellg();
					reader.seekg(index+1);

					if(reader.peek() == EOF)
					{
						break;
					}
				}
			}
		}
		else
		{
			cout<<"Problem locating file "<<filename<<"!"<<endl<<endl;
		}

		reader.close();
	}

	void Functions::checkNearing(list<Entries> list, int currentYear, int currentMonth, int currentDay)
	{

		cout<<currentYear<<"  "<<currentMonth<<" "<<currentDay<<endl;

		for(Entries item : list)
		{
			if(item.getDeadline().getYear() - currentYear < 0)
			{
				cout<<"The contest "<<item.getName()<< " has expired and must be deleted!"<<endl;
			}
			else if(item.getDeadline().getYear() - currentYear == 0)
			{
				if(item.getDeadline().getMonth() - currentMonth <= 2)
				{
					if(item.getDeadline().getDay() - currentDay > 0)
					{
						cout<<"The contest "<<item.getName()<<" is near expiration!"<<endl;
					}
					else
					{
						cout<<"The contest "<<item.getName()<<" has expired and should be deleted!"<<endl;
					}
				}
			}
		}
	}
