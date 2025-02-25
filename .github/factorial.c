#include "factorial.h"

ulong_long_func_ptr factorial_provider = factorial;

// a factorial "provider" (TINY CHANGE)
unsigned long long factorial(unsigned int of_num) {
    if (of_num < 2)
        return 1; // factorials of less than 2 (0 and 1) are both 1

    return of_num * (*factorial_provider)(of_num-1);
}