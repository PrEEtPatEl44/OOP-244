/*/////////////////////////////////////////////////////////////////////////
						  Workshop - #4 (P2)
Full Name  : Preet Bhagyesh Patel
Student ID#: 132603226
Email      : pbpatel48@myseneca.ca
Date       : 6 october 2023

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/

#include "LabelMaker.h"

using namespace std;
namespace sdds {

	LabelMaker::LabelMaker(int noOfLabels) {
		m_noOfLabels = noOfLabels;
		m_labelsList = new Label[noOfLabels];
	}

	void LabelMaker::readLabels(){
		int i = 0;
		cout << "Enter " << m_noOfLabels << " labels:" << endl;
		for ( i = 0; i < m_noOfLabels; i++) {
			cout << "Enter label number " << i + 1 << endl
				<< "> ";
			 m_labelsList[i].readLabel();
		}
	}

	void LabelMaker::printLabels(){
		int i = 0; 
		for ( i = 0; i < m_noOfLabels; i++) {
			m_labelsList[i].printLabel()<<endl;
		}
		
	}

	LabelMaker::~LabelMaker() {
		
		delete[] m_labelsList;
		m_labelsList = nullptr;

		
	}
}