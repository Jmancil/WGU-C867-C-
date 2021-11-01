#include "roster.h"
#include <vector>
#include <string>

using namespace std; 

const int numStudents = 5;
string studentData[numStudents] =
{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,James,Mancil,jmanci6@wgu.edu,28,5,5,50,SOFTWARE"
};

Roster::Roster(int capacity) //full con 
{
	this->capacity = capacity;
	this->lastIndex = -1;
	this->classRosterArray = new Student *[capacity];
}


Roster::Roster() // Empty con
{
	this->capacity = 0;
	this->lastIndex = -1;
	this->classRosterArray = nullptr;
}


void Roster::pAdd(string row)

	{
		if (lastIndex < capacity)
		{
			lastIndex++;

			int tArray[Student::courseDaysSize];

			if (row.back() == 'Y')
			{
				this->classRosterArray[lastIndex] = new Student();
				classRosterArray[lastIndex]->setDegreeType(DegreeType::SECURITY);
			}
			else if (row.back() == 'K')
			{
				this->classRosterArray[lastIndex] = new Student();
				classRosterArray[lastIndex]->setDegreeType(DegreeType::NETWORK);
			}
			else if (row.back() == 'E')
			{
				this->classRosterArray[lastIndex] = new Student();
				classRosterArray[lastIndex]->setDegreeType(DegreeType::SOFTWARE);
			}
			else if (row.back() == 'D')
			{
				this->classRosterArray[lastIndex] = new Student();
				classRosterArray[lastIndex]->setDegreeType(DegreeType::UNDECIDED);
			}
			else
			{
				std::cerr << "Invalid degree type, exiting now...\n";
				exit(-1);
			}

			//Set ID
			int rhs = studentData[lastIndex].find(",");
			classRosterArray[lastIndex]->setStudentID(studentData[lastIndex].substr(0, rhs));

			//Set First Name
			int lhs = rhs + 1;
			rhs = studentData[lastIndex].find(",", lhs);
			classRosterArray[lastIndex]->setFName(studentData[lastIndex].substr(lhs, rhs - lhs));

			//Set Last Name
			lhs = rhs + 1;
			rhs = studentData[lastIndex].find(",", lhs);
			classRosterArray[lastIndex]->setLname(studentData[lastIndex].substr(lhs, rhs - lhs));

			//Set Email Address
			lhs = rhs + 1;
			rhs = studentData[lastIndex].find(",", lhs);
			classRosterArray[lastIndex]->setEAddress(studentData[lastIndex].substr(lhs, rhs - lhs));

			//Set Age
			lhs = rhs + 1;
			rhs = studentData[lastIndex].find(",", lhs);
			classRosterArray[lastIndex]->setSAGE(studentData[lastIndex].substr(lhs, rhs - lhs));

			//Set Days to Complete
			lhs = rhs + 1;
			rhs = studentData[lastIndex].find(",", lhs);
			tArray[0] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

			//Set Days to Complete
			lhs = rhs + 1;
			rhs = studentData[lastIndex].find(",", lhs);
			tArray[1] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

			//Set Days to Complete
			lhs = rhs + 1;
			rhs = studentData[lastIndex].find(",", lhs);
			tArray[2] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

			//Set all of the Days
			classRosterArray[lastIndex]->setCourseDays(tArray);
		}
		else
		{
			std::cerr << "List at capacity";
			exit(-1);
		}

	}

void Roster::printAverageDays(string studentID) // printing average days based on sutdentID
{
	bool found = false;
	for (int i = 0; i <= lastIndex; ++i)
	{
		if (this->classRosterArray[i]->getStudentID() == studentID)
		{
			found = true;
			int* days = classRosterArray[i]->getCourseDays();
			cout << "Average course days for student " << studentID << " is: " << (days[0] + days[1] + days[2]) / 3 << endl;

		}
	}
	
}


void Roster::remove(string studentID) 
{ //Removing student based on ID also moves array items to fill space
	cout << "Removing student based on  ID: " << studentID  << endl;

	bool isFound = false;
	for (int i = 0; i < numStudents; i++) {
		if (classRosterArray[i]->getStudentID() == studentID) {
			
			isFound = true;
			delete this->classRosterArray[i];
			
			
			this->lastIndex--;

			for (int j = i; j <= this->lastIndex; j++) { //Moves Array items
				classRosterArray[j] = classRosterArray[j + 1];
				
			}
		}
	}
	if (!isFound)
	{
		cout << "No student found with this ID: " << studentID << endl;
	}
}



void Roster::pAll() // print all
{
	for (int i = 0; i <= this->lastIndex; ++i)
	{
		(this->classRosterArray)[i]->print();
	}
}

void Roster::printByDegreetype(DegreeType d) // Degree type print
{
	cout << "Printing by degree type" << DegreeTypeStrings[d] << endl;
	for (int i = 0; i <= lastIndex; ++i) {
		if (this->classRosterArray[i]->getDegreeType() == d)
		{
			classRosterArray[i]->print();
		}
	}
}

void Roster::printInvalidEmails() { // find and print invalid emails
	
	for (int i = 0; i <= this->lastIndex; i++) {
		string invEmailCheck = classRosterArray[i]->getEAddress();

		
		if (invEmailCheck.find('@') == string::npos) {
			cout << invEmailCheck <<  endl;
			continue;
		}
		
		else if (invEmailCheck.find('.') == string::npos) {
			cout << invEmailCheck  << endl;
			continue;
		}
		
		else if (invEmailCheck.find(' ') != string::npos) {
			cout << invEmailCheck << endl;
			continue;
		}

	}
}

Roster::~Roster()
{
	for (int i = 0; i <= lastIndex; ++i)
	{
		delete this->classRosterArray[i];
	}
	delete classRosterArray;
}
