//
// Created by Eliott on 07/12/2020.
//

#ifndef AITKEN_ACCELERATOR_H
#define AITKEN_ACCELERATOR_H

/*
 * Aitken series acceleration
 * Useful for accelerating the convergence of a sequence that is converging linearly
 */

class Aitken_Accelerator {

public:
    // Acceleration method
    double Accelerate(double current, double next, double nextnext) const;


};


#endif //AITKEN_ACCELERATOR_H
