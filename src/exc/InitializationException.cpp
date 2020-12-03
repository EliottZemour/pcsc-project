/*
* Class for Exceptions when initializing a solver badly
        *
        * 	   Author: Cyril Vallez <cyril.vallez@epfl.ch>
*/

#include "InitializationException.hpp"
#include <string>

InitializationException::InitializationException(std::string problems_)
: Exception("Initialization", problems_), variable("undefined") {}

InitializationException::InitializationException(std::string problem_, std::string variable_)
: Exception("Initialization", problem_), variable(variable_) {}
