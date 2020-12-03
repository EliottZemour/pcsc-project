/*
* Class for Exceptions
        *
        * 	   Author: Cyril Vallez <cyril.vallez@epfl.ch>
*/

#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
#include <string>

class Exception {

protected:

    std::string tag;
    std::string problem;

    public:

    // Constructor
    Exception(std::string problem_);

    // Constructor
    Exception(std::string tag_, std::string problem_);

    // Method
    void PrintDebug () const;

};

#endif