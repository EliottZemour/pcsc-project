/**
* Class for solving NLS using Newton method
        *
        * 	   Author: Cyril Vallez <cyril.vallez@epfl.ch>
*/

#ifndef NEWTON_SYSTEM_SOLVER_H
#define NEWTON_SYSTEM_SOLVER_H

#include "NLS_Solver.hpp"

class Newton_System_Solver : public NLS_Solver
{
protected:
    matrix (*inv_jacobian)(vector x);

public:
    /// Constructor and destructor
    Newton_System_Solver(int dim, vector (*fun)(vector x), matrix (*inv_jaco)(vector x));
    Newton_System_Solver(vector initial_guess, vector (*fun)(vector x), matrix (*inv_jaco)(vector x));
    Newton_System_Solver(int iterations, double epsilon, vector initial_guess, vector (*fun)(vector x),
                  matrix (*inv_jaco)(vector x));
    virtual ~Newton_System_Solver();

    /// Setter
    void SetInverseJacobian(matrix (*inv_jaco)(vector x));

    /// Getter
    matrix EvaluateInverseJacobian (vector x) const {return inv_jacobian(x);}

    /// To test whether the dimension of the inverse jacobian is correct
    void TestDimensionInvJacobian () const;

    /// Override of the solve function
    vector Solve() const override;
};

// Functions to solve the problem
vector Solve_System_Newton (int dim, vector (*fun)(vector x), matrix (*inv_jaco)(vector x));
vector Solve_System_Newton (vector initial_guess, vector (*fun)(vector x), matrix (*inv_jaco)(vector x));
vector Solve_System_Newton (int iterations, double epsilon, vector initial_guess, vector (*fun)(vector x),
                            matrix (*inv_jaco)(vector x));

#endif