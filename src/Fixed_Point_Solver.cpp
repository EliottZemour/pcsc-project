/*
* Base class for non-linear equations solver using fixed point method
        *
        * 	   Author: Cyril Vallez <cyril.vallez@epfl.ch>
*/

#include "Fixed_Point_Solver.hpp"
#include "exc/Exception.hpp"

// Default Constructor
Fixed_Point_Solver::Fixed_Point_Solver()
: NLE_Solver(), acc(false) {}

// Constructor
Fixed_Point_Solver::Fixed_Point_Solver(double (*function)(double), bool acceleration)
: NLE_Solver(function), acc(acceleration) {}

// Constructor
Fixed_Point_Solver::Fixed_Point_Solver(double initial_guess, double (*function)(double), bool acceleration)
: NLE_Solver(initial_guess, function), acc(acceleration) {}

// Constructor
Fixed_Point_Solver::Fixed_Point_Solver(int iterations, double epsilon, double initial_guess,
                                       double (*function)(double), bool acceleration)
: NLE_Solver(iterations, epsilon, initial_guess, function), acc(acceleration) {}


// Destructor
Fixed_Point_Solver::~Fixed_Point_Solver() {}


//########################################## External function ##############################################

double TrySolve (NLE_Solver *solver)
{
    double solution;
    try
    {
        solution = solver->Solve();
    }
    catch (Exception &error)
    {
        error.PrintDebug();
        std::cout << "Changing slightly the initial guess and trying a second time" << std::endl << std::endl;
        solver->SetGuess(solver->GetGuess() + 1.);
        try
        {
            solution = solver->Solve();
        }
        catch (Exception &exc)
        {
            exc.PrintDebug();
        }
    }
    return solution;
}
