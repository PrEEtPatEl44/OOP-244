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
#include "Menu.h"
#include "Utils.h"
#include <iostream>
using namespace std;
#include <cstring>
namespace sdds {
	int sdds::Menu::countTab(const char* mContent)const
	{
		int count = 0;
		unsigned int i;
		if (*mContent) {
			for (i = 0; i < strlen(mContent); i++) {
				if (mContent[i] == '\t') {
					count++;
				}
			}
		}
		return count;
		
	}
	void Menu::setEmpty()
	{
		m_menuContent = nullptr;
	}

	Menu::Menu()
	{
		setEmpty();
	}

	Menu::Menu(const char* mContent)
	{
		setEmpty();
		if (mContent && countTab(mContent) < 15) {
				ut.alocpy(m_menuContent, mContent);
		}
		else {
			m_menuContent = nullptr;
		}
	}

	Menu::~Menu()
	{
		if (m_menuContent) {
			delete[]m_menuContent;
		}
	}
	unsigned int Menu::run()const
	{
		if (m_menuContent) {
			
			unsigned int count = countTab(m_menuContent), i = 0;
			int j = 0;

			
			do {
				cout << ++i << "- ";
				while (m_menuContent[j] != '\t' && j < (int)strlen(m_menuContent)) {
					cout << m_menuContent[j];
					j++;
				}
				j++;
				cout << endl;
			} while (i < count+1); //adding 1 because the number of options would be 1 more than the number of tabs
			cout << "---------------------------------" << endl << "0- Exit" << endl;
			int option = ut.getint(0, count+1, "> ");
			return option;
		}
		else {
			cout << "Invalid Menu!" << endl;
			return 0;
		}
	
	}
}
