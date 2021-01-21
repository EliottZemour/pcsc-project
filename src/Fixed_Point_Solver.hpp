/*
* Base class for scalar non-linear equations solver
        *
        * 	   Author: Cyril Vallez <cyril.vallez@epfl.ch>
*/

#ifndef FIXED_POINT_SOLVER_H
#define FIXED_POINT_SOLVER_H

#include "NLE_Solver.hpp"

class Fixed_Point_Solver : public NLE_Solver
{
protected:
    bool acc;

public:
    // Constructor and destructor
    Fixed_Point_Solver();
    Fixed_Point_Solver(double (*function)(double x), bool acceleration);
    Fixed_Point_Solver(double initial_guess, double (*function)(double x), bool acceleration);
    Fixed_Point_Solver(int iterations, double epsilon, double initial_guess, double (*function)(double x),
                       bool acceleration);
    virtual ~Fixed_Point_Solver();

    // Setters
    void SetAcceleration (bool acceleration) {acc = acceleration;}

    // Getters
    double GetAcceleration () const {return acc;}

};

#endif