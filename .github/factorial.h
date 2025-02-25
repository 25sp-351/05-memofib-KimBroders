#ifndef FACTORIAL_H
#define FACTORIAL_H

// a type for it
typedef unsigned long long (*ulong_long_func_ptr)(unsigned int of_num);

extern ulong_long_func_ptr factorial_provider;

unsigned long long factorial(unsigned int of_num);

#endif // FACTORIAL_H