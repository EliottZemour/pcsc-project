/*
* Class for solving NLE using Newton method
        *
        * 	   Author: Cyril Vallez <cyril.vallez@epfl.ch>
*/

#include "Newton_Solver.hpp"
#include "exc/DivBy0Exception.hpp"
#include <string>
#include <cmath>
#include <iostream>
#include <cstdlib>

// Default Constructor
Newton_Solver::Newton_Solver()
: NLE_Solver(), f_prime(nullptr) {}

// Constructor
Newton_Solver::Newton_Solver(double initial_guess, double (*fun)(double x), double (*fun_p)(double x))
: NLE_Solver(initial_guess, fun)
{
    SetDerivative(fun_p);
}

// Constructor
Newton_Solver::Newton_Solver(int iterations, double epsilon, double initial_guess, double (*fun)(double x),
                             double (*fun_p)(double x))
: NLE_Solver(iterations, epsilon, initial_guess, fun)
{
    SetDerivative(fun_p);
}

// Destructor
Newton_Solver::~Newton_Solver() {}


//Setter
void Newton_Solver::SetDerivative(double (*fun_p)(double))
{
    f_prime = fun_p;

    if (f_prime == nullptr)
    {
        std::string problem("The pointer on the derivative of the function to solve for is null");
        std::cerr << "Problem : " << problem << std::endl;
        std::cerr << "Please re-run providing a correct pointer" << std::endl;
        std::cerr.flush();
        exit(EXIT_FAILURE);
    }
}

// Override of the solve function
double Newton_Solver::Solve(bool acc) const
{
    double current = guess;
    double next = 0.;
    int i = 0;

    while (true)
    {
        double denominator = f_prime(current);

        if (fabs(denominator) < 1e-15 )
        {
            std::string error("Evaluation of the next approximation is diverging");
            throw DivBy0Exception(error);
        }

        next = current - f(current)/denominator;
        if(acc)
        {
            double denominator_acc = f_prime(next);
            double nextnext = next - f(next)/denominator;
            next = Accelerate(current, next, nextnext);
        }

        i += 1;

        if (fabs(next-current)<tolerance)
        {
            std::cout << "Stopped because the solution has converged within the given tolerance" << std::endl;
            std::cout << "iteration #" << i << std::endl;
            break;
        }
        if (i>=max_iter)
        {
            std::cerr << "Stopped because maximum number of iterations was reached" << std::endl;
            std::cout << "The last approximation of the solution is returned" << std::endl;
            break;
        }

        current = next;
    }

    current = next;
    return current;
}



double Solve_Newton (double initial_guess, double (*fun)(double x), double (*fun_p)(double x), bool acc)
{
    NLE_Solver* solver = new Newton_Solver(initial_guess, fun, fun_p);
    double solution = -1;

    try
    {
        solution = solver->Solve(acc);
    }
    catch (Exception &error)
    {
        error.PrintDebug();
    }
    delete solver;
    return solution;
}

double Solve_Newton (int iterations, double epsilon, double initial_guess, double (*fun)(double x),
                     double (*fun_p)(double x), bool acc)
{
    NLE_Solver* solver = new Newton_Solver(iterations, epsilon, initial_guess, fun, fun_p);
    double solution = -1;

    try
    {
        solution = solver->Solve(acc);
    }
    catch (Exception &error)
    {
        error.PrintDebug();
    }
    delete solver;
    return solution;
}
