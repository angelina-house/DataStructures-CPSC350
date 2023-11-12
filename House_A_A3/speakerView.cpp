/*
Angelina House
ID: 2422726
ahouse@chapman.edu
CPSC-350-02
House_A_A3

Description:
Reads in file. Creates a 2D array and fills it with the file contents. 
Creates a 2D array of monoStacks and fills them with the contents of 
the 2D array. Prints the contents of the monoStacks.

*/

#include "speakerView.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
using namespace std;

speakerView::speakerView() {}

speakerView::~speakerView() {}


void speakerView::FileProcessor(string fileName) {
    string line;
    fstream inFile;
    inFile.open(fileName);
    bool foundBegin = false;
    bool foundEnd = false;
    int cols = 0;
    int rows = 0;
    double x;


    // Check if the file is open
    if (!inFile.is_open()) {
        cerr << "Error: Could not open the file." << endl;
        return;
    }


    // Read in the file and count the number of rows and columns
    while (getline(inFile, line)) {

        if (!foundBegin) {
            if (line == "BEGIN") {
                foundBegin = true;
            }
            continue;
        }


        if (line == "END") {
            foundEnd = true;
            break;
        }



        rows++;
        istringstream iss(line);
        while (iss >> x) {
            cols++;
            //cout << cols << endl;
        }
    }

    inFile.clear();
    inFile.seekg(0, ios::beg);

    int fCols = cols / rows;
    // Create the 2D array
    double** arr = new double*[rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new double[fCols];
    }

    for (int i = 0; i < rows; i++) {
        getline(inFile, line);
        istringstream ss(line);
        for (int j = 0; j < fCols; j++) {
            ss >> x;
            arr[i][j] = x;
        }
    }

    monoStack<double>** stackArr = new monoStack<double>*[fCols];
    for (int i = 0; i < fCols; i++) {
        stackArr[i] = new monoStack<double>(rows, 'd');
    }

    // Fill the stacks
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < fCols; j++) {
            stackArr[j]->push(arr[i][j]);
        }
    }

    // Print the stacks
    for (int i = 0; i < fCols; i++) {
        cout << "Column: " << i << " contains " << stackArr[i]->size() << " that are able to see. The heights of the people are ";
        while (!stackArr[i]->isEmpty()) {
            cout << stackArr[i]->pop() << " ";
        }
        cout << endl;
        delete stackArr[i];
    }

    delete[] stackArr;
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    inFile.close();
}






