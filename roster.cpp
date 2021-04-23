// Note: A valid email should include an at sign ('@') and period ('.') and should not include a space (' ').
// f.  public void printByDegreeProgram(DegreeProgram degreeProgram) that prints out student information for 
//     a degree program specified by an enumerated type.

//const string studentData[] = {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Rob,Duffy,rduffy7@wgu.edu,30,1,5,2,SOFTWARE"}

#include <iostream>
#include <string>

#include "roster.h"

Roster::Roster(const std::string aStudentData[], unsigned int aNumStudents) {
    for (int i=0; i < aNumStudents; i++) {
        std::string temp_arr[NUM_ROSTER_FIELDS];
        int k = 0;
        for (int j=0; j < aStudentData[i].length(); j++) { //for each character in string
            if (aStudentData[i][j] == ',') { //if comma, skip it
                k++; //and start new temp_arr string
                continue;
            }
            else {
                temp_arr[k] += aStudentData[i][j]; //if other, append to current str
            }
        }

        DegreeProgram temp_degree; //temp enum to parse degree to enmerated data
        if (temp_arr[8] == "NETWORK") {
            temp_degree = NETWORK;
        }
        else if (temp_arr[8] == "SECURITY") {
            temp_degree = SECURITY;
        }
        else if (temp_arr[8] == "SOFTWARE") {
            temp_degree = SOFTWARE;
        }
        else { 
            temp_degree = INVALID;
        }
        //classRosterArray.add student to the roster
    }
}

void Roster::add(std::string aStudentId, std::string aFirstName, std::string aLastName, std::string aEmail, int aAge, int aDaysInCourse1, int aDaysInCourse2, int aDaysInCourse3, DegreeProgram aDegreeProgram) {

}                                                           
// a.  public void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, 
// int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram)  that sets the instance variables from part D1 and updates the roster.

void Roster::remove(std::string aStudentId) {

}
// b.  public void remove(string studentID)  that removes students from the roster by student ID. If the student ID does not exist, 
// the function prints an error message indicating that the student was not found.

void Roster::printAll() {

}
// c. public void printAll() that prints a complete tab-separated list of student data in the provided format: 
// A1 [tab] First Name: John [tab] Last Name: Smith [tab] Age: 20 [tab]daysInCourse: {35, 40, 55} Degree Program: Security. 
// The printAll() function should loop through all the students in classRosterArray and call the print() function for each student.

void Roster::printAverageDaysInCourse(std::string aStudentId) {

}
// d.  public void printAverageDaysInCourse(string studentID)  that correctly prints a student’s average number of days 
// in the three courses. The student is identified by the studentID parameter.

void Roster::printInvalidEmails() {

}
// e.  public void printInvalidEmails() that verifies student email addresses and displays all invalid email addresses to the user.
