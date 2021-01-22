

#ifndef EXCEPTION_H
#define EXCEPTION_H

#include <iostream>
#include <string>
/**
* Class for Exceptions. This is the superclass and any exception has to be derived from it.
*/
class Exception {

protected:

    std::string tag;
    std::string problem;

    public:

    /// Constructor
    Exception(std::string problem_);

    /// Constructor
    Exception(std::string tag_, std::string problem_);

    /// Getters
    std::string GetTag () const {return tag;}
    std::string GetProblem () const {return problem;}

    /// Method
    void PrintDebug () const;

};

#endif