#ifndef CHORD_SOLVER_H
#define CHORD_SOLVER_H

#include "Fixed_Point_Solver.hpp"
#include "Aitken_Accelerator.hpp"

/**
* Class for solving NLE using classical chord method
*/
class Chord_Solver : public Fixed_Point_Solver
{
public:
    /// Constructor and destructor
    Chord_Solver();
    Chord_Solver(double (*function)(double x), bool acceleration = false);
    Chord_Solver(double initial_guess, double (*function)(double x), bool acceleration = false);
    Chord_Solver(int iterations, double epsilon, double initial_guess, double (*function)(double x),
                 bool acceleration = false);
    virtual ~Chord_Solver();

    /// Override of the solve function
    double Solve() const override;
};

/// Functions to solve the problem, handling exceptions
double Solve_Chord (double (*fun)(double x), bool acc = false);
double Solve_Chord (double initial_guess, double (*fun)(double x), bool acc = false);
double Solve_Chord (int iterations, double epsilon, double initial_guess, double (*fun)(double x), bool acc = false);


#endif