/*
Angelina House
ID: 2422726
ahouse@chapman.edu
CPSC-350-02
House_A_A5

Description: 
Creates student object and functions
*/

#ifndef STUDENT_H
#define STUDENT_H
#include <string>

//STUDENT CLASS
class Student {
    public:
        Student();
        ~Student();
        Student(const Student& other);
        Student(int studentID, std::string name, std::string level, std::string major, double GPA, int facultyID);

        int getID();
        void setFacultyID(int facultyID);
        int getFacultyID();



        void print();        
        // Overloading operators
        bool operator==(const Student& other) const {
            return mStudentID == other.mStudentID;
        }

        bool operator<(const Student& other) const {
            return mStudentID < other.mStudentID;
        }

        bool operator>(const Student& other) const {
            return mStudentID > other.mStudentID;
        }

        bool operator!=(const Student& other) const {
            return mStudentID != other.mStudentID;
        }

        Student& operator=(const Student& other) {
            if (this != &other) { // Check for self-assignment
                mStudentID = other.mStudentID;
                mName = other.mName;
                mLevel = other.mLevel;
                mMajor = other.mMajor;
                mGPA = other.mGPA;
                mFacultyID = other.mFacultyID;
            }
            return *this;
        }


    private:
        int mStudentID;
        std::string mName;
        std::string mLevel;
        std::string mMajor;
        double mGPA;
        int mFacultyID;
};

#endif