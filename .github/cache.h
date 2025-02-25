#ifndef CACHE_H
#define CACHE_H
#include "factorial.h"

extern ulong_long_func_ptr original_provider;

unsigned long long cache(unsigned int val);

#endif // CACHE_H