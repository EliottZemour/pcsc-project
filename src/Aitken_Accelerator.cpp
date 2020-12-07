//
// Created by Eliott on 07/12/2020.
//

#include "Aitken_Accelerator.h"

// Acceleration method
double Aitken_Accelerator::Accelerate(double current, double next, double nextnext) const {
    double acc_next;
    acc_next = (current * nextnext - next * next)/(current + nextnext - 2*next);
    return acc_next;
}
