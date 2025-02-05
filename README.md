## PCSC - Project 5: Non-linear systems

Authors: [Cyril Vallez](mailto:cyril.vallez@epfl.ch), [Eliott Zemour](mailto:eliott.zemour@epfl.ch).   
GROUP 7.   
_Implementation of numerical methods for the solution of nonlinear equations (NLE)._  

The numerical methods implemented are:
* Bisection,
* Fixed point methods:
  * Chord,
  * Newton

And an acceleration feature through Aitken's delta squared process is also implemented according to this [source](https://en.wikipedia.org/wiki/Aitken%27s_delta-squared_process).  
The main source for this project can be found at [https://onlinelibrary.wiley.com/doi/pdf/10.1002/9781118673515.app8](https://onlinelibrary.wiley.com/doi/pdf/10.1002/9781118673515.app8).

Finally, this project includes an extension to systems of nonlinear equations (NLS) solved by the Newton method in n-dimensions.

## Requirements
This project relies on the following librairies:
* GoogleTest
* cmath
* chrono
* string
* iostream
* cstdlib

## Architecture of the project

![Imgur](https://i.imgur.com/Oi06fhP.png)

A Doxygen generated documentation is also available within the 'html' folder of the repository.

## How to use
There are several ways to use the numerical methods implemented:
* Either though out of class methods Solve_Newton, Solve_Chord, Solve_Bisection are designed to instantiate the NLE Solver objects, call their own solve function to obtain the solution and then delete them.
Code example:
```
    double function(double x)
    {
    // definition of function
    }
    
    double (*func)(double x) = &function;
    double LeftEdge = -5.;
    double RightEdge = 5.;
    double solution = Solve_Bisection(func, LeftEdge, RightEdge);
```
* Either by dynamically allocating memory for a NLE Solver object and directly calling its solve function. In this case the user is responsible of deleting the object.
Code example:
```
    double function(double x)
    {
    // definition of function
    }
    
    double (*func)(double x) = &function;
    double LeftEdge = -5.;
    double RightEdge = 5.;
    NLE_Solver* solver = new Bisection_Solver(func, LeftEdge, RightEdge);
    double solution = solver->Solve();
    delete solver;
```
