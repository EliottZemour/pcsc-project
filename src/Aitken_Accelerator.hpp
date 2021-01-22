
#ifndef AITKEN_ACCELERATOR_H
#define AITKEN_ACCELERATOR_H

/**
 * Aitken series acceleration
 * Useful for accelerating the convergence of a sequence that is converging linearly
 */

/// Acceleration method
double Accelerate(double current, double next, double nextnext);



#endif //AITKEN_ACCELERATOR_H
