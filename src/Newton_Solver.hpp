/*
* Class for solving NLE using Newton method
        *
        * 	   Author: Cyril Vallez <cyril.vallez@epfl.ch>
*/

#ifndef NEWTON_SOLVER_H
#define NEWTON_SOLVER_H

#include "NLE_Solver.hpp"
#include "Aitken_Accelerator.hpp"

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

    // Setter
    void SetDerivative(double (*fun_p)(double x));

    // Getter
    double EvaluateDerivative (double x) const {return f_prime(x);}

    // Override of the solve function
    double Solve(bool acc = false) const override;
};

// Functions to solve the problem, handling exceptions
double Solve_Newton (double initial_guess, double (*fun)(double x), double (*fun_p)(double x), bool acc = false);
double Solve_Newton (int iterations, double epsilon, double initial_guess, double (*fun)(double x),
                     double (*fun_p)(double x), bool acc = false);

#endif