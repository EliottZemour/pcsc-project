/*
* Base class for all solvers
        *
        * 	   Author: Cyril Vallez <cyril.vallez@epfl.ch>
*/

#include "Solver.hpp"
#include <string>
#include <iostream>

// Default Constructor
Solver::Solver()
: max_iter(100), tolerance(1e-3) {}

// Constructor
Solver::Solver(int iterations, double epsilon)
{
    SetMaxIter(iterations);
    SetTolerance(epsilon);
}

// Destructor
Solver::~Solver() {}

// Setters
void Solver::SetMaxIter(int iter)
{
    max_iter = iter;

    if (max_iter < 1)
    {
        std::string problem("The maximum number of iterations must be superior than 0 !");
        int iter_max = 0;
        do
        {
            std::cout << "Problem : " << problem << std::endl;
            std::cout << "Please enter a valid number of iterations :" << std::endl;
            std::cin >> iter_max;
            max_iter = iter_max;
        }
        while (iter_max < 1);
    }
}

void Solver::SetTolerance(double epsilon)
{
    tolerance = epsilon;

    if (tolerance <= 0)
    {
        std::string problem("The tolerance must be strictly positive !");
        double eps = 0.;
        do
        {
            std::cout << "Problem : " << problem << std::endl;
            std::cout << "Please enter a valid tolerance :" << std::endl;
            std::cin >> eps;
            tolerance = eps;
        }
        while (eps <= 0);
    }
    if (tolerance > 1)
    {
        std::cout << "The tolerance is really high (bigger than 1)" << std::endl;
        std::cout << "Continuing anyway..." << std::endl;
    }
}
