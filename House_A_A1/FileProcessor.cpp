/*
Angelina House
ID: 2422726
ahouse@chapman.edu
CPSC-350-02
House_A_A1

Description:
Reads in file text and creates output html file of both untranslated and translated sentence
*/
#include "Model.h"
#include "Translator.h"
#include "FileProcessor.h"
#include <iostream>
#include <fstream>

FileProcessor::FileProcessor() {}
FileProcessor::~FileProcessor() {}

//reads input file and stores them as strings; writes html output file of original sentence and translated sentence
void FileProcessor::processFile(std::string inputFile, std::string outputFile) {

    std::string sentence;
    std::fstream my_file;
    std::string translatedSentence;
	my_file.open(inputFile, std::ios::in);

    Translator t = Translator();
    

    std::ofstream outFile("Translation.html");

     outFile << "<!DOCTYPE> <html> <head> <title> Robbers Translation </title> </head> <body>"  << std::endl;


    while(getline(my_file,sentence))
    {
        
        outFile << "<p><b>" << sentence << "</b></p>";
        translatedSentence += "<br>" + t.translateSentence(sentence) + "<br>";
 
    }
    outFile << "<p><i>" << translatedSentence << "</i></p>" << std::endl;

 

    outFile << "</body> </html>" << std::endl;


    my_file.close();

    
    outFile.close();

}

