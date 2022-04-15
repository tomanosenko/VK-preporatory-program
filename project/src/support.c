
#include <stdio.h>
#include "matrix.h"

int check_for_exist(const Matrix *matrix) {
    if (!matrix || !(matrix->value)) {
        fprintf(stderr, EXIST_ERR);
        return 1;
    }
    return 0;
}


Matrix* get_minor(const Matrix* matrix, size_t row, size_t col) {
    if (!matrix) {
    return NULL;
    }
    Matrix* minor = create_matrix(matrix -> num_rows - 1, matrix -> num_cols - 1);
    if (minor -> value && matrix -> value) {
        size_t n = matrix -> num_rows;
        int pointer = 0;
        for (size_t i = 0; i < n; i++) {
            if (i != row) {
                 for (size_t j = 0; j < n; j++) {
                    if (j != col) {
                        *(minor -> value + pointer) = matrix -> value[i * n + j];
                        pointer++;
                    }
                }
            }
        }
    }
    return minor;
}

double summary(double x, double y) {
    return x + y;
}

double subtract(double x, double y) {
    return x - y;
}
