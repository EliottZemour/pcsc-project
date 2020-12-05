/*
* Class for Exceptions when dividing by 0
        *
        * 	   Author: Cyril Vallez <cyril.vallez@epfl.ch>
*/

#ifndef DIVBY0EXCEPTION_H
#define DIVBY0EXCEPTION_H

#include <iostream>
#include <string>
#include "Exception.hpp"

class DivBy0Exception : public Exception {

    public:

    // Constructor
    DivBy0Exception(std::string problem_);

};

#endif