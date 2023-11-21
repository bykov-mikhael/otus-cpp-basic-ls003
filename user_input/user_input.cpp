#include "user_input.h"

#include <cstdlib>
#include <ctime>

bool get_RandomVal(int iMaxVal, int &iRandomVal)  {
    std::srand(std::time(nullptr)); // use current time as seed for random generator

    do {
        iRandomVal = std::rand() % 100;
    } while (iRandomVal >= iMaxVal);

	return 0;
}