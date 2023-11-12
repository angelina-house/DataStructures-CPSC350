/*
Angelina House
ID: 2422726
ahouse@chapman.edu
CPSC-350-02
House_A_A1

Description:
Defines methods model, translateSingleConsonant, translateSingleVowel
*/
#include "Model.h"
using namespace std;

Model::Model() {}
Model::~Model() {}

/* impliments translateSingleConsonant; checks if char is consonant, puncuation, 
upper case and lower case and returns finalConsonant
*/
string Model::translateSingleConsonant(char consonant) {

    string finalConsonant = "";

    if (!isalpha(consonant))
    {
        return finalConsonant += consonant;
    }
    else if (isupper(consonant))
    {
        string o = "O";
        finalConsonant = consonant + o +consonant;
        return finalConsonant;
    }
    else
    {
        string o = "o";
        finalConsonant = consonant + o + consonant;
        return finalConsonant;
    }
}

/* impliments translateSingleVowel; returns char as final vowel
*/

std::string Model::translateSingleVowel(char vowel) {
    // Implement the translation logic for vowels

    std::string finalVowel = "";
    
    /* if (isupper(vowel))
    {

    } */

    return finalVowel += vowel;

}




