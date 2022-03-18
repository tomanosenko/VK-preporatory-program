#include "utils.h"
#include <stdio.h>

size_t timer_from(int from) {
    size_t counter = 0;
    for (int i = from; i >= 0; --i) {
        ++counter;
        if (i != 0) {
            printf("%d ", i);
        } else {
            printf("%d\n", i);
        }
    }
    return counter;
}


