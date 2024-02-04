/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #6 (P1)
Full Name  : Preet Bhagyesh Patel
Student ID#: 132603226
Email      : pbpatel48@myseneca.ca
Date       : 16 september 2023

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/


#define _CRT_SECURE_NO_WARNINGS

#include "Phone.h"
#include "cStrTools.h"

#include<iostream>

using namespace std;
namespace sdds {

    void phoneDir(const char* nameDir, const char* filename) {
        
        printf("%s phone direcotry search\n", nameDir);
        printf("-------------------------------------------------------\n");

        struct Person person[100];

        int i = 0;

        //reading data from the file
        FILE* file;
        file = fopen(filename, "r");
        if (file != NULL) {
            while (fscanf(file, "%[^\t]\t%s\t%s\t%s\n", person[i].name, person[i].area, person[i].num1, person[i].num2) != EOF) {
                i++;
            }
       
            fclose(file);

            char userInput[50];
            
            //getting user input for the name of the person in the directory
            do {
                cout << "Enter a partial name to search (no spaces) or enter '!' to exit" << endl;
                cout << "> ";
                cin >> userInput;

                if (userInput[0] == '!') {
                    cout << "Thank you for using " << nameDir << " directory." << endl;
                    
                }
                

                
                
                for (int j = 0; j < i; j++) {
                    char lowercaseName[50];
                    //converting the user inputed name and the name stored in the data files
                    //both in lower case so we can compare them
                    toLowerCaseAndCopy(lowercaseName, person[j].name);
                    toLowerCaseAndCopy(userInput, userInput);
                    
                    //using the strStr functin to compare the userinput and the names in data file
                    if (strStr(lowercaseName, userInput) != NULL) {
                        cout << person[j].name << ": (" << person[j].area << ") " << person[j].num1 << "-" << person[j].num2 << endl;

                        
                    }
                }

               
            } while (userInput[0] != '!');
        }
        else {
            cout << filename << " file not found!" << endl;
            cout << "Thank you for using " << nameDir << " directory." << endl;



           
        }
    }
}
