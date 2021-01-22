/**
* Base class for non-linear equations solver
*/

#include "NLE_Solver.hpp"
#include "exc/DivBy0Exception.hpp"
#include <string>
#include <iostream>
#include <cstdlib>
#include <cmath>

/// Default Constructor
NLE_Solver::NLE_Solver()
: Solver(), guess(1.), f(nullptr) {}

/// Constructor
NLE_Solver::NLE_Solver(double (*function)(double x))
: Solver(), guess(1.)
{
    SetFunction(function);
}

/// Another Constructor
NLE_Solver::NLE_Solver(double initial_guess, double (*function)(double))
: Solver(), guess(initial_guess)
{
    SetFunction(function);
}

/// Another Constructor
NLE_Solver::NLE_Solver(int iterations, double epsilon, double initial_guess, double (*function)(double x))
: Solver(iterations, epsilon), guess(initial_guess)
{
    SetFunction(function);
}

/// Destructor
NLE_Solver::~NLE_Solver() {}


/// Setter
void NLE_Solver::SetGuess(double initial_guess)
{
    guess = initial_guess;
}

void NLE_Solver::SetFunction(double (*function)(double))
{
    f = function;

    if (f == nullptr)
    {
        std::string problem("The pointer on the function to solve for is null");
        std::cout << "Problem : " << problem << std::endl;
        std::cout << "Please re-run providing a correct pointer" << std::endl;
        exit(EXIT_FAILURE);
    }
}

/// ################################### External function #################################

void IsZero (double denominator)
{
    if (fabs(denominator) < 1e-15 )
    {
        std::string error("Division by 0 encountered while updating the approximation of the root");
        throw DivBy0Exception(error);
    }
}