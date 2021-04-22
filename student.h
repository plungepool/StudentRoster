#ifndef student_h
#define student_h

// #include <string>
// using namespace std;

#include "degree.h"

//function prototypes in header as part of class?
//function definitions in .cpp file?

// D.  For the Student class, do the following:
// 1.  Create the class Student  in the files student.h and student.cpp, which includes each of the
//     following variables:
// •  student ID
// •  first name
// •  last name
// •  email address
// •  age
// •  array of number of days to complete each course
// •  degree program

class Student {
    private:
        int studentId;
        string firstName;
        string lastName;
        string email;
        int age;
        int daysToComplte[];
        int degreeProgram; //reference enum data type??
    public:
        Student(int aStudentId, string aFirstName){ //constructor
        studentId = aStudentId;
        firstName = aFirstName;
        //etc
        //function is called every time object is created
        //can be used to create default initialization values
        }

        void setEmail(string aEmail) { //setter/mutator
            //set rules for email format (includes @ something)
        }
        void getEmail() { //getter/accessor
            return email;
        }

        // void print() {
        //     cout << studentId << ", " << firstName << ", " << endl;
        // } 
};

#endif