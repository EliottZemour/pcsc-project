//
// Created by Eliott on 21/01/2021.
//

#include "Newton_Solver.hpp"
#include <iostream>
#include <cmath>
#include <gtest/gtest.h>
#include "exc/DivBy0Exception.hpp"

double function_xcube (double x)
{
    return x*x*x - 2.;
}

double function_xcube_prime (double x)
{
    return 3*x*x;
}


TEST(TestNewton, xcube)
{
    double (*func)(double x) = &function_xcube;
    double (*func_p)(double x) = &function_xcube_prime;
    double tol = 1e-3;
    int max_iter = 100;
    double guess = 10;
    double res = Solve_Newton(max_iter, tol, guess, func, func_p, true);
    double diff = std::fabs(res - pow(2., 1./3.));

    EXPECT_LE(diff, 1e-3);
}

TEST(TestNewton, nullderivative)
{
    double (*func)(double x) = &function_xcube;
    double (*func_p)(double x) = &function_xcube_prime;
    double tol = 1e-3;
    int max_iter = 100;
    double guess = 0; // the func_p(guess) = 0 => expect DivBy0Exception

    NLE_Solver* solver = new Newton_Solver(max_iter, tol, guess, func, func_p);

    ASSERT_THROW(solver->Solve(), DivBy0Exception);
}


int main(int argc, char *argv[]) {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}