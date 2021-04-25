#include <iostream>
#include <string>

#include "roster.h"

Roster::Roster() {
    studentsInRoster = 0;
}

Roster::~Roster(){
    for (int i=0; i < studentsInRoster; i++) {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}

void Roster::parse(const std::string aStudentData[], int aNumStudents, Roster* aRoster) {
    for (int i=0; i < aNumStudents; i++) {
        std::string temp_arr[NUM_ROSTER_FIELDS];
        int k = 0;
        for (int j=0; j < aStudentData[i].length(); j++) {
            if (aStudentData[i][j] == ',') {
                k++;
                continue;
            }
            else {
                temp_arr[k] += aStudentData[i][j];
            }
        }
        
        int temp_age = std::stoi(temp_arr[4]);
        int temp_daystocomplete[TOTAL_COURSES] = {std::stoi(temp_arr[5]), std::stoi(temp_arr[6]), std::stoi(temp_arr[7])};

        DegreeProgram temp_degree;
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
    aRoster->add(temp_arr[0], temp_arr[1], temp_arr[2], temp_arr[3], temp_age, temp_daystocomplete, temp_degree);
    }
}

void Roster::add(std::string aStudentId, std::string aFirstName, std::string aLastName, std::string aEmail, int aAge, int* aDaysToComplete, DegreeProgram aDegreeProgram) {
    classRosterArray[studentsInRoster] = new Student(aStudentId, aFirstName, aLastName, aEmail, aAge, aDaysToComplete, aDegreeProgram);
    studentsInRoster++;
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