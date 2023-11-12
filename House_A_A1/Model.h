/*
Angelina House
ID: 2422726
ahouse@chapman.edu
CPSC-350-02
House_A_A1

Description:
Creates model constructor, translateSingleConsonant, translateSingleVowel
*/
#ifndef MODEL_H
#define MODEL_H

#include <string>

//public class that creates translateSingleConsonant(input char) and translateSingleVowel(input char)

class Model {
public:
    Model(); 
    ~Model(); 

    std::string translateSingleConsonant(char consonant);
    std::string translateSingleVowel(char vowel);
};

#endif






/*
#define MODEL_H

#include <string>
using namespace std;

class translateSingleConsonant{
    public: 
        translateSingleConsonant();
        translateSingleConsonant(string letter);
        virtual ~translateSingleConsonant();

        string getLetter();
        void setLetter(string letter);

       string translatedLetter();


    
        private:

        string m_letter;


};

class translateSingleVowel{
    public:
        translateSingleVowel();
        translateSingleVowel(string letter);
        virtual ~translateSingleVowel();

        string getLetter();
        void setLetter(string letter);


    private:

        string m_letter;

};

#endif */