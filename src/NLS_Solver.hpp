

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
double norm (vector a, int p=2);

// ############################# Class ####################################

/**
* Base class for systems of non-linear equations solver
*/

class NLS_Solver : public Solver
{
protected:
    int dimension;
    vector guess;
    vector (*f)(vector x);

public:
    /// Constructor and destructor
    NLS_Solver(int dim, vector (*function)(vector x));
    NLS_Solver(vector initial_guess, vector (*function)(vector x));
    NLS_Solver(int iterations, double epsilon, vector initial_guess, vector (*function)(vector x));
    virtual ~NLS_Solver();

    /// Setters
    void SetGuess(vector initial_guess);
    void SetFunction(vector (*function)(vector x));
    void SetDimension(int dim);

    /// Getters
    vector GetGuess () const {return guess;}
    vector EvaluateFunction (vector x) const {return f(x);}
    int GetDimension () const {return dimension;}

    /// To test whether the dimension of the function f is correct
    void TestDimensionFunction () const;

    /// Virtual function to solve the NLS
    virtual vector Solve() const = 0;
};

#endif