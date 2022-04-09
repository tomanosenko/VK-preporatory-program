
#include <math.h>

int is_equal(double first_compared_digit, double second_compared_digit) {
    double epsilon = 0.0000001;
    if (fabs(first_compared_digit - second_compared_digit<= epsilon)) 
        return 0;
    return 1;
}
