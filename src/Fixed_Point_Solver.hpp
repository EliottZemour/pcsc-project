

#ifndef FIXED_POINT_SOLVER_H
#define FIXED_POINT_SOLVER_H

#include "NLE_Solver.hpp"

/**
* Base class for non-linear equations solver using fixed point method
*/
class Fixed_Point_Solver : public NLE_Solver
{
protected:
    bool acc;

public:
    /// Constructor and destructor
    Fixed_Point_Solver();
    Fixed_Point_Solver(double (*function)(double x), bool acceleration);
    Fixed_Point_Solver(double initial_guess, double (*function)(double x), bool acceleration);
    Fixed_Point_Solver(int iterations, double epsilon, double initial_guess, double (*function)(double x),
                       bool acceleration);
    virtual ~Fixed_Point_Solver();

    /// Setters
    void SetAcceleration (bool acceleration) {acc = acceleration;}

    /// Getters
    double GetAcceleration () const {return acc;}

};

/** Function handling the exceptions that will occur in the override of the Solve function.
// It will try solving a second time changing the initial guess. This is particularly useful when using
// Newton's method, since the user may set the initial guess on a zero of the derivative. For example,
// if the derivative is 3x^2, the user may be tempted of setting the initial guess to 0, which will create a
// division by 0
*/
double TrySolve (NLE_Solver *solver);

#endif