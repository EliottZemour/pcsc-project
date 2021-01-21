/*
* Base class for systems of non-linear equations solver
        *
        * 	   Author: Cyril Vallez <cyril.vallez@epfl.ch>
*/

#include "NLS_Solver.hpp"
#include <string>
#include <iostream>
#include <cmath>
#include <cassert>
#include <cstdlib>

// ######################## Functions and overload ####################

vector operator* (matrix A, vector b)
{
    int dim = b.size();
    assert(A.size()==dim);
    vector result(dim, 0.);

    for (int i(0); i<dim; ++i)
    {
        assert(A[i].size()==dim);
        for (int j(0); j<dim; ++j)
        {
            result[i] += A[i][j]*b[j];
        }
    }

    return result;
}

vector operator- (vector a, vector b)
{
    assert(a.size()==b.size());
    vector result(a.size());

    for (int i(0); i<a.size(); ++i)
    {
        result[i] = a[i] - b[i];
    }

    return result;
}

vector operator+ (vector a, vector b)
{
    assert(a.size()==b.size());
    vector result(a.size());

    for (int i(0); i<a.size(); ++i)
    {
        result[i] = a[i] + b[i];
    }

    return result;
}

double norm (vector a, int p)
{
    double sum = 0.;

    for (int i(0); i<a.size(); ++i)
    {
        sum += pow(a[i], p);
    }

    return pow(sum, 1./p);

}

// ######################## Class methods ##############################

// Constructor
NLS_Solver::NLS_Solver(int dim, vector (*function)(vector x))
: Solver()
{
    SetDimension(dim);
    guess = vector(dimension, 1.);
    SetFunction(function);
}

// Constructor
NLS_Solver::NLS_Solver(vector initial_guess, vector (*function)(vector x))
: Solver(), guess(initial_guess)
{
    dimension = guess.size();  // The dimension is inferred from the size of the guess
    SetFunction(function);
}

// Constructor
NLS_Solver::NLS_Solver(int iterations, double epsilon, vector initial_guess, vector (*function)(vector x))
: Solver(iterations, epsilon), guess(initial_guess)
{
    dimension = guess.size();  // The dimension is inferred from the size of the guess
    SetFunction(function);
}

// Destructor
NLS_Solver::~NLS_Solver() {}

// Setter
void NLS_Solver::SetGuess(vector initial_guess)
{
    if (initial_guess.size() != dimension)
    {
        std::string problem("The guess does not have the right dimension");
        std::cout << "Problem : " << problem << std::endl;
        std::cout << "Please re-run providing a correct guess" << std::endl;
        exit(EXIT_FAILURE);
    }

    guess = initial_guess;
}

void NLS_Solver::SetFunction(vector (*function)(vector))
{
    f = function;

    if (f == nullptr)
    {
        std::string problem("The pointer on the function to solve for is null");
        std::cout << "Problem : " << problem << std::endl;
        std::cout << "Please re-run providing a correct pointer" << std::endl;
        exit(EXIT_FAILURE);
    }

    TestDimensionFunction();
}

void NLS_Solver::SetDimension(int dim)
{
    dimension = dim;

    if (dimension < 2)
    {
        std::string problem("The dimension of the system must be strictly superior than 1 !");
        int dim = 0;
        do
        {
            std::cout << "Problem : " << problem << std::endl;
            std::cout << "Please enter a valid dimension for your system :" << std::endl;
            std::cin >> dim;
            dimension = dim;
        }
        while (dim < 2);
    }
}

// Test dimension
void NLS_Solver::TestDimensionFunction() const
{
    vector foo = f(guess);
    int dim = foo.size();

    if (dimension != dim)
    {
        std::string problem("The function does not match the dimension of the system !");
        std::cout << "Problem : " << problem << std::endl;
        std::cout << "Please re-run providing correct dimensions" << std::endl;
        exit(EXIT_FAILURE);
    }
}