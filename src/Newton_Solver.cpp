/*
* Class for solving NLE using Newton method
        *
        * 	   Author: Cyril Vallez <cyril.vallez@epfl.ch>
*/

#include "Newton_Solver.hpp"
#include "exc/DivBy0Exception.hpp"
#include "exc/InitializationException.hpp"
#include <string>
#include <cmath>
#include <iostream>
#include <cstdlib>

// Default Constructor
Newton_Solver::Newton_Solver()
: NLE_Solver(), f_prime(nullptr) {}

// Constructor
Newton_Solver::Newton_Solver(double initial_guess, double (*fun)(double x), double (*fun_p)(double x))
: NLE_Solver(initial_guess, fun), f_prime(fun_p)
{
    if (fun_p == nullptr)
    {
        std::string problem("The pointer on the derivative of the function to solve for is null");
        std::string variable("f_prime");
        throw InitializationException(problem, variable);
    }
}

// Constructor
Newton_Solver::Newton_Solver(int iterations, double epsilon, double initial_guess, double (*fun)(double x),
                             double (*fun_p)(double x))
: NLE_Solver(iterations, epsilon, initial_guess, fun), f_prime(fun_p)
{
    if (fun_p == nullptr)
    {
        std::string problem("The pointer on the derivative of the function to solve for is null");
        std::string variable("f_prime");
        throw InitializationException(problem, variable);
    }
}

// Destructor
Newton_Solver::~Newton_Solver() {}

// Override of the solve function
double Newton_Solver::Solve() const
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
        i += 1;

        if (fabs(next-current)<tolerance)
        {
            std::cout << "Stopped because the solution has converged within the given tolerance" << std::endl;
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

NLE_Solver* Initialize_Newton (double initial_guess, double (*fun)(double x), double (*fun_p)(double x))
{
    NLE_Solver* solver = nullptr;

    try
    {
        solver = new Newton_Solver(initial_guess, fun, fun_p);
    }
    catch (InitializationException &error)
    {
        error.PrintDebug();
        std::cerr << "Please re-run providing a correct pointer" << std::endl;
        exit(EXIT_FAILURE);
    }

    return solver;
}

NLE_Solver* Initialize_Newton (int iterations, double epsilon, double initial_guess, double (*fun)(double x),
                               double (*fun_p)(double x))
{
    NLE_Solver* solver = nullptr;

    try
    {
        solver = new Newton_Solver(iterations, epsilon, initial_guess, fun, fun_p);
    }
    catch (InitializationException &error)
    {
        error.PrintDebug();

        if (error.GetVariable() == "iterations")
        {
            int iter = 0;
            std::cout << "Please enter a valid number of iterations :" << std::endl;
            std::cin >> iter;
            return Initialize_Newton(iter, epsilon, initial_guess, fun, fun_p);
        }
        if (error.GetVariable() == "epsilon")
        {
            double eps = 0.;
            std::cout << "Please enter a valid tolerance :" << std::endl;
            std::cin >> eps;
            return Initialize_Newton(iterations, eps, initial_guess, fun, fun_p);
        }
        else
        {
            std::cerr << "Please re-run providing a correct pointer" << std::endl;
            exit(EXIT_FAILURE);
        }
    }

    return solver;
}

double Solve_Newton (double initial_guess, double (*fun)(double x), double (*fun_p)(double x))
{
    NLE_Solver* solver = Initialize_Newton(initial_guess, fun, fun_p);
    double solution = -1;

    try
    {
        solution = solver->Solve();
    }
    catch (Exception &error)
    {
        error.PrintDebug();
    }
    delete solver;
    return solution;
}

double Solve_Newton (int iterations, double epsilon, double initial_guess, double (*fun)(double x),
                     double (*fun_p)(double x))
{
    NLE_Solver* solver = Initialize_Newton(iterations, epsilon, initial_guess, fun, fun_p);
    double solution = -1;

    try
    {
        solution = solver->Solve();
    }
    catch (Exception &error)
    {
        error.PrintDebug();
    }
    delete solver;
    return solution;
}
