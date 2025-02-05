/*
 * Aitken accelerator testing file
 * In order to reproduce the results mentioned in the report,
 * comment the output lines in the Solve methods for Chord and Newton solver
 * Finally, uncomment the google tests from line 53 to 116
*/

#include "../src/Aitken_Accelerator.hpp"
#include "../src/Chord_Solver.hpp"
#include "../src/Newton_Solver.hpp"
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

TEST(TestAitken, chord_acc)
{
    double (*func)(double x) = &function_sinus;
    double tol = 1e-3;
    int max_iter = 100;
    double guess = 10;
    double res_acc = Solve_Chord(max_iter, tol, guess, func, true);
    double f_root_acc = std::fabs(func(res_acc));

    EXPECT_LE(f_root_acc, 1e-3);
}

TEST(TestAitken, newton_acc)
{
    double (*func)(double x) = &function_sinus;
    double (*func_p)(double x) = &function_sinus_prime;
    double tol = 1e-3;
    int max_iter = 100;
    double guess = 10;
    double res_acc = Solve_Newton(max_iter, tol, guess, func, func_p, true);
    double f_root_acc = std::fabs(func(res_acc));

    EXPECT_LE(f_root_acc, 1e-3);
}

 /*
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
 */


int main(int argc, char *argv[]) {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}