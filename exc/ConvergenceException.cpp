/*
* Class for Exceptions when problems of convergence
        *
        * 	   Author: Cyril Vallez <cyril.vallez@epfl.ch>
*/

#include "Exception.hpp"
#include "ConvergenceException.hpp"
#include <string>

ConvergenceException::ConvergenceException (std::string problems_)
: Exception("Convergence issue", problems_) {}


