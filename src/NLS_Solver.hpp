/*
* Base class for systems of non-linear equations solver
        *
        * 	   Author: Cyril Vallez <cyril.vallez@epfl.ch>
*/

#ifndef NLS_SOLVER_H
#define NLS_SOLVER_H

#include <vector>
#include "Solver.hpp"

// ################################### Types ##########################

typedef std::vector<double> vector;
typedef std::vector<std::vector<double>> matrix;

// ######################## Functions and overloads #####################

vector operator* (matrix A, vector b);
vector operator- (vector a, vector b);
vector operator+ (vector a, vector b);
double norm (vector a);

// ############################# Class ####################################

class NLS_Solver : public Solver
{
protected:
    vector guess;
    vector (*f)(vector x);

public:
    // Constructor and destructor
    NLS_Solver();
    NLS_Solver(vector (*function)(vector x));
    NLS_Solver(vector initial_guess, vector (*function)(vector x));
    NLS_Solver(int iterations, double epsilon, vector initial_guess, vector (*function)(vector x));
    virtual ~NLS_Solver();

    // Setters
    void SetGuess(vector initial_guess);
    void SetFunction(vector (*function)(vector x));

    // Getters
    vector GetGuess () const {return guess;}
    vector EvaluateFunction (vector x) const {return f(x);}

    // Virtual function to solve the NLS
    virtual vector Solve() const = 0;
};

#endif