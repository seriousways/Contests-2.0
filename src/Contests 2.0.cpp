#include <iostream>
using namespace std;

int main() {
	cout<<"Welocme to Contests 2.0"<<endl;

	bool runProgram = true;

	int a;

	while(runProgram)
	{
		cout<<"Choose an Option:"<<endl;
		cout<<"1. Create New Entry"<<endl;
		cout<<"2. View All Entries"<<endl;
		cout<<"3. Edit Entry"<<endl;
		cout<<"4. Delete Entry"<<endl;
		cout<<"5. Exit Program"<<endl;

		cin>>a;
		if (a == 5)
			runProgram = false;
	}
	return 0;
}
