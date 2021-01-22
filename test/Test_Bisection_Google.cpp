/*
 *
 * Test of the Bisection Solver
 * Works with Google Test framework
 *
 */

#include "../src/Bisection_Solver.hpp"
#include <iostream>
#include <cmath>
#include <gtest/gtest.h>


double function_xcube (double x)
{
    return x*x*x - 2.;
}

double function_sinus (double x)
{
    return sin(x) - 1/2.;
}

TEST(TestBisection, xcube)
{
    double (*func)(double x) = &function_xcube;
    double res = Solve_Bisection(func, -1, 4);
    double diff = std::fabs(res - pow(2., 1./3.));
    EXPECT_LE(diff, 1e-3);
}

TEST(TestBisection, sinus)
{
    double (*func)(double x) = &function_sinus;
    double res = Solve_Bisection(func, -M_PI/2., M_PI/2.);
    double diff = std::fabs(res - M_PI/6.);
    EXPECT_LE(diff, 1e-3);
}

int main(int argc, char *argv[]) {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

//    std::cout.setf(std::ios::scientific);
//    std::cout.setf(std::ios::showpos);
//    std::cout.precision(15);
//
//    std::cout << "The numerical result is " << res << std::endl;
//    std::cout << "The exact result is " << pow(2., 1./3.) << std::endl;
//    std::cout << "Error = " << fabs(res - pow(2., 1./3.)) << std::endl;
// return 0;

}
