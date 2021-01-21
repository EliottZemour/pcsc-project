/*
* Class for solving NLE using Newton method
        *
        * 	   Author: Cyril Vallez <cyril.vallez@epfl.ch>
*/

#include "Newton_System_Solver.hpp"
#include <string>
#include <iostream>
#include <cstdlib>

// Constructor
Newton_System_Solver::Newton_System_Solver(int dim, vector (*fun)(vector), matrix (*inv_jaco)(vector))
: NLS_Solver(dim, fun)
{
    SetInverseJacobian(inv_jaco);
}

Newton_System_Solver::Newton_System_Solver(double initial_guess, vector (*fun)(vector), matrix (*inv_jaco)(vector))
: NLS_Solver(initial_guess, fun)
{
    SetInverseJacobian(inv_jaco);
}

Newton_System_Solver::Newton_System_Solver(int iterations, double epsilon, vector initial_guess, vector (*fun)(vector),
                                           matrix (*inv_jaco)(vector))
: NLS_Solver(iterations, epsilon, initial_guess, fun)
{
    SetInverseJacobian(inv_jaco);
}

// Destructor
Newton_System_Solver::~Newton_System_Solver() {}

// Override of the solve function
vector Newton_System_Solver::Solve() const
{
    vector current = guess;
    vector next(dimension, 0.);
    int i = 0;

    while (true)
    {
        next = current - inv_jacobian(current)*f(current);
        i += 1;

        if (norm(f(next)-f(current))<tolerance)
        {
            std::cout << "Stopped because the solution has converged within the given tolerance" << std::endl;
            break;
        }
        if (i>=max_iter)
        {
            std::cout << "Stopped because maximum number of iterations was reached" << std::endl;
            std::cout << "The last approximation of the solution is returned" << std::endl;
            break;
        }

        current = next;
    }

    current = next;
    return current;
}

// Setter
void Newton_System_Solver::SetInverseJacobian(matrix (*inv_jaco)(vector))
{
    inv_jacobian = inv_jaco;

    if (inv_jacobian == nullptr)
    {
        std::string problem("The pointer on the inverse jacobian is null");
        std::cout << "Problem : " << problem << std::endl;
        std::cout << "Please re-run providing a correct pointer" << std::endl;
        exit(EXIT_FAILURE);
    }

    TestDimensionInvJacobian();
}

// Test dimension
void Newton_System_Solver::TestDimensionInvJacobian() const
{
    matrix foo = inv_jacobian(guess);

    if (dimension != foo.size())
    {
        std::string problem("The inverse jacobian does not match the dimension of the system !");
        std::cout << "Problem : " << problem << std::endl;
        std::cout << "Please re-run providing correct dimensions" << std::endl;
        exit(EXIT_FAILURE);
    }

    for (int i(0); i<foo.size(); ++i)
    {
        if (dimension != foo[i].size())
        {
            std::string problem("The inverse jacobian is not a squared matrix !");
            std::cout << "Problem : " << problem << std::endl;
            std::cout << "Please re-run providing correct dimensions" << std::endl;
            exit(EXIT_FAILURE);
        }
    }
}


// ########################## External functions #################################


