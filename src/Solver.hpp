/*
* Base class for all solvers
        *
        * 	   Author: Cyril Vallez <cyril.vallez@epfl.ch>
*/

#ifndef SOLVER_H
#define SOLVER_H

class Solver
{
protected:
    int max_iter;
    double tolerance;

public:
    // Constructor and destructor
    Solver();
    Solver(int iterations, double epsilon);
    virtual ~Solver();

    // Setters
    void SetMaxIter(int iter);
    void SetTolerance(double epsilon);

    // Getters
    int GetMaxIter () const {return max_iter;}
    double GetTolerance() const {return tolerance;}

};

#endif