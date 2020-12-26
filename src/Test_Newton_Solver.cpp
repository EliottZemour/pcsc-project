/*
 *
 * Test of the Newton Solver
 *
 * Created on: September 02, 2015 <--- Fill in the date here
 * 	   Author: Cyril Vallez <cyril.vallez@epfl.ch> <--- Fill in your name
 */

#include "Newton_Solver.hpp"
#include <iostream>
#include <cmath>

double function (double x)
{
    return x*x*x - 2.;
}

double function_prime (double x)
{
    return 3*x*x;
}

int main(int argc, char *argv[]) {

    double tol = -2;
    int max_iter = -5;
    double (*func)(double x) = &function;
    double (*func_p)(double x) = &function_prime;
    double guess = 10;

    double res = Solve_Newton(max_iter, tol, guess, func, func_p);

    std::cout.setf(std::ios::scientific);
    std::cout.setf(std::ios::showpos);
    std::cout.precision(15);

    std::cout << "The numerical result is " << res << std::endl;
    std::cout << "The exact result is " << pow(2., 1./3.) << std::endl;

  return 0;
}
