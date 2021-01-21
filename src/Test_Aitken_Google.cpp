//
// Created by Eliott on 21/01/2021.
//

#include "Aitken_Accelerator.hpp"
#include "Chord_Solver.hpp"
#include "Newton_Solver.hpp"
#include <chrono>
#include <iostream>
#include <cmath>
#include <gtest/gtest.h>
using namespace std::chrono;


double function_sinus (double x)
{
    return sin(x) - 1/2.;
}

double function_sinus_prime (double x)
{
    return cos(x);
}

TEST(TestAitken, acc_chord)
{
    double (*func)(double x) = &function_sinus;
    double tol = 1e-3;
    int max_iter = 100;
    double guess = 10;

    auto start = high_resolution_clock::now();
    double res;
    for (int i=0; i<100000; ++i)
    {
        res = Solve_Chord(max_iter, tol, guess, func, false);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    auto start_acc = high_resolution_clock::now();
    double res_acc;
    for (int i=0; i<100000; ++i)
    {
        res_acc = Solve_Chord(max_iter, tol, guess, func, true);
    }
    auto stop_acc = high_resolution_clock::now();
    auto duration_acc = duration_cast<nanoseconds>(stop_acc - start_acc);


    EXPECT_LE(duration_acc.count(), duration.count());

}

TEST(TestAitken, acc_newton)
{
    double (*func)(double x) = &function_sinus;
    double (*func_p)(double x) = &function_sinus_prime;
    double tol = 1e-3;
    int max_iter = 100;
    double guess = 10;

    auto start = high_resolution_clock::now();
    double res;
    for (int i=0; i<100000; ++i)
    {
        res = Solve_Newton(max_iter, tol, guess, func, func_p, false);
    }
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    auto start_acc = high_resolution_clock::now();
    double res_acc;
    for (int i=0; i<100000; ++i)
    {
        res_acc = Solve_Newton(max_iter, tol, guess, func, func_p, false);
    }
    auto stop_acc = high_resolution_clock::now();
    auto duration_acc = duration_cast<nanoseconds>(stop_acc - start_acc);


    EXPECT_LE(duration_acc.count(), duration.count());
}


int main(int argc, char *argv[]) {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}