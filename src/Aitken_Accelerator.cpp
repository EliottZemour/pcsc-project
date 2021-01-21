//
// Created by Eliott on 07/12/2020.
//

#include "Aitken_Accelerator.hpp"

// Acceleration method
double Accelerate(double current, double next, double nextnext)
{
    double acc_next;
    double delta = next - current;
    double delta_next = nextnext - next;
    double deltadelta = delta_next - delta;
    // acc_next = (current * nextnext - next * next)/(current + nextnext - 2*next);
    // acc_next = current - (delta * delta)/ deltadelta;
    acc_next = next + 1./(1./delta_next - 1./delta);
    return acc_next;
}
