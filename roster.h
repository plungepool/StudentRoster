#ifndef roster_h
#define roster_h

#include <string>

#include "student.h"

#define NUM_ROSTER_FIELDS 9
#define MAX_NUM_STUDENTS 10

class Roster {
    private:
        Student* classRosterArray[MAX_NUM_STUDENTS];
        int studentsInRoster;
    public:
        //Constructor/Destructor Stubs
        Roster();
        ~Roster();

        //Function Stubs
        void parse(const std::string aStudentData[], int aNumStudents, Roster* aRoster);
        void add(std::string aStudentId, std::string aFirstName, std::string aLastName, std::string aEmail, int aAge, int* aDaysToComplete, DegreeProgram aDegreeProgram);                                                           
        void remove(std::string aStudentId);
        void printAll();
        void printAverageDaysInCourse(std::string aStudentId);
        void printInvalidEmails();
        void printByDegreeProgram(DegreeProgram aDegreeProgram);

        void printAllAverageDaysInCourse();
};

#endif