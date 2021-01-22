/*
 *
 * Test of the Bisection Solver
 * Works with Google Test framework
 *
 */

#include "../src/Bisection_Solver.hpp"
#include <iostream>
#include <cmath>



double function_xcube (double x)
{
    return x*x*x - 2.;
}

double function_sinus (double x) {
    return sin(x) - 1 / 2.;
}

int main(int argc, char *argv[])
{

    std::cout.setf(std::ios::scientific);
    std::cout.setf(std::ios::showpos);
    std::cout.precision(15);

    double (*func)(double x) = &function_xcube;
    double res = Solve_Bisection(func, -1., -2.);

    std::cout << "The numerical result is " << res << std::endl;
    std::cout << "The exact result is " << pow(2., 1./3.) << std::endl;
    std::cout << "Error = " << fabs(res - pow(2., 1./3.)) << std::endl;
    return 0;

}

