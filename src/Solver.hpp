

#ifndef SOLVER_H
#define SOLVER_H

/**
* Base class for all solvers
*/
class Solver
{
protected:
    int max_iter;
    double tolerance;

public:
    /// Constructor and destructor
    Solver();
    Solver(int iterations, double epsilon);
    virtual ~Solver();

    /// Setters
    void SetMaxIter(int iter);
    void SetTolerance(double epsilon);

    /// Getters
    int GetMaxIter () const {return max_iter;}
    double GetTolerance() const {return tolerance;}

};

#endif