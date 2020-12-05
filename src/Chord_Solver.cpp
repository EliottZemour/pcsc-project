/*
* Class for solving NLE using classical chord method
        *
        * 	   Author: Cyril Vallez <cyril.vallez@epfl.ch>
*/

#include "Chord_Solver.hpp"
#include "exc/DivBy0Exception.hpp"
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

// Override of the solve function
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
        if (fabs(next-current)<tolerance)
        {
            std::cout << "Stopped because the solution has converged within the given tolerance" << std::endl;
            current = next;
            break;
        }

        previous = current;
        current = next;
        double denominator = f(current)-f(previous);
        if (denominator < 1e-15)
        {
            std::cout << "Division by 0" << std::endl;
        }
        next = current - (current-previous)/denominator*f(current);
        i += 1;

    }

    return current;

}

double Solve_Chord (double initial_guess, double (*fun)(double x))
{
    NLE_Solver* solver = new Chord_Solver(initial_guess, fun);
    double solution = -1;

    try
    {
        solution = solver->Solve();
    }
    catch (Exception &error)
    {
        error.PrintDebug();
    }
    delete solver;
    return solution;
}

double Solve_Chord (int iterations, double epsilon, double initial_guess, double (*fun)(double x))
{
    NLE_Solver* solver = new Chord_Solver(iterations, epsilon, initial_guess, fun);
    double solution = -1;

    try
    {
        solution = solver->Solve();
    }
    catch (Exception &error)
    {
        error.PrintDebug();
    }
    delete solver;
    return solution;
}