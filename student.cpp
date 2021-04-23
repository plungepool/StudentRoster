#include "student.h"

#include <iostream>
#include <string>
using namespace std;

//Constrictor Definition
Student::Student(unsigned int aStudentId, string aFirstName, string aLastName, string aEmail, unsigned int aAge, unsigned int aDaysToComplete[], DegreeProgram aDegreeProgram){ //constructor
    studentId = aStudentId;
    firstName = aFirstName;
    lastName = aLastName;
    email = aEmail;
    age = aAge;
    for (int i=0; i < COURSESTOTAL; i++) {
        daysToComplete[i] = aDaysToComplete[i];
    }
    degreeProgram = aDegreeProgram;
}

//Mutator Definitions
void Student::setStudentId(unsigned int aStudentId) {
    studentId = aStudentId;
}
void Student::setFirstName(string aFirstName) {
    firstName = aFirstName;
}
void Student::setLastName(string aLastName) {
    lastName = aLastName;
}
void Student::setEmail(string aEmail) {
    //set rules for email format (includes @ something)
    email = aEmail;
}
void Student::setAge(unsigned int aAge) {
    age = aAge;
}
void Student::setDaysToComplete(unsigned int aDaysToComplete[]){
    for (int i=0; i < COURSESTOTAL; i++) {
        daysToComplete[i] = aDaysToComplete[i];
    }
}
void Student::setDegreeProgram(DegreeProgram aDegreeProgram){
    //rules for valid program
    degreeProgram = aDegreeProgram;
}

//Accessor Definitions
unsigned int Student::getStudentId() {
    return studentId;
}
string Student::getFirstName() {
    return firstName;
}
string Student::getLastName() {
    return lastName;
}
string Student::getEmail() {
    return email;
}
unsigned int Student::getAge() {
    return age;
}
unsigned int Student::getDaysToComplete() {
    return daysToComplete[COURSESTOTAL];
}
DegreeProgram Student::getDegreeProgram() {
    return degreeProgram;
}

//Print Definition
void Student::print() {
    cout << "ID: " << studentId << endl
    << "Name: " << firstName << lastName << endl
    << "Email: " << email << endl
    << "Age: " << age << endl
    << "Days to Complete: " << daysToComplete[COURSESTOTAL] << endl
    << "Degree Program: " << degreeProgram << endl;
} 