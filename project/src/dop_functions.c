
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix* adj(const Matrix* matrix) {
    if (check_for_exist(matrix))
        return NULL;
    if ((matrix->num_rows != matrix->num_cols) || (matrix ->num_cols == 0)) {
        return NULL;
    }
    size_t n = matrix->num_rows;
    if (n < 1) {
         puts("uncountable det");
         return NULL;
    }
    Matrix* adject = create_matrix(n, n);
    if (n == 1) {
        adject -> value[0] = 1;
        return adject;
    }
    double minor_det;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            Matrix* minor = get_minor(matrix, j, i);
            if ((minor != NULL) && !(det(minor, &minor_det))) {
                int minor_sign = ((i + j) % 2)? -1: 1;
                adject -> value[i * n + j] = minor_sign * minor_det;
            }
        free_matrix(minor);
        }
    }
    return adject;
}

Matrix* inv(const Matrix* matrix) {
    if (check_for_exist(matrix))
        return NULL;
    double determinant;
    int buff = det(matrix, &determinant);
    if ((determinant = 0 || buff)) {
        puts("error determinant");
        return NULL;
    }
    double value = 1/determinant;
    Matrix *adjected = adj(matrix);
    Matrix *invert_matr = mul_scalar(adjected, value);
    free_matrix(adjected);
    return invert_matr;
}

int det(const Matrix* matrix, double* val) {
    if (check_for_exist(matrix)) {
        fprintf(stderr, INPUT_ERR);
        return 1;
    }
    if ((matrix -> num_cols != matrix -> num_rows) || (matrix -> num_cols == 0)) {
       fprintf(stderr, "matrix isn`t square");
        return 1;
    }
    size_t n = matrix -> num_rows;
    if (n == 1) {
        *val = *(matrix -> value);
    } else if (n == 2) {
        *val = matrix -> value[0] * matrix -> value[3] - matrix -> value[2]*matrix -> value[1];
    } else {
        int minor_sign = 1;
        double determinant = 0;
        double minor_det;
        for (size_t i = 0; i < n; i++) {
            Matrix* minor = get_minor(matrix, 0, i);
            if ((minor != NULL) && !(det(minor, &minor_det))) {
            determinant += minor_sign * minor_det * matrix -> value[i];
            minor_sign *= -1;
            }
        free_matrix(minor);
        }
    *val = determinant;
    }
    return 0;
}

Matrix*get_minor(const Matrix* matrix, size_t row, size_t col) {
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
