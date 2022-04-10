
#include <stdio.h>
#include "matrix.h"

int get_elem(const Matrix* matrix, size_t row, size_t col, double* val) {
    if (check_for_exist(matrix) != 0) {
    *val = matrix->value[row][col];
    return *val;
    } else {
        return -1;}
}

int set_elem(Matrix* matrix, size_t row, size_t col, double val) {
    if (check_for_exist(matrix) != 0) {
        matrix->value[row][col] = val;
        return 0;
    } else {
        return -1;
    }
}
