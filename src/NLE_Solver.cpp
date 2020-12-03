/*
* Base class for non-linear equations solver
        *
        * 	   Author: Cyril Vallez <cyril.vallez@epfl.ch>
*/

#include "NLE_Solver.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

// Default Constructor
NLE_Solver::NLE_Solver()
: max_iter(100), tolerance(1e-3), guess(0.), f(nullptr) {}

// Constructor
NLE_Solver::NLE_Solver(double initial_guess, double (*function)(double))
: max_iter(100), tolerance(1e-3), guess(initial_guess), f(function)
{
    if (f == nullptr)
    {
        std::cerr << "** Error (" << "Initialization" << ") **" << std::endl;
        std::string problem("The pointer on the function to solve for is null");
        std::cerr << "Problem : " << problem << std::endl << std::endl;
        std::cerr << "Please re-run providing a correct pointer" << std::endl;
        std::cerr.flush();
        exit(EXIT_FAILURE);
    }
}

// Constructor
NLE_Solver::NLE_Solver(int iterations, double epsilon, double initial_guess, double (*function)(double x))
: max_iter(iterations), tolerance(epsilon), guess(initial_guess), f(function)
{
    std::string tag = "** Error (Initialization) **";

    if (max_iter < 1)
    {
        std::string problem("The maximum number of iterations must be superior than 0 !");
        int iter = 0;
        do
        {
           std::cerr << tag << std::endl;
           std::cerr << "Problem : " << problem << std::endl << std::endl;
           std::cerr.flush();
           std::cout << "Please enter a valid number of iterations :" << std::endl;
           std::cin >> iter;
           max_iter = iter;
        }
        while (iter < 1);
    }
    if (tolerance <= 0)
    {
        std::string problem("The tolerance must be strictly positive !");
        double eps = 0.;
        do
        {
            std::cerr << tag << std::endl;
            std::cerr << "Problem : " << problem << std::endl << std::endl;
            std::cerr.flush();
            std::cout << "Please enter a valid tolerance :" << std::endl;
            std::cin >> eps;
            tolerance = eps;
        }
        while (eps <= 0);
    }
    if (tolerance > 1)
    {
        std::cerr << "The tolerance is really high (bigger than 1)" << std::endl;
        std::cerr << "Solving anyway..." << std::endl;
        std::cerr.flush();

    }
    if (f == nullptr)
    {
        std::cerr << tag << std::endl;
        std::string problem("The pointer on the function to solve for is null");
        std::cerr << "Problem : " << problem << std::endl << std::endl;
        std::cerr << "Please re-run providing a correct pointer" << std::endl;
        std::cerr.flush();
        exit(EXIT_FAILURE);
    }
}

// Destructor
NLE_Solver::~NLE_Solver() {}
