/*
* Base class for scalar non-linear equations solver
        *
        * 	   Author: Cyril Vallez <cyril.vallez@epfl.ch>
*/

#ifndef NLE_SOLVER_H
#define NLE_SOLVER_H

#include "Solver.hpp"

class NLE_Solver : public Solver
{
protected:
    double guess;
    double (*f)(double x);

public:
    // Constructor and destructor
    NLE_Solver();
    NLE_Solver(double (*function)(double x));
    NLE_Solver(double initial_guess, double (*function)(double x));
    NLE_Solver(int iterations, double epsilon, double initial_guess, double (*function)(double x));
    virtual ~NLE_Solver();

    // Setters
    void SetGuess(double initial_guess);
    void SetFunction(double (*function)(double x));

    // Getters
    double GetGuess () const {return guess;}
    double EvaluateFunction (double x) const {return f(x);}

    // Virtual function to solve the NLE
    virtual double Solve() const = 0;
};

#endif