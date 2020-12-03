/*
* Class for Exceptions when problems of convergence
        *
        * 	   Author: Cyril Vallez <cyril.vallez@epfl.ch>
*/

#ifndef CONVERGENCEEXCEPTION_H
#define CONVERGENCEEXCEPTION_H

#include <iostream>
#include <string>
#include "Exception.hpp"

class ConvergenceException : public Exception {

    public:

    // Constructor
    ConvergenceException(std::string problem_);

};

#endif