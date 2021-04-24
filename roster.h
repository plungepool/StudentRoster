#ifndef roster_h
#define roster_h

//#include <iostream>
#include <string>

#include "student.h"

#define NUM_ROSTER_FIELDS 9
#define MAX_NUM_STUDENTS 10

class Roster {
    private:
        Student* classRosterArray[MAX_NUM_STUDENTS];
        unsigned int studentsInRoster;
    public:
        //Constructor Stubs
        Roster(const std::string aStudentData[], unsigned int aNumStudents);
        //~Roster();

        //Function Stubs
        void add(std::string aStudentId, std::string aFirstName, std::string aLastName, std::string aEmail, unsigned int aAge, unsigned int aDaysInCourse1, unsigned int aDaysInCourse2, unsigned int aDaysInCourse3, DegreeProgram aDegreeProgram);                                                           
        void remove(std::string aStudentId);
        void printAll();
        void printAverageDaysInCourse(std::string aStudentId);
        void printInvalidEmails();
        void printByDegreeProgram(DegreeProgram aDegreeProgram);
};

#endif