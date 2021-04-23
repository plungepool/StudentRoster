#ifndef student_h
#define student_h

#include "degree.h"

#define COURSESTOTAL 3

class Student {
    private:
        unsigned int studentId;
        string firstName;
        string lastName;
        string email;
        unsigned int age;
        unsigned int daysToComplete[COURSESTOTAL];
        DegreeProgram degreeProgram;
    public:
        //Constructor Stubs
        Student(unsigned int aStudentId, string aFirstName, string aLastName, string aEmail, unsigned int aAge, unsigned int aDaysToComplete[], DegreeProgram aDegreeProgram);
        //~Student();

        //Mutators Stubs
        void setStudentId(unsigned int aStudentId);
        void setFirstName(string aFirstName);
        void setLastName(string aLastName);
        void setEmail(string aEmail);
        void setAge(unsigned int aAge);
        void setDaysToComplete(unsigned int aDaysToComplete[]);
        void setDegreeProgram(DegreeProgram aDegreeProgram);

        //Accessors Stubs
        unsigned int getStudentId();
        string getFirstName();
        string getLastName();
        string getEmail();
        unsigned int getAge();
        unsigned int getDaysToComplete();
        DegreeProgram getDegreeProgram();

        //Print Stub
        void print();
};

#endif