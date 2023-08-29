#include "func_tools.h"

bool compare_double_with_zero (double param){

    static double EPSILON = 1e-10;

    if (fabs(param) < EPSILON){

        return true;
    }

    return false;
}
