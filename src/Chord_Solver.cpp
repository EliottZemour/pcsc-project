/*
* Class for solving NLE using classical chord method
        *
        * 	   Author: Cyril Vallez <cyril.vallez@epfl.ch>
*/

#include "NLE_Solver.hpp"
#include "Chord_Solver.hpp"
#include <cmath>
#include <iostream>

// Default Constructor
Chord_Solver::Chord_Solver()
: NLE_Solver() {}

// Constructor
Chord_Solver::Chord_Solver(double initial_guess, double (*function)(double))
: NLE_Solver(initial_guess, function) {}

// Constructor
Chord_Solver::Chord_Solver(int iterations, double epsilon, double initial_guess, double (*function)(double x))
: NLE_Solver(iterations, epsilon, initial_guess, function) {}

// Destructor
Chord_Solver::~Chord_Solver() {}

double Chord_Solver::Solve() const
{
    double current = guess;
    double next = 0.;
    double previous = 0.;
    int i = 0;

    next = current - f(current);
    i += 1;

    while (true)
    {
        if (i>=max_iter)
        {
            std::cout << "Stopped because maximum number of iterations was reached" << std::endl;
            current = next;
            break;
        }
        if (abs(next-current)<tolerance)
        {
            std::cout << "Stopped because the solution has converged within the given tolerance" << std::endl;
            current = next;
            break;
        }
        /*
        if (abs(next-current) >= abs(current-previous) and i>1)
        {
            std::cout << "Solution is diverging : find better initial guess" << std::endl;
            break;
        }
        */
        previous = current;
        current = next;
        next = current - (current-previous)/(f(current)-f(previous))*f(current);
        i += 1;
    }

    return current;

}
