#include <iostream>

#include <string>
#include "roster.h"


using namespace std; 

const int numStudents = 5;
static std::string studentData[numStudents] =
{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,James,Mancil,jmanci6@wgu.edu,28,5,5,50,SOFTWARE"
};

int main() 
{
	cout << "Scripting and Programming - Applications  C867 " << "C++ " << "#000577272 " << "James Mancil" << endl;

	Roster* classRoster = new Roster(numStudents);

	for (int i = 0; i < numStudents; ++i) 
	{
		classRoster->pAdd(studentData[i]); //Parsing and turning into students
	}

	cout << "Printing class roster: " << endl;
	classRoster->pAll();

	cout << "Printing invalid emails: " << endl;
	classRoster->printInvalidEmails();

	cout << "Printing average course days for each sutdent: " << endl; //Looping classRosterArray and printing average course days
	for (int i = 0; i <= numStudents; ++i)
	{
		classRoster->printAverageDays("A" + to_string(i));
		cout << endl;
	}

	 
	classRoster->printByDegreetype(SOFTWARE); //Printing software students
	cout << endl;

	
	classRoster->remove("A3");  //Removing A3
	cout << endl;

	classRoster->pAll(); //Printing after removal to demonstrate remove fuction functionality

	classRoster->remove("A3"); //Attempting to remove A3 a second time to demonstrate the ID was not found

	classRoster->~Roster(); //Decon


	system("pause");
}

