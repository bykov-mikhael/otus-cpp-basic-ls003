#include "user_input.h"

#include <cstdlib>
#include <ctime>

bool get_RandomVal(int iRandomVal)  {
    const int max_value = 100;

	std::srand(std::time(nullptr)); // use current time as seed for random generator

    iRandomVal = std::rand() % 100;

	return 0;
}