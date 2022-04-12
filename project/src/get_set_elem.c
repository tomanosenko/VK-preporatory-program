
#include <stdio.h>
#include "matrix.h"

int get_elem(const Matrix* matrix, size_t row, size_t col, double* val) {
    if (check_for_exist(matrix) !=0) {
        *val = matrix->value[row*matrix->num_cols+col];
        return 0;
    } else {
        return -1;
    }
}

int set_elem(Matrix* matrix, size_t row, size_t col, double val) {
    if (check_for_exist(matrix) !=0) {
        matrix->value[row*matrix->num_cols+col] = val;
        return 0;
    } else {
        return -1;
    }
}
