
#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"
#include "support.h"

Matrix* arifmetic(const Matrix* left, const Matrix* right, arifmetic_func fn) {
    if (check_for_exist(left) || check_for_exist(right)) {
        fprintf(stderr, INPUT_ERR);
        return NULL;
    }
    if (left -> num_cols != right -> num_cols || left -> num_rows != right -> num_rows) {
        fprintf(stderr, DIMENTION_ERR);
        return NULL;
    }
    size_t n = left -> num_rows;
    size_t m = left -> num_cols;
    Matrix * arifmetic_matrix = create_matrix(left -> num_rows, right -> num_cols);
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            arifmetic_matrix -> value[i * m + j] = fn(left -> value[i * m + j], right -> value[i * m + j]);
        }
    }
    return arifmetic_matrix;
}

Matrix* sum(const Matrix* left, const Matrix* right) {
    return arifmetic(left, right, summary);
}

Matrix* sub(const Matrix* left, const Matrix* right) {
    return arifmetic(left, right, subtract);
}

Matrix* mul(const Matrix* left, const Matrix* right) {
    if (check_for_exist(left) || check_for_exist(right)) {
        fprintf(stderr, INPUT_ERR);
        return NULL;
    }
    if (left -> num_cols != right -> num_rows) {
        fprintf(stderr, MULTIPLY_ERR);
        return NULL;
    }
    Matrix * multiply = create_matrix(left -> num_rows, right -> num_cols);
    size_t mid = left -> num_cols;
    size_t n = multiply -> num_rows;
    size_t m = multiply -> num_cols;
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            double buf = 0;
            for (size_t k = 0; k < mid; k++) {
                buf += left -> value[i * left -> num_cols + k] * right -> value[k * right -> num_cols + j];
            }
        multiply -> value[i * multiply -> num_cols + j]= buf;
        }
    }
    return multiply;
}

Matrix* transp(const Matrix* matrix) {
    if (check_for_exist(matrix)) {
        puts("can`t transp non-existing matrix");
        return NULL;
    }
    Matrix* transp_matrix = create_matrix(matrix -> num_cols, matrix -> num_rows);
    double *buf = malloc(sizeof(double));
    for (size_t i=0; i < matrix->num_rows; i++) {
        for (size_t j=0; j < matrix->num_cols; j++) {
        get_elem(matrix, i, j, buf);
        set_elem(transp_matrix, j, i, *buf);
        }
    }
    free(buf);
    return transp_matrix;
}

Matrix* mul_scalar(const Matrix* matrix, double val) {
    if (check_for_exist(matrix)) {
    return NULL;
    } else {
        Matrix* mul_matrix = create_matrix(matrix -> num_rows, matrix -> num_cols);
        size_t M = matrix -> num_cols;
        for (size_t i = 0; i < matrix -> num_rows; i++) {
            for (size_t j = 0; j < matrix -> num_cols; j++) {
                mul_matrix -> value[i*M+j] = val * (matrix -> value[i*M+j]);
            }
        }
    return mul_matrix;
    }
}
