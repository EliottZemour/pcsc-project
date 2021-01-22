//
// Created by Eliott on 05/12/2020.
//

#include "Bisection_Solver.hpp"
#include <cmath>
#include <iostream>
#include "exc/DivBy0Exception.hpp"

/// Default Constructor
Bisection_Solver::Bisection_Solver()
        : NLE_Solver() {}

/// Constructor
/// Need to assert that f(left) * f(right) < 0 in the constructor
/// and swap (or not) left & right such that f(left) < 0 and f(right) > 0
Bisection_Solver::Bisection_Solver(double (*function)(double), double LeftEdge, double RightEdge)
        : NLE_Solver(function)
        {
            SetEdges(LeftEdge, RightEdge);
        }

Bisection_Solver::Bisection_Solver(int maxiter, double epsilon, double (*function)(double), double LeftEdge, double RightEdge)
        :NLE_Solver(maxiter, epsilon, 0., function)
        {
            SetEdges(LeftEdge, RightEdge);
        }

/// Destructor
Bisection_Solver::~Bisection_Solver() {}

/// Override of the solve function
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
            std::cout << "Stopped because the solution has converged within the given tolerance" << std::endl;
            std::cout << "iteration #" << iter_count << std::endl;
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
        if (iter_count>=max_iter)
        {
            std::cout << "Stopped because maximum number of iterations was reached" << std::endl;
            std::cout << "The last approximation of the solution is returned" << std::endl;
            break;
        }
    }
    return mid;
}

/// Setters
void Bisection_Solver::SetEdges(double LeftEdge, double RightEdge) {
    double f_l = f(LeftEdge);
    double f_r = f(RightEdge);
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
            std::string problem("Bisection edges are invalid: f(LeftEdge) * f(RightEdge) >= 0");
            std::cout << "Problem : " << problem << std::endl;
            std::cout << "Please enter other edges" << std::endl;
            std::cout << "Left edge: " << std::endl;
            std::cin >> LeftEdge;
            std::cout << "Right edge: " << std::endl;
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



///################################ External function #################################

double Solve_Bisection(double (*function)(double), double LeftEdge, double RightEdge) {
    NLE_Solver* solver = new Bisection_Solver(function, LeftEdge, RightEdge);
    double solution = -1;
    solution = solver->Solve();

    delete solver;
    return solution;
}

double Solve_Bisection(int maxiter, double epsilon, double (*function)(double), double LeftEdge, double RightEdge) {
    NLE_Solver* solver = new Bisection_Solver(maxiter, epsilon, function, LeftEdge, RightEdge);
    double solution = -1;
    solution = solver->Solve();

    delete solver;
    return solution;
}
