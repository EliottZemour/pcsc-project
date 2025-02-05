

#ifndef NEWTON_SOLVER_H
#define NEWTON_SOLVER_H

#include "Fixed_Point_Solver.hpp"
#include "Aitken_Accelerator.hpp"
/**
* Class for solving NLE using Newton method
*/
class Newton_Solver : public Fixed_Point_Solver
{
protected:
    double (*f_prime)(double x);

public:
    /// Constructor and destructor
    Newton_Solver();
    Newton_Solver(double (*fun)(double x), double (*fun_p)(double x), bool acceleration = false);
    Newton_Solver(double initial_guess, double (*fun)(double x), double (*fun_p)(double x),
                  bool acceleration = false);
    Newton_Solver(int iterations, double epsilon, double initial_guess, double (*fun)(double x),
                  double (*fun_p)(double x), bool acceleration = false);
    virtual ~Newton_Solver();

    /// Setter
    void SetDerivative(double (*fun_p)(double x));

    /// Getter
    double EvaluateDerivative (double x) const {return f_prime(x);}

    /// Override of the solve function
    double Solve() const override;
};

///################################ External functions #################################
double Solve_Newton (double (*fun)(double x), double (*fun_p)(double x), bool acc = false);
double Solve_Newton (double initial_guess, double (*fun)(double x), double (*fun_p)(double x), bool acc = false);
double Solve_Newton (int iterations, double epsilon, double initial_guess, double (*fun)(double x),
                     double (*fun_p)(double x), bool acc = false);

#endif