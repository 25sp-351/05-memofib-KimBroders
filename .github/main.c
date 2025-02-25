#include <stdio.h> // printf_s, scanf_s, gets, NULL
#include "cache.h"

int main(int argc, char*argv[]) {
	char str_buffer[256];
	int num_scanned;
    unsigned int find_factorial_of;

    // install it in main
    factorial_provider = cache; // remove this line to use uncached version

	while ((fgets(str_buffer, sizeof(str_buffer), stdin)) != NULL){
		num_scanned = sscanf_s(str_buffer, "%u", &find_factorial_of);

		if (num_scanned != 1 || str_buffer[0] == '-')
			printf_s("Invalid input: %s\n", str_buffer);
        else if (find_factorial_of > 20)
			printf_s("Valid input: %u, but inaccurate results.\nThe factorial of %u is too large for unsigned long long!\n", find_factorial_of, find_factorial_of);
        else
            printf_s("factorial of %u is %llu\n", find_factorial_of, (*factorial_provider)(find_factorial_of));
	}
}