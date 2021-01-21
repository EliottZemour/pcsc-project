/*
* Class for solving NLE using classical chord method
        *
        * 	   Author: Cyril Vallez <cyril.vallez@epfl.ch>
*/

#include "Chord_Solver.hpp"
#include <cmath>
#include <iostream>
#include "Aitken_Accelerator.hpp"

// Default Constructor
Chord_Solver::Chord_Solver()
: Fixed_Point_Solver() {}

// Constructor
Chord_Solver::Chord_Solver(double (*function)(double), bool acceleration)
: Fixed_Point_Solver(function, acceleration) {}

// Constructor
Chord_Solver::Chord_Solver(double initial_guess, double (*function)(double), bool acceleration)
: Fixed_Point_Solver(initial_guess, function, acceleration) {}

// Constructor
Chord_Solver::Chord_Solver(int iterations, double epsilon, double initial_guess, double (*function)(double x),
                           bool acceleration)
: Fixed_Point_Solver(iterations, epsilon, initial_guess, function, acceleration) {}

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

    if(acc)
    {
        double nextnext = next - f(next);
        next = Accelerate(current, next, nextnext);
    }

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
        IsZero(denominator);
        next = current - (current-previous)/denominator*f(current);
        i += 1;

        if(acc)
        {
            denominator = f(next) - f(current);
            IsZero(denominator);
            double nextnext = next - (next-current)/denominator*f(next);
            next = Accelerate(current, next, nextnext);
        }
    }

    return current;

}

//################################ External functions #################################

double Solve_Chord (double (*fun)(double x), bool acc)
{
    NLE_Solver* solver = new Chord_Solver(fun, acc);
    return TrySolve(solver);
}

double Solve_Chord (double initial_guess, double (*fun)(double x), bool acc)
{
    NLE_Solver* solver = new Chord_Solver(initial_guess, fun, acc);
    return TrySolve(solver);
}

double Solve_Chord (int iterations, double epsilon, double initial_guess, double (*fun)(double x), bool acc)
{
    NLE_Solver* solver = new Chord_Solver(iterations, epsilon, initial_guess, fun, acc);
    return TrySolve(solver);
}

