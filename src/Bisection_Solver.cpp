//
// Created by Eliott on 05/12/2020.
//

#include "Bisection_Solver.hpp"
#include <cmath>
#include <iostream>

// Default Constructor
Bisection_Solver::Bisection_Solver()
        : NLE_Solver() {}

// Constructor
// Need to assert that f(left) * f(right) < 0 in the constructor
// and swap (or not) left & right such that f(left) < 0 and f(right) > 0
Bisection_Solver::Bisection_Solver(double (*function)(double), double LeftEdge, double RightEdge)
        : NLE_Solver(function)
        {
            double f_l = function(LeftEdge);
            double f_r = function(RightEdge);
            if (f_l * f_r < 0) {
                if ((f_l < 0) && (f_r > 0)) {
                    left = LeftEdge;
                    right = RightEdge;
                }
                else // Swap the edges ==> convenient for Solve() method (need f_l < 0 and f_r > 0)
                {
                    left = RightEdge;
                    right = LeftEdge;
                }
            }
            else // that is f_l * f_r >= 0
            {
                do
                {
                    std::cout << "Bisection edges are invalid, please enter other edges" << std::endl;
                    std::cout << "Left edge:";
                    std::cin >> LeftEdge;
                    std::cout << "Right edge:";
                    std::cin >> RightEdge;
                    f_l = f(LeftEdge);
                    f_r = f(RightEdge);
                } while (f_l * f_r >= 0);
                if ((f_l < 0) && (f_r > 0)) {
                    left = LeftEdge;
                    right = RightEdge;
                }
                else // Swap the edges ==> convenient for Solve() method (need f_l < 0 and f_r > 0)
                {
                    left = RightEdge;
                    right = LeftEdge;
                }
            }
        }

// Destructor
Bisection_Solver::~Bisection_Solver() {}

// Override of the solve function
double Bisection_Solver::Solve() const
{
    double mid = (left + right)/2.;
    double _left = left;
    double _right = right;
    double iter_count = 0;

    if (fabs(f(mid)) < tolerance) // mettre "< tolerance" à l'avenir (quand on change sa sigification)
    {
        return mid;
    }
    while(true)
    {
        iter_count += 1;
        mid = (_left + _right)/2.;
        if (fabs(f(mid)) < tolerance)
        {
            std::cout << "Iteration counter: " << iter_count << std::endl;
            break;
        }
        if (f(mid) < 0)
        {
            _left = mid;
        }
        else if (f(mid) > 0)
        {
            _right = mid;
        }
    }
    return mid;
}