
#ifndef DIVBY0EXCEPTION_H
#define DIVBY0EXCEPTION_H

#include <iostream>
#include <string>
#include "Exception.hpp"

/**
 * DivBy0Exception class, handling exceptions thrown when a denominator is too close
 * to zero (typically < 1e-15)
 */
class DivBy0Exception : public Exception {

    public:

    /// Constructor
    DivBy0Exception(std::string problem_);

};

#endif