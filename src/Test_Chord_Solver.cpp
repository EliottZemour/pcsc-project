/*
 *
 * Test of the Chord Solver
 *
 * Created on: September 02, 2015 <--- Fill in the date here
 * 	   Author: Cyril Vallez <cyril.vallez@epfl.ch> <--- Fill in your name
 */

#include "NLE_Solver.hpp"
#include "Chord_Solver.hpp"
#include <iostream>
#include <cmath>

double function (double x)
{
    return x*x*x - 2.;
}

int main(int argc, char *argv[]) {

    double tol = 1e-3;
    int max_iter = 200;
    double (*func)(double x) = &function;
    double guess = 2.9;

    NLE_Solver* solver = new Chord_Solver(max_iter, tol, guess, func);

    double res = solver->Solve();

    std::cout.setf(std::ios::scientific);
    std::cout.setf(std::ios::showpos);
    std::cout.precision(15);

    std::cout << "The numerical result is " << res << std::endl;
    std::cout << "The exact result is " << pow(2., 1./3.) << std::endl;


  return 0;
}
