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
    double Solve() const override;

private:
    double left, right;
};


#endif //BISECTION_H
