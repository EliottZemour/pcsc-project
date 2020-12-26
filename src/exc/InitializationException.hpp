/*
* Class for Exceptions when initializing a solver badly
        *
        * 	   Author: Cyril Vallez <cyril.vallez@epfl.ch>
*/

#ifndef INITIALIZATIONEXCEPTION_H
#define INITIALIZATIONEXCEPTION_H

#include "Exception.hpp"

class InitializationException : public Exception {

protected:
    std::string variable;

    public:

    // Constructor
    InitializationException(std::string problem_);
    InitializationException(std::string problem_, std::string variable_);

    // Getter
    std::string GetVariable () const {return variable;}

};

#endif