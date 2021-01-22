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
    double diff = std::fabs(func(res));
    // double diff = std::fabs(res - M_PI/6.);

    EXPECT_LE(diff, 1e-3);
}

// struct badfunc : public std::exception {};

/* TEST(TestChord, nullptr_except)
{
    double (*func)(double x) = nullptr;
    double tol = 1e-3;
    int max_iter = 100;
    double guess = 10;

    ASSERT_THROW(Solve_Chord(max_iter, tol, guess, func, true), badfunc);
}*/

int main(int argc, char *argv[]) {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}