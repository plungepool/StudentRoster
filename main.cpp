// 2.  Create a student object for each student in the data table and populate classRosterArray.
// a.  Parse each set of data identified in the “studentData Table.”
// b.  Add each student object to classRosterArray.
// don't use contructor and move all that to the add function? and a parse function?
// The add(…) method is not used.
// Some students do not use the add method to add Student objects to the Roster because they simply 
// point the array of pointers at the new object using a particular index.  In this sense the add 
// method is rather superfluous, but it is necessary, and the workaround is simple.

// The printout does not do output using accessors.
// Students don’t use the accessors because they simply call the print() method, which does not use 
// accessors because the print() method is already a member of the Student class.  The clear solution 
// is to use getters in the print() method, or to call the accessors directly from main for that printout.

#include <iostream>
#include <string>

#include "roster.h"
#include "roster.cpp"
#include "student.h"
#include "student.cpp"

int main()
{
//Initialize StudentData
const std::string studentData[] =
{
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", 
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", 
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", 
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
    "A5,Rob,Duffy,rduffy7@wgu.edu,30,1,5,2,SOFTWARE"
};
//Find number of students in roster for use later
int numStudents = sizeof(studentData) / sizeof(studentData[0]);

//Print course title, language, my WGU id, and my name
std::cout << "C867 Scripting and Programming Applications, C++, 003377175, Robert Duffy" << std::endl << std::endl;

//Initialize roster
Roster* classRoster = new Roster;

//Parse and populate
classRoster->parse(studentData, numStudents, classRoster);

std::cout << "Class Roster:" << std::endl;
classRoster->printAll();

std::cout << std::endl << "Invalid email addresses:" << std::endl;
classRoster->printInvalidEmails();

std::cout << std::endl << "All students' average days in courses, by ID:" << std::endl;
classRoster->printAllAverageDaysInCourse();

std::cout << std::endl << "List of Software students:" << std::endl;
classRoster->printByDegreeProgram(SOFTWARE);

std::cout << std::endl << "Removing student A3..." << std::endl;
classRoster->remove("A3");
std::cout << std::endl << "Updated roster:" << std::endl;
classRoster->printAll();

std::cout << std::endl << "Removing student A3 again..." << std::endl;
classRoster->remove("A3");

delete classRoster;

std::cout << std::endl; system("pause"); exit (0);
}