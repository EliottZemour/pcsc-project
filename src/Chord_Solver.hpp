/*
* Class for solving NLE using classical chord method
        *
        * 	   Author: Cyril Vallez <cyril.vallez@epfl.ch>
*/

#ifndef CHORD_SOLVER_H
#define CHORD_SOLVER_H

#include "NLE_Solver.hpp"
#include "Aitken_Accelerator.hpp"

class Chord_Solver : public NLE_Solver
{
public:
    // Constructor and destructor
    Chord_Solver();
    Chord_Solver(double initial_guess, double (*function)(double x));
    Chord_Solver(int iterations, double epsilon, double initial_guess, double (*function)(double x));
    virtual ~Chord_Solver();

    // Override of the solve function
    double Solve(bool acc) const override;
};

// Functions to solve the problem, handling exceptions
double Solve_Chord (double initial_guess, double (*fun)(double x), bool acc);
double Solve_Chord (int iterations, double epsilon, double initial_guess, double (*fun)(double x), bool acc);


#endif