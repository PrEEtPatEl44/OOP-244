/*/////////////////////////////////////////////////////////////////////////
                          Workshop - #10 (P1)
Full Name  : Preet Bhagyesh Patel
Student ID#: 132603226
Email      : pbpatel48@myseneca.ca
Date       : 26 November 2023

Authenticity Declaration:
I have done all the coding by myself and only copied the code that my
professor provided to complete my workshops and assignments.
/////////////////////////////////////////////////////////////////////////*/
#ifndef SELECTION_H
#define SELECTION_H

#include "EmployeeOffice.h"
#include "Car.h"
#include "Student.h"
#include "Displayable.h"
#include <iostream>
#include <cstring>  

namespace sdds {

    // Function 1
    template <typename arrayType, typename keyType>
    int* select(const arrayType array[], const keyType key, const size_t size) {

        size_t count = 0;
        for (size_t i = 0; i < size; ++i) {
            if (array[i] == key) {
                ++count;
            }
        }

        int* indices = new int[count + 1];  
        size_t index = 0;

        for (size_t i = 0; i < size; ++i) {
            if (array[i] == key) {
                indices[index++] = static_cast<int>(i);
            }
        }

  
        indices[count] = -1;

        return indices;
    }

    // Function 2
    template <typename arrayType>
    void csvDisplaySelection(const char* title, const arrayType array[], const int indices[]) {
        std::cout << title << std::endl;

        if (indices && indices[0] != -1) {
            size_t i = 0;
            while (indices[i] != -1) {
                std::cout << array[static_cast<size_t>(indices[i])];
                if (indices[i + 1] != -1) {
                    std::cout << ", ";
                }
                ++i;
            }
        }
        else {
            std::cout << "Empty Selection";
        }

        std::cout << std::endl;
    }

}
#endif 