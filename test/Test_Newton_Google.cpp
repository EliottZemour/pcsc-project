//
// Created by Eliott on 21/01/2021.
//

#include "../src/Newton_Solver.hpp"
#include <iostream>
#include <cmath>
#include <gtest/gtest.h>
#include "../src/exc/DivBy0Exception.hpp"

double function_xcube (double x)
{
    return x*x*x - 2.;
}

double function_xcube_prime (double x)
{
    return 3*x*x;
}

double function_sinus (double x)
{
    return sin(x)*sin(x) - 1./2.;
}

double function_sinus_prime (double x)
{
    return 2*cos(x)*sin(x);
}

double function_polynomial (double x)
{
    return pow(x,6) + pow(x,5);
}

double function_polynomial_prime (double x)
{
    return 6*pow(x,5) + 5*pow(x,4);
}

double function_complex (double x)
{
    return exp(-1*x*x) + cos(x) - 1.5;
}

double function_complex_prime (double x)
{
    return -2 * x * exp(-1*x*x) - sin(x);
}


TEST(TestNewton, xcube)
{
    /*
     * In this test, we know the unique solution to x^3 - 2 = 0
     * Therefore, we test the difference between the root and the exact sol.
    */
    double (*func)(double x) = &function_xcube;
    double (*func_p)(double x) = &function_xcube_prime;
    double tol = 1e-3;
    int max_iter = 100;
    double guess = 10;
    double res = Solve_Newton(max_iter, tol, guess, func, func_p, false);
    double diff = std::fabs(res - pow(2., 1./3.));

    EXPECT_LE(diff, 1e-3);
}

TEST(TestNewton, nullderivative)
{
    /*
     * In this test, want to check that a null derivative throws an exception
     * The expected exception is a DivBy0Exception
    */
    double (*func)(double x) = &function_xcube;
    double (*func_p)(double x) = &function_xcube_prime;
    double tol = 1e-3;
    int max_iter = 100;
    double guess = 0; // so that func_p(guess) = 0 => expect DivBy0Exception

    NLE_Solver* solver = new Newton_Solver(max_iter, tol, guess, func, func_p);

    ASSERT_THROW(solver->Solve(), DivBy0Exception);

    delete solver;
}

TEST(TestNewton, sinus)
{
    /*
     * In this test, there are multiple roots to the function_sinus.
     * The root towards which the solver converges is determined by the initial guess
     * Therefore, we test that abs(f(root_found)) is close enough to zero
     * instead of comparing with the exact solution.
    */
    double (*func)(double x) = &function_sinus;
    double (*func_p)(double x) = &function_sinus_prime;
    double tol = 1e-3;
    int max_iter = 100;
    double guess = 1;
    double res = Solve_Newton(max_iter, tol, guess, func, func_p, false);
    double f_root = std::fabs(func(res));
    EXPECT_LE(f_root, 1e-3);
}

TEST(TestNewton, complex)
{
    /*
     * In this test, we test that abs(f(root_found)) is close enough to zero
     * instead of comparing with the exact solution.
    */
    double (*func)(double x) = &function_complex;
    double (*func_p)(double x) = &function_complex_prime;
    double tol = 1e-3;
    int max_iter = 100;
    double guess = 1.;
    double res = Solve_Newton(max_iter, tol, guess, func, func_p, false);
    double f_root = std::fabs(func(res));
    EXPECT_LE(f_root, 1e-3);
}

TEST(TestNewton, polynomial)
{
    /*
     * In this test, we test that abs(f(root_found)) is close enough to zero
     * instead of comparing with the exact solution.
    */
    double (*func)(double x) = &function_polynomial;
    double (*func_p)(double x) = &function_polynomial_prime;
    double tol = 1e-3;
    int max_iter = 100;
    double guess = -101;
    double res = Solve_Newton(max_iter, tol, guess, func, func_p, false);
    double f_root = std::fabs(func(res));
    EXPECT_LE(f_root, 1e-3);
}



int main(int argc, char *argv[]) {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}