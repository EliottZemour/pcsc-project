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

double function_complex (double x)
{
    return exp(-1*x*x) + cos(x) - 1.5;
}

double function_polynomial (double x)
{
    return pow(x,6) + pow(x,5);
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
    double f_root = std::fabs(func(res));
    EXPECT_LE(f_root, 1e-3);
}

TEST(TestBisection, polynomial)
{
    double (*func)(double x) = &function_polynomial;
    double res = Solve_Bisection(func, -0.7, 100.);
    double f_root = std::fabs(func(res));
    EXPECT_LE(f_root, 1e-3);
}

TEST(TestBisection, complex)
{
    double (*func)(double x) = &function_complex;
    double res = Solve_Bisection(func, 0., 100.);
    double f_root = std::fabs(func(res));
    EXPECT_LE(f_root, 1e-3);
}

int main(int argc, char *argv[]) {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
