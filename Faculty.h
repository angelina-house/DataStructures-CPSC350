/*
Angelina House
ID: 2422726
ahouse@chapman.edu
CPSC-350-02
House_A_A5

Description: 
Creates faculty object and functions
*/

#ifndef FACULTY_H
#define FACULTY_H
#include <string>
#include "LazyBST.h"

class Faculty {
    public:
        Faculty();
        ~Faculty();
        Faculty(const Faculty& other);
        Faculty(int facultyID, std::string name, std::string level, std::string department);
        void addStudentID(int studentID);
        void deleteStudentID(int studentID);
        void print();



        int getID();
        LazyBST<int> getStudentIDList();

        // Overloading operators
        bool operator==(const Faculty& other) const {
            return mFacultyID == other.mFacultyID;
        }

        bool operator<(const Faculty& other) const {
            return mFacultyID < other.mFacultyID;
        }

        bool operator>(const Faculty& other) const {
            return mFacultyID > other.mFacultyID;
        }

        bool operator!=(const Faculty& other) const {
            return mFacultyID != other.mFacultyID;
        }
        Faculty& operator=(const Faculty& other) {
            if (this != &other) {
                mFacultyID = other.mFacultyID;
                mName = other.mName;
                mLevel = other.mLevel;
                mDepartment = other.mDepartment;
                mStudentIDList = other.mStudentIDList;
            }
            return *this;
        }



    private:
        int mFacultyID;
        std::string mName;
        std::string mLevel;
        std::string mDepartment;
        LazyBST<int> mStudentIDList;
};

#endif