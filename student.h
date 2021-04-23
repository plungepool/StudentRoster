#ifndef student_h
#define student_h

//#include <iostream>
#include <string>

#include "degree.h"

#define TOTAL_COURSES 3

class Student {
    private:
        unsigned int studentId;
        std::string firstName;
        std::string lastName;
        std::string email;
        unsigned int age;
        unsigned int daysToComplete[TOTAL_COURSES];
        DegreeProgram degreeProgram;
    public:
        //Constructor Stubs
        Student(unsigned int aStudentId, std::string aFirstName, std::string aLastName, std::string aEmail, unsigned int aAge, unsigned int aDaysToComplete[], DegreeProgram aDegreeProgram);
        //~Student();

        //Mutators Stubs
        void setStudentId(unsigned int aStudentId);
        void setFirstName(std::string aFirstName);
        void setLastName(std::string aLastName);
        void setEmail(std::string aEmail);
        void setAge(unsigned int aAge);
        void setDaysToComplete(unsigned int aDaysToComplete[]);
        void setDegreeProgram(DegreeProgram aDegreeProgram);

        //Accessors Stubs
        unsigned int getStudentId();
        std::string getFirstName();
        std::string getLastName();
        std::string getEmail();
        unsigned int getAge();
        unsigned int getDaysToComplete();
        DegreeProgram getDegreeProgram();

        //Print Stub
        void print();
};

#endif