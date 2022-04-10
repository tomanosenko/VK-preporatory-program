
#include <stdio.h>
#include "matrix.h"

int get_elem(const Matrix* matrix, size_t row, size_t col, double* val) {
    *val = matrix->value[row][col];
    return *val;
}

int set_elem(Matrix* matrix, size_t row, size_t col, double val) {
    matrix->value[row][col] = scanf("lf", &matrix->value[row][col]);
    return 0;
}

