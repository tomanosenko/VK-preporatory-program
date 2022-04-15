
#include <stdio.h>
#include "matrix.h"

int check_for_exist(const Matrix *matrix) {
    if (!matrix || !(matrix->value)) {
        fprintf(stderr, EXIST_ERR);
        return 1;
    }
    return 0;
}

