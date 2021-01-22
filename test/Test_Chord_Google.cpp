//
// Created by Eliott on 21/01/2021.
//

#include "../src/Chord_Solver.hpp"
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

TEST(TestChord, xcube)
{
    double (*func)(double x) = &function_xcube;
    double tol = 1e-3;
    int max_iter = 100;
    double guess = 10;
    double res = Solve_Chord(max_iter, tol, guess, func, true);
    double diff = std::fabs(res - pow(2., 1./3.));

    EXPECT_LE(diff, 1e-3);
}

TEST(TestChord, sinus)
{
    double (*func)(double x) = &function_sinus;
    double tol = 1e-3;
    int max_iter = 100;
    double guess = 10;
    double res = Solve_Chord(max_iter, tol, guess, func, true);
    double f_root = std::fabs(func(res));

    EXPECT_LE(f_root, 1e-3);
}

TEST(TestChord, polynomial)
{
    double (*func)(double x) = &function_polynomial;
    double tol = 1e-3;
    int max_iter = 100;
    double guess = -0.05;
    double res = Solve_Chord(max_iter, tol, guess, func, false);
    double f_root = std::fabs(func(res));

    EXPECT_LE(f_root, 1e-3);
}


TEST(TestChord, complex)
{
    double (*func)(double x) = &function_complex;
    double tol = 1e-3;
    int max_iter = 100;
    double guess = 1.01;
    double res = Solve_Chord(max_iter, tol, guess, func, false);
    double f_root = std::fabs(func(res));

    EXPECT_LE(f_root, 1e-3);
}




int main(int argc, char *argv[]) {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}