#include "student.h"

#include <iostream>
#include <string>

//Constrictor Definition
Student::Student(std::string aStudentId, std::string aFirstName, std::string aLastName, std::string aEmail, int aAge, int aDaysToComplete[], DegreeProgram aDegreeProgram){ //constructor
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
void Student::setStudentId(std::string aStudentId) {
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
void Student::setAge(int aAge) {
    age = aAge;
}
void Student::setDaysToComplete(int aDaysToComplete[]){
    for (int i=0; i < TOTAL_COURSES; i++) {
        daysToComplete[i] = aDaysToComplete[i];
    }
}
void Student::setDegreeProgram(DegreeProgram aDegreeProgram){
    //rules for valid program
    degreeProgram = aDegreeProgram;
}

//Accessor Definitions
std::string Student::getStudentId() {
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
int Student::getAge() {
    return age;
}
int *Student::getDaysToComplete() {
    return daysToComplete;
}
DegreeProgram Student::getDegreeProgram() {
    return degreeProgram;
}

//Print Definition
void Student::print() {
    char tab = 0x09;
    std::cout << "ID: " << studentId << tab
    << "Name: " << firstName << ' ' << lastName << tab
    << "Email: " << email << tab
    << "Age: " << age << tab
    << "Days to Complete: {" << daysToComplete[0] << ", " << daysToComplete[1] << ", " << daysToComplete[2] << "}" << tab
    << "Degree Program: ";
    switch (degreeProgram) {
        case SECURITY :
            std::cout << "Security" << std::endl;
            break;
        case NETWORK :
            std::cout << "Network" << std::endl;
            break;
        case SOFTWARE :
            std::cout << "Software" << std::endl;
            break;
        case INVALID :
            std::cout << "Not found" << std::endl;
            break;
    }
} 