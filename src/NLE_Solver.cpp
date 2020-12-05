/*
* Base class for non-linear equations solver
        *
        * 	   Author: Cyril Vallez <cyril.vallez@epfl.ch>
*/

#include "NLE_Solver.hpp"

// Default Constructor
NLE_Solver::NLE_Solver()
: max_iter(100), tolerance(1e-3), guess(0.), f(0) {}

// Constructor
NLE_Solver::NLE_Solver(double (*function)(double x))
: max_iter(100), tolerance(1e-3), guess(0.), f(function) {}

// Constructor
NLE_Solver::NLE_Solver(double initial_guess, double (*function)(double x))
: max_iter(100), tolerance(1e-3), guess(initial_guess), f(function) {}

// Constructor
NLE_Solver::NLE_Solver(int iterations, double epsilon, double initial_guess, double (*function)(double x))
: max_iter(iterations), tolerance(epsilon), guess(initial_guess), f(function) {}

// Destructor
NLE_Solver::~NLE_Solver() {}
