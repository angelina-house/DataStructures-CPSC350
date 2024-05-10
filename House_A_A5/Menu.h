/*
Angelina House
ID: 2422726
ahouse@chapman.edu
CPSC-350-02
House_A_A5

Description: 
Creates menu object and functions
*/

#ifndef MENU_H
#define MENU_H
#include "Operations.h"
#include "Database.h"
#include "StudentTable.h"
#include "FacultyTable.h"
#include "Student.h"
#include "Faculty.h"
#include "iostream"

//MENU CLASS
class Menu {
    public:
        Menu();
        ~Menu();

        void play();

    private:
        Database d;
        Operations o;
};

#endif