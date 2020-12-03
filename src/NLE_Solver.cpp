/*
* Base class for non-linear equations solver
        *
        * 	   Author: Cyril Vallez <cyril.vallez@epfl.ch>
*/

#include "NLE_Solver.hpp"
#include "exc/InitializationException.hpp"
#include <string>
#include <iostream>

// Default Constructor
NLE_Solver::NLE_Solver()
: max_iter(100), tolerance(1e-3), guess(0.), f(nullptr) {}

// Constructor
NLE_Solver::NLE_Solver(double initial_guess, double (*function)(double))
: max_iter(100), tolerance(1e-3), guess(initial_guess), f(function)
{
    if (function == nullptr)
    {
        std::string problem("The pointer on the function to solve for is null");
        std::string variable("f");
        throw InitializationException(problem, variable);
    }
}

// Constructor
NLE_Solver::NLE_Solver(int iterations, double epsilon, double initial_guess, double (*function)(double x))
: max_iter(iterations), tolerance(epsilon), guess(initial_guess), f(function)
{
    if (iterations < 1)
    {
        std::string problem("The maximum number of iterations must be superior than 0 !");
        std::string variable("iterations");
        throw InitializationException(problem, variable);
    }
    if (epsilon <= 0)
    {
        std::string problem("The tolerance must be strictly positive !");
        std::string variable("epsilon");
        throw InitializationException(problem, variable);
    }
    if (epsilon > 1)
    {
        std::cerr << "The tolerance is really high (bigger than 1)" << std::endl;
        std::cerr << "Solving anyway..." << std::endl;

    }
    if (function == nullptr)
    {
        std::string problem("The pointer on the function to solve for is null");
        std::string variable("f");
        throw InitializationException(problem, variable);
    }
}

// Destructor
NLE_Solver::~NLE_Solver() {}
