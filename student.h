#ifndef student_h
#define student_h

#include <string>

#include "degree.h"

#define TOTAL_COURSES 3

class Student {
    private:
        std::string studentId;
        std::string firstName;
        std::string lastName;
        std::string email;
        int age;
        int daysToComplete[TOTAL_COURSES];
        DegreeProgram degreeProgram;
    public:
        //Constructor/Destructor Stubs
        Student(std::string aStudentId, std::string aFirstName, std::string aLastName, std::string aEmail, int aAge, int* aDaysToComplete, DegreeProgram aDegreeProgram);
        ~Student();

        //Mutators Stubs
        void setStudentId(std::string aStudentId);
        void setFirstName(std::string aFirstName);
        void setLastName(std::string aLastName);
        void setEmail(std::string aEmail);
        void setAge(int aAge);
        void setDaysToComplete(int aDaysToComplete[]);
        void setDegreeProgram(DegreeProgram aDegreeProgram);

        //Accessors Stubs
        std::string getStudentId();
        std::string getFirstName();
        std::string getLastName();
        std::string getEmail();
        int getAge();
        int *getDaysToComplete();
        DegreeProgram getDegreeProgram();

        //Print Stub
        void print();
};

#endif