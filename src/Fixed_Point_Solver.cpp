/*
* Base class for non-linear equations solver
        *
        * 	   Author: Cyril Vallez <cyril.vallez@epfl.ch>
*/

#include "Fixed_Point_Solver.hpp"

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
