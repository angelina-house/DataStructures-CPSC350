/*
Angelina House
ID: 2422726
ahouse@chapman.edu
CPSC-350-02
House_A_A1

Description:
Defines methods, isvowel, translateWord, translateSentence
*/
#include <iostream>
#include "Model.h"
#include "Translator.h"
#include "FileProcessor.h"
using namespace std;

Translator::Translator() {}

Translator::~Translator() {}

//checks if character (input char) is a vowel or not; returns true or false
bool Translator::isVowel(char c)
{
    
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || 
    c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' )
    {
        return true;
    }
    return false;
}

//translates singular word from sentence (input string word; checks if vowel and will either call translate vowel or consonant method
//returns translated word
string Translator::translateWord(string word) 
{
    Model m;


    string translatedWord = "";
    

    for (int i = 0; i < word.size(); ++i)
    {
        if (isVowel(word[i]) == true)
        {
            translatedWord = translatedWord + m.translateSingleVowel(word[i]);
        }
        else if (isVowel(word[i]) == false)
        {
            translatedWord = translatedWord + m.translateSingleConsonant(word[i]);
        }
        else
        {
            translatedWord += word[i];
        }
        
    }
    return translatedWord;
}

//breaks down sentence (input string sentence) word to word to be translated with translate word above
// returns translated sentence
std::string Translator::translateSentence( std::string sentence) 
{

    std::string translatedSentence = "";
    std::string wordBreak;

    for (int i = 0; i < sentence.size(); i++)
    {
        if (sentence[i] !=  ' ')
        {
            wordBreak += sentence[i];
        }
        else
        {
            translatedSentence += translateWord(wordBreak);
            wordBreak = ' ';
        }
        
    }

    translatedSentence += translateWord(wordBreak);

    return translatedSentence;
}
