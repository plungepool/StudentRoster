// F.  Demonstrate the program’s required functionality by adding a main() function in main.cpp, which will 
//     contain the required function calls to achieve the following results:
// 1.  Print out to the screen, via your application, the course title, the programming language used, your 
//     WGU student ID, and your name.
// 2.  Create an instance of the Roster class called classRoster.
// 3.  Add each student to classRoster.
// 4.  Convert the following pseudo code to complete the rest of the  main() function:
// classRoster.printAll();
// classRoster.printInvalidEmails();
// //loop through classRosterArray and for each element:
// classRoster.printAverageDaysInCourse(/*current_object's student id*/);
// classRoster.printByDegreeProgram(SOFTWARE);
// classRoster.remove("A3");
// classRoster.printAll();
// classRoster.remove("A3");
// //expected: the above line should print a message saying such a student with this ID was not found.
// 5.  Implement the destructor to release the memory that was allocated dynamically in Roster.

//#include stdafx.h
#include <iostream>
#include <string>

#include "roster.h"

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
unsigned int numStudents = sizeof(studentData) / sizeof(studentData[0]);

//Print course title, language, my WGU id, and my name
std::cout << "C867 Scripting and Programming Applications, C++, 003377175, Robert Duffy" << std::endl;

std::cout << std::endl; system("pause"); return 0;
}