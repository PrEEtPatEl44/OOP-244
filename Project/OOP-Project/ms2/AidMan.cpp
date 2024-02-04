/*/////////////////////////////////////////////////////////////////////////
                          Milestone: 2
Full Name  : Preet Bhagyesh Patel
Student ID#: 132603226
Email      : pbpatel48@myseneca.ca
Date       : 15 November 2023

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#define _CRT_SECURE_NO_WARNINGS
#include "AidMan.h"
#include "Utils.h"
#include"Menu.h"
#include"Date.h"
#include <iostream>
using namespace std;
#include <cstring>
namespace sdds {
    AidMan::AidMan(const char* filename) : mainMenu("List Items\tAdd Item\tRemove Item\tUpdate Quantity\tSort\tShip Items\tNew/Open Aid Database") {
        ut.alocpy(this->filename, filename);
    }

   
    AidMan::~AidMan() {
        if(filename)
        delete[] filename;
    }

   
    void AidMan::run() {
        unsigned int userSelection;
        do {
            userSelection = menu();
            
            switch (userSelection) {
            case 1:
                
                cout<<endl << "****List Items****" << endl<<endl;
                break;
            case 2:
                
                cout << endl << "****Add Item****" << endl << endl;
                break;
                
            case 3:
                cout << endl << "****Remove Item****" << endl << endl;
                break;
            case 4:
                cout << endl << "****Update Quantity****" << endl << endl;
                break;
            case 5:
                cout << endl << "****Sort****" << endl << endl;
                break;
            case 6:
                cout << endl << "****Ship Items****" << endl << endl;
                break;
            case 7:
                cout << endl << "****New/Open Aid Database****" << endl << endl;
                break;
            case 0:
                cout << "Exiting Program!" << endl;
                break;
            
            }
        } while (userSelection != 0);
    }

   
    unsigned int AidMan::menu()const {
        cout << "Aid Management System" << endl;
        cout << "Date: " << Date() << endl;
        if (filename)
        {
            cout << "Data file: " << filename << endl<<endl;
        }
        else
        {
            cout << "Data file: No file" << endl<<endl;
        }
       
        unsigned int val = this->mainMenu.run();
        return val;
    }
}