#include <stdio.h> // printf_s, scanf_s, gets

// a type for it
typedef long (*long_func_ptr)(int of_num);

long_func_ptr factorial_provider = NULL;

// a factorial "provider" (TINY CHANGE)
long factorial(int of_num) {
    if (of_num < 2)
        return of_num;

    return of_num * (*factorial_provider)(of_num-1);
}

// caching (memoizing) version of factorial
long_func_ptr original_provider;

#define NOT_PRESENT -1
long results[100] = {NOT_PRESENT};

long cache(int val) {
    if (results[val] == NOT_PRESENT)
        results[val] = (*original_provider)(val);
    return results[val];
}

int main(int argc, char*argv[]) {
	char str_buffer[256];
	int num_scanned;
    int find_factorial_of;

    // install it in main
    original_provider = factorial;
    factorial_provider = cache;

	while ((fgets(str_buffer, sizeof(str_buffer), stdin)) != NULL){
		num_scanned = sscanf_s(str_buffer, "%u", &find_factorial_of);

		if (num_scanned != 1 || str_buffer[0] == '-') {
			printf_s("Invalid input: %s\n", str_buffer);
		}

		else {
			// how to use it NO CHANGE EXCEPT SPEED
            printf_s("factorial of %d is %ld\n", find_factorial_of, (*factorial_provider)(find_factorial_of));
		}
	}	
}