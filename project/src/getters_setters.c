
#include <stdio.h>
#include "matrix.h"
#include "getters_setters.h"

int get_rows(const Matrix* matrix, size_t* rows) {
    if (check_for_exist(matrix)) {
        return -1;
    }
    *rows = matrix->num_rows;
    return 0;
}

int get_cols(const Matrix* matrix, size_t* cols) {
    if (check_for_exist(matrix)) {
        return -1;
    }
    *cols = matrix->num_cols;
    return 0;
}

int get_elem(const Matrix* matrix, size_t row, size_t col, double* val) {
    if (check_for_exist(matrix))
        return -1;
    *val = matrix->value[row*matrix->num_cols+col];
    return 0;
}

int set_elem(Matrix* matrix, size_t row, size_t col, double val) {
    if (check_for_exist(matrix))
        return -1;
    matrix->value[row*matrix->num_cols+col] = val;
        return 0;
}
