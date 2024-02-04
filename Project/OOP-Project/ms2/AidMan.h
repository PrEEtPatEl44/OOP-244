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
#ifndef SDDS_AIDMAN_H
#define SDDS_AIDMAN_H
#include"Menu.h"
namespace sdds {
	class AidMan {
    private:
        char* filename=nullptr;
        Menu mainMenu;
        unsigned int menu()const;

    public:
        AidMan(const char* filename);
        ~AidMan();
        void run();

    
	};
}
#endif