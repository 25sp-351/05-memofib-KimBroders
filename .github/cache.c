#include "cache.h"
#define NOT_PRESENT 0

// caching (memoizing) version of factorial
ulong_long_func_ptr original_provider = factorial;

unsigned long long cache(unsigned int val) {
    static unsigned long long results[100] = {NOT_PRESENT};

    if (results[val] == NOT_PRESENT)        
        results[val] = (*original_provider)(val);
    
    return results[val];
}