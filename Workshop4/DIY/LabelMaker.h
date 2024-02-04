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

#ifndef SDDS_LABEL_MAKER_H
#define SDDS_LABEL_MAKER_H
#include "Label.h"

namespace sdds {
	class LabelMaker {

		Label* m_labelsList;
		int m_noOfLabels;

	public:
		LabelMaker(int noOfLabels);
		void readLabels();
		void printLabels();
		~LabelMaker();


	};
}
#endif // !SDDS_LABEL_MAKER_H
