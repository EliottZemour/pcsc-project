/*
 *
 * Test of the Chord Solver
 *
 * Created on: September 02, 2015 <--- Fill in the date here
 * 	   Author: Cyril Vallez <cyril.vallez@epfl.ch> <--- Fill in your name
 */

#include "Chord_Solver.hpp"
#include <iostream>
#include <cmath>

double function (double x)
{
    return x*x*x - 2.;
}

int main(int argc, char *argv[]) {

    double tol = 1e-3;
    int max_iter = 100;
    double (*func)(double x) = &function;
    double guess = 10;

    std::cerr << "Test cerr" << std::endl;
    std::cout << "Test cout" << std::endl;

    double res = Solve_Chord(max_iter, tol, guess, func, true);

    std::cout.setf(std::ios::scientific);
    std::cout.setf(std::ios::showpos);
    std::cout.precision(15);

    std::cout << "The numerical result is " << res << std::endl;
    std::cout << "The exact result is " << pow(2., 1./3.) << std::endl;

  return 0;
}
