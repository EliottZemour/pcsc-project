/*
* Class for Exceptions when dividing by 0
        *
        * 	   Author: Cyril Vallez <cyril.vallez@epfl.ch>
*/

#include "Exception.hpp"
#include "DivBy0Exception.hpp"
#include <string>

DivBy0Exception::DivBy0Exception (std::string problems_)
: Exception("Division by 0", problems_) {}


