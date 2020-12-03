/*
* Class for solving NLE using Newton method
        *
        * 	   Author: Cyril Vallez <cyril.vallez@epfl.ch>
*/

#ifndef NEWTON_SOLVER_H
#define NEWTON_SOLVER_H

#include "NLE_Solver.hpp"

class Newton_Solver : public NLE_Solver
{
protected:
    double (*f_prime)(double x);

public:
    // Constructor and destructor
    Newton_Solver();
    Newton_Solver(double initial_guess, double (*fun)(double x), double (*fun_p)(double x));
    Newton_Solver(int iterations, double epsilon, double initial_guess, double (*fun)(double x),
                  double (*fun_p)(double x));
    virtual ~Newton_Solver();

    // Override of the solve function
    double Solve() const override;
};

// Function to initialize a Newton_Solver, handling exceptions
NLE_Solver* Initialize_Newton (double initial_guess, double (*fun)(double x), double (*fun_p)(double x));
NLE_Solver* Initialize_Newton (int iterations, double epsilon, double initial_guess, double (*fun)(double x),
                              double (*fun_p)(double x));

// Functions to solve the problem, handling exceptions
double Solve_Newton (double initial_guess, double (*fun)(double x), double (*fun_p)(double x));
double Solve_Newton (int iterations, double epsilon, double initial_guess, double (*fun)(double x),
                     double (*fun_p)(double x));

#endif