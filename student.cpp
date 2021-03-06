#include "student.h"

#include <iostream>
#include <string>

//Constrictor Definition
Student::Student(std::string aStudentId, std::string aFirstName, std::string aLastName, std::string aEmail, int aAge, int* aDaysToComplete, DegreeProgram aDegreeProgram){ //constructor
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

//Destructor Definition
Student::~Student(){
    //No destructors needed
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
    int print_DaysToComplete[TOTAL_COURSES];
    char tab = 0x09;
    std::cout << "ID: " << getStudentId() << tab
    << "Name: " << getFirstName() << ' ' << getLastName() << tab
    << "Email: " << getEmail() << tab
    << "Age: " << getAge() << tab
    << "Days to Complete: {" << getDaysToComplete()[0] << ", " << getDaysToComplete()[1] << ", " << getDaysToComplete()[2] << "}" << tab
    << "Degree Program: ";
    switch (getDegreeProgram()) {
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