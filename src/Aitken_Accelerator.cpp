
#include "Aitken_Accelerator.hpp"

/// Acceleration method
/// Taken to be the most robust to rounding errors
/// according to https://en.wikipedia.org/wiki/Aitken%27s_delta-squared_process
double Accelerate(double current, double next, double nextnext)
{
    double acc_next;
    double delta = next - current;
    double delta_next = nextnext - next;
    acc_next = next + 1./(1./delta_next - 1./delta);
    return acc_next;
}
