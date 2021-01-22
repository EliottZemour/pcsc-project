//
// Created by Eliott on 05/12/2020.
//

#ifndef BISECTION_H
#define BISECTION_H

#include "NLE_Solver.hpp"

/**
 * Class implements bisection method which is a root-finding method that
 * applies to any continuous functions for which one knows two values with opposite signs.
 */
class Bisection_Solver : public NLE_Solver
{
public:

    /// Constructor and destructor
    Bisection_Solver();
    Bisection_Solver(double (*function)(double x), double LeftEdge, double RightEdge);
    Bisection_Solver(int maxiter, double epsilon, double (*function)(double), double LeftEdge, double RightEdge);
    virtual ~Bisection_Solver();

    /// Solve method
    double Solve() const override;

    /// Setters
    void SetEdges(double LeftEdge, double RightEdge);

private:
    double left, right;
};

/// Functions to solve the problem, handling exceptions
double Solve_Bisection(double (*function)(double x), double LeftEdge, double RightEdge);


#endif //BISECTION_H
