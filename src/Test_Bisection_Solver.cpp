/*
 *
 * Test of the Bisection Solver
 *
 */

#include "Bisection_Solver.hpp"
#include <iostream>
#include <cmath>

double function (double x)
{
    return x*x*x - 2.;
}

int main(int argc, char *argv[]) {

    double (*func)(double x) = &function;
    double res = Solve_Bisection(func, -1e10, 1.2);

    std::cout.setf(std::ios::scientific);
    std::cout.setf(std::ios::showpos);
    std::cout.precision(15);

    std::cout << "The numerical result is " << res << std::endl;
    std::cout << "The exact result is " << pow(2., 1./3.) << std::endl;
    std::cout << "Error = " << fabs(res - pow(2., 1./3.)) << std::endl;

  return 0;
}
