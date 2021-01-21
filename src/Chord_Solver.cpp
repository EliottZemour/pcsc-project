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
double Chord_Solver::Solve(bool acc = false) const
{
    double current = guess;
    double next = 0.;
    double previous = 0.;
    int i = 0;
    next = current - f(current);
    if(acc)
    {
        double nextnext = next - f(next);
        next = Accelerate(current, next, nextnext);
    }
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
            std::cout << "iteration #" << i << std::endl;
            current = next;
            break;
        }

        previous = current;
        current = next;
        double denominator = f(current)-f(previous);
        if (fabs(denominator) < 1e-15)
        {
            std::string error("Division by 0 encountered while updating the approximation of the root, try a new initial guess");
            throw DivBy0Exception(error);
        }
        next = current - (current-previous)/denominator*f(current);
        if(acc)
        {
            denominator = f(next) - f(current);
            double nextnext = next - (next-current)/denominator*f(next);
            next = Accelerate(current, next, nextnext);
        }
        i += 1;
    }

    return current;

}

double Solve_Chord (double initial_guess, double (*fun)(double x), bool acc)
{
    NLE_Solver* solver = new Chord_Solver(initial_guess, fun);
    double solution = -1;

    try
    {
        solution = solver->Solve(acc);
    }
    catch (Exception &error)
    {
        error.PrintDebug();
    }
    delete solver;
    return solution;
}

double Solve_Chord (int iterations, double epsilon, double initial_guess, double (*fun)(double x), bool acc)
{
    NLE_Solver* solver = new Chord_Solver(iterations, epsilon, initial_guess, fun);
    double solution = -1;

    try
    {
        solution = solver->Solve(acc);
    }
    catch (Exception &error)
    {
        error.PrintDebug();
    }
    delete solver;
    return solution;
}

