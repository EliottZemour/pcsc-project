/*
 *
 * Test of the Newton Solver for systems
 *
 * Created on: September 02, 2015 <--- Fill in the date here
 * 	   Author: Cyril Vallez <cyril.vallez@epfl.ch> <--- Fill in your name
 */

#include "Newton_System_Solver.hpp"
#include <iostream>
#include <cmath>

vector function (vector x)
{
    vector res(2);
    res[0] = exp(x[0]) + x[1] - 4.;
    res[1] = x[1]*x[1] - 4.;

    return res;
}

matrix inv_jacobian (vector x)
{
    matrix res = {{0., 0.}, {0., 0.}};

    res[0][0] = 1./exp(x[0]);
    res[0][1] = -1./2./x[1]/exp(x[0]);
    res[1][0] = 0.;
    res[1][1] = 1./2./x[1];

    return res;
}

int main(int argc, char *argv[]) {

    double tol = 1e-5;
    int max_iter = 1000;
    vector (*func)(vector x) = &function;
    matrix (*inv_jaco)(vector x) = &inv_jacobian;
    vector guess(2, 15);

    NLS_Solver* solver = new Newton_System_Solver(max_iter, tol, guess, func, inv_jaco);
    vector res = solver->Solve();

    std::cout.setf(std::ios::scientific);
    std::cout.setf(std::ios::showpos);
    std::cout.precision(15);

    std::cout << "The exact result is :" << std::endl;
    std::cout << log(2) << std::endl;
    std::cout << 2. << std::endl << std::endl;

    std::cout << "The numerical result is " << std::endl;
    std::cout << res[0] << std::endl;
    std::cout << res[1] << std::endl << std::endl;

    delete solver;

  return 0;
}
