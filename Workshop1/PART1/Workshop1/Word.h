/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
Full Name  : Preet Bhagyesh Patel
Student ID#: 132603226
Email      : pbpatel48@myseneca.ca
Date       : 13 september 2023

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my 
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SDDS_WORD_H
#define SDDS_WORD_H


#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>



namespace sdds {
    const int MAX_WORD_LEN = 21;

    struct Word {
        char letters[MAX_WORD_LEN];
        int count;
    };

    int searchWords(const Word words[], int num, const char word[]);
    void addWord(Word words[], int* index, const char newWord[]);
    int readWord(char* word, FILE* fptr, int maxLen);
    void title(const char* value, int len);// uses iomanip header file
    void endList();
    void totalWordsStat(int totNoWrds, int totalOverAll, int longestWord);
    void print(const Word* w, int gotoNextLine, int len);
    int findMaxLen(const Word words[], int noOfWords);
    void listWords(const Word words[], int noOfWords, const char* theTitle);
    void swap(Word* p1, Word* p2);
    void sort(Word words[], int cnt, int sortType);
    int totalCount(const Word* words, int num);
    void wordStats(const char* filename);
    void programTitle();
}

#endif 