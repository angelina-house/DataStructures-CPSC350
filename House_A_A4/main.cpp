/*
Angelina House
ID: 2422726
ahouse@chapman.edu
CPSC-350-02
House_A_A4

Description: 
Main method for A4. Reads in a file of DNA sequences and prints them out.
*/
#include "DnaSeq.h"
#include "DblList.h"
#include "PalindromeFinder.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) { // main method
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " input_filename" << endl;
        return 1;
    }

    ifstream inputFile(argv[1]);
    if (!inputFile.is_open()) {
        cerr << "Failed to open file: " << argv[1] << endl;
        return 1;
    }

    string line;
    DblList<DnaSeq> dnaList; // Create a doubly-linked list of DnaSeq

    while (getline(inputFile, line) && line != "END") {
        DnaSeq sequence(line);
        if (!sequence.isEmpty()) {
            //sequence.print();
            dnaList.addBack(sequence); // Add the DNA sequence to the list

        }
    }

    inputFile.close();

    // Iterate through the list
    for (int i = 0; i < dnaList.getSize(); i++) {
        DnaSeq currentSeq = dnaList.get(i);
        currentSeq.print();
    }

    return 0;
}
