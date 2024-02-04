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
#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H
#define MAX_CONTENT_CHAR 70;
#include<iostream>

namespace sdds {
	
	class Label
	{
		

	public:
		char* m_content;
		char m_frame[9];
		Label();
		Label(const char* frameArg);
		Label(const char* frameArg, const char* content);
		~Label();
		std::istream& readLabel(std::istream& ist = std::cin);
		std::ostream& printLabel(std::ostream& ostr=std::cout)const;
		Label& text(const char* content);


	};
}
#endif // !
