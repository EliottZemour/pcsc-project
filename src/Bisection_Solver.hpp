//
// Created by Eliott on 05/12/2020.
//

#ifndef BISECTION_H
#define BISECTION_H

#include "NLE_Solver.hpp"

class Bisection_Solver : public NLE_Solver
{
public:

    // Constructor and destructor
    Bisection_Solver();
    Bisection_Solver(double (*function)(double x), double LeftEdge, double RightEdge);
    virtual ~Bisection_Solver();

    // Solve method
    double Solve(bool acc = false) const override;

    // Setters
    void SetEdges(double LeftEdge, double RightEdge);

private:
    double left, right;
};

// Functions to solve the problem, handling exceptions
double Solve_Bisection(double (*function)(double x), double LeftEdge, double RightEdge);


#endif //BISECTION_H
