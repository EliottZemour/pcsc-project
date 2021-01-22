/*
 *
 * Test of the Newton Solver for systems
 *
 * Created on: September 02, 2015 <--- Fill in the date here
 * 	   Author: Cyril Vallez <cyril.vallez@epfl.ch> <--- Fill in your name
 */

#include "../src/Newton_System_Solver.hpp"
#include <iostream>
#include <cmath>
#include <gtest/gtest.h>
#include "../src/exc/DivBy0Exception.hpp"

vector function (vector x)
{
    vector res(2);
    res[0] = exp(x[0]) + x[1] - 4.;
    res[1] = x[1]*x[1] - 4.;

    return res;
}

matrix inv_jacobian (vector x)
{
    matrix res = {{0., 0.}, {0., 0.}};

    res[0][0] = 1./exp(x[0]);
    res[0][1] = -1./2./x[1]/exp(x[0]);
    res[1][0] = 0.;
    res[1][1] = 1./2./x[1];

    return res;
}

TEST(TestSystemNewton, easy22)
{
    double tol = 1e-5;
    int max_iter = 1000;
    vector (*func)(vector x) = &function;
    matrix (*inv_jaco)(vector x) = &inv_jacobian;
    vector guess(2, 15);

    NLS_Solver* solver = new Newton_System_Solver(max_iter, tol, guess, func, inv_jaco);
    vector res = solver->Solve();
    delete solver;

    ASSERT_NEAR(res[0], log(2), 1e-5);
    ASSERT_NEAR(res[1], 2., 1e-5);
}

int main(int argc, char *argv[]) {

    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}
