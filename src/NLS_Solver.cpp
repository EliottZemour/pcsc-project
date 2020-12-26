/*
* Base class for systems of non-linear equations solver
        *
        * 	   Author: Cyril Vallez <cyril.vallez@epfl.ch>
*/

#include "NLS_Solver.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

// ######################## Functions and overload ####################

vector operator* (matrix A, vector b)
{
    int matrix_size = A.size();
    int vector_size = b.size();
}

// ######################## Class methods ##############################

// Default Constructor
NLS_Solver::NLS_Solver()
: Solver(), guess(0.), f(nullptr) {}

// Constructor
NLS_Solver::NLS_Solver(vector (*function)(vector x))
: Solver(), guess(0.)
{
    SetFunction(function);
}

// Constructor
NLS_Solver::NLS_Solver(vector initial_guess, vector (*function)(vector x))
: Solver(), guess(initial_guess)
{
    SetFunction(function);
}

// Constructor
NLS_Solver::NLS_Solver(int iterations, double epsilon, vector initial_guess, vector (*function)(vector x))
: Solver(iterations, epsilon), guess(initial_guess)
{
    SetFunction(function);
}

// Destructor
NLS_Solver::~NLS_Solver() {}

// Setter
void NLS_Solver::SetGuess(vector initial_guess)
{
    guess = initial_guess;
}

void NLS_Solver::SetFunction(vector (*function)(vector))
{
    f = function;

    if (f == nullptr)
    {
        std::string problem("The pointer on the function to solve for is null");
        std::cerr << "Problem : " << problem << std::endl;
        std::cerr << "Please re-run providing a correct pointer" << std::endl;
        std::cerr.flush();
        exit(EXIT_FAILURE);
    }
}
