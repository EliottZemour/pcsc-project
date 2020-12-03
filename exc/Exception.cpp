/*
* Class for Exceptions
        *
        * 	   Author: Cyril Vallez <cyril.vallez@epfl.ch>
*/

#include "Exception.hpp"
#include <string>

Exception::Exception (std::string problems_)
{
    problem = problems_;
    tag = "Undefined";
}

Exception::Exception(std::string tag_, std::string problem_)
{
    tag = tag_;
    problem = problem_;
}

void Exception::PrintDebug () const
{
    std::cerr << "** Error (" << tag << ") **" << std::endl;
    std::cerr << "Problem : " << problem << std::endl << std::endl;
}