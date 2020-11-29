/*
* Base class for scalar non-linear equations solver
        *
        * 	   Author: Cyril Vallez <cyril.vallez@epfl.ch>
*/

#ifndef NLE_SOLVER_H
#define NLE_SOLVER_H

class NLE_Solver
{
protected:
    int max_iter;
    double tolerance;
    double guess;
    double (*f)(double x);

public:
    // Constructor and destructor
    NLE_Solver();
    NLE_Solver(double initial_guess, double (*function)(double x));
    NLE_Solver(int iterations, double epsilon, double initial_guess, double (*function)(double x));
    virtual ~NLE_Solver();

    // Setters
    void SetMaxIter(int iter) {max_iter = iter;}
    void SetTolerance(double epsilon) {tolerance = epsilon;}
    void SetGuess(double initial_guess) {guess = initial_guess;}
    void SetFunction(double (*function)(double x)) {f = function;}

    // Getters
    int GetMaxIter () const {return max_iter;}
    double GetTolerance() const {return tolerance;}
    double GetGuess () const {return guess;}
    double EvaluateFunction (double x) const {return f(x);}

    // Virtual function to solve the NLE
    virtual double Solve() const = 0;
};

#endif