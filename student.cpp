#include "student.h"

#include <iostream>
#include <string>

//Constrictor Definition
Student::Student(unsigned int aStudentId, std::string aFirstName, std::string aLastName, std::string aEmail, unsigned int aAge, unsigned int aDaysToComplete[], DegreeProgram aDegreeProgram){ //constructor
    studentId = aStudentId;
    firstName = aFirstName;
    lastName = aLastName;
    email = aEmail;
    age = aAge;
    for (int i=0; i < TOTAL_COURSES; i++) {
        daysToComplete[i] = aDaysToComplete[i];
    }
    degreeProgram = aDegreeProgram;
}

//Mutator Definitions
void Student::setStudentId(unsigned int aStudentId) {
    studentId = aStudentId;
}
void Student::setFirstName(std::string aFirstName) {
    firstName = aFirstName;
}
void Student::setLastName(std::string aLastName) {
    lastName = aLastName;
}
void Student::setEmail(std::string aEmail) {
    //set rules for email format (includes @ something)
    email = aEmail;
}
void Student::setAge(unsigned int aAge) {
    age = aAge;
}
void Student::setDaysToComplete(unsigned int aDaysToComplete[]){
    for (int i=0; i < TOTAL_COURSES; i++) {
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
std::string Student::getFirstName() {
    return firstName;
}
std::string Student::getLastName() {
    return lastName;
}
std::string Student::getEmail() {
    return email;
}
unsigned int Student::getAge() {
    return age;
}
unsigned int Student::getDaysToComplete() {
    return daysToComplete[TOTAL_COURSES];
}
DegreeProgram Student::getDegreeProgram() {
    return degreeProgram;
}

//Print Definition
void Student::print() {
    std::cout << "ID: " << studentId << std::endl
    << "Name: " << firstName << lastName << std::endl
    << "Email: " << email << std::endl
    << "Age: " << age << std::endl
    << "Days to Complete: " << daysToComplete[TOTAL_COURSES] << std::endl
    << "Degree Program: " << degreeProgram << std::endl;
} 