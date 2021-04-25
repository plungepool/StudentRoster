//const string studentData[] = {"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Rob,Duffy,rduffy7@wgu.edu,30,1,5,2,SOFTWARE"}

#include <iostream>
#include <string>

#include "roster.h"

Roster::Roster(const std::string aStudentData[], int aNumStudents) {
    studentsInRoster = 0;
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
        
        int temp_age = std::stoi(temp_arr[4]);
        int temp_daystocomplete[TOTAL_COURSES] = {std::stoi(temp_arr[5]), std::stoi(temp_arr[6]), std::stoi(temp_arr[7])};

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
        classRosterArray[i] = new Student(temp_arr[0], temp_arr[1], temp_arr[2], temp_arr[3], temp_age, temp_daystocomplete, temp_degree);
        studentsInRoster++;
    }
}

Roster::~Roster(){
    // delete classRosterArray;
}

void Roster::add(std::string aStudentId, std::string aFirstName, std::string aLastName, std::string aEmail, int aAge, int aDaysInCourse1, int aDaysInCourse2, int aDaysInCourse3, DegreeProgram aDegreeProgram) {
    studentsInRoster++;
    int aDaysToComplete[TOTAL_COURSES] = {aDaysInCourse1, aDaysInCourse2, aDaysInCourse3};
    classRosterArray[studentsInRoster] = new Student(aStudentId, aFirstName, aLastName, aEmail, aAge, aDaysToComplete, aDegreeProgram);
}

void Roster::remove(std::string aStudentId) {
    bool studentFound = false;
    for (int i=0; i < studentsInRoster; i++) {
        if (classRosterArray[i]->getStudentId() == aStudentId) {
            for (int j=i; j < studentsInRoster; j++) {
                classRosterArray[j] = classRosterArray[j+1];
            }
            studentFound = true;
            studentsInRoster--;
            break;
        }
    }
    if (studentFound == false) {
        std::cout << "Error: No such student ID found" << std::endl;
    }
}

void Roster::printAll() {
    for (int i=0; i < studentsInRoster; i++) {
        classRosterArray[i]->print();
    }
}

void Roster::printAverageDaysInCourse(std::string aStudentId) {
    bool studentFound = false;
    for (int i=0; i < studentsInRoster; i++) {
        if (classRosterArray[i]->getStudentId() == aStudentId) {
            int *totalDTC = classRosterArray[i]->getDaysToComplete();
            int averageDaysToComplete = (totalDTC[0]+totalDTC[1]+totalDTC[2]) / TOTAL_COURSES;
            std::cout << averageDaysToComplete << std::endl;
            studentFound = true;
            break;
        }
    }
    if (studentFound == false) {
        std::cout << "Error: No such student ID found" << std::endl;
    }
}

void Roster::printInvalidEmails() {
    for (int i=0; i < studentsInRoster; i++) {
        std::string currentEmail = classRosterArray[i]->getEmail();
        bool spaceFlag = false;
        bool atFlag = false;
        bool periodFlag = false;
        for (int j=0; j < currentEmail.length(); j++) {
            if (currentEmail[j] == ' ') {
                spaceFlag = true;
                break;
            }
            else if (currentEmail[j] == '@') {
                atFlag = true;
                continue;
            }
            else if (currentEmail[j] == '.') {
                periodFlag = true;
                continue;
            }
        }
        if (spaceFlag == true || atFlag == false || periodFlag == false) {
            std::cout << currentEmail << std::endl;
        }
    }
}

void Roster::printByDegreeProgram(DegreeProgram aDegreeProgram) {
    for (int i=0; i < studentsInRoster; i++) {
        if (classRosterArray[i]->getDegreeProgram() == aDegreeProgram) {
            classRosterArray[i]->print();
        }
    }
}

void Roster::printAllAverageDaysInCourse() {
    for (int i=0; i < studentsInRoster; i++) {
        std::string currentId = classRosterArray[i]->getStudentId();
        std::cout << currentId << ": ";
        printAverageDaysInCourse(currentId);
    }
}