/*
Angelina House
ID: 2422726
ahouse@chapman.edu
CPSC-350-02
House_A_A1

Description:
Creates construsters
*/
#ifndef FILEPROCESSOR_H
#define FILEPROCESSOR_H

#include <string>

//public class that creates file processor and process file method (input strings input file name and output file name)
class FileProcessor {
public:
    FileProcessor(); 
    ~FileProcessor(); 

    void processFile(std::string inputFile, std::string outputFile);
};

#endif
