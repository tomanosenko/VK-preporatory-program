
#include <stdio.h>
#include "matrix.h"

int get_rows(const Matrix* matrix) {
    return matrix->num_rows;
}

int get_cols(const Matrix* matrix) {
    return matrix->num_cols;
}
