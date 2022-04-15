
#include <stdio.h>
#include "matrix.h"

Matrix* mul(const Matrix* left, const Matrix* right) {
    Matrix *result = malloc(sizeof(Matrix));
    if (!result) {
        puts("error allocate memory");
        return NULL;
    }
    if (!(check_for_exist(left) || check_for_exist(right))) {
        puts("can`t multiply non-existing matrix");
        free(result);
        return NULL;
    }
    if (left->num_rows == right->num_cols) {
        double res;
        size_t k = 0;
        for (size_t i = 0; i < left->num_rows; i++) {
            while (k < right->num_cols) {
                res = 0;
                for (size_t j = 0; j < left->num_cols; j++) {
                    res = res + left->value[i*left->num_cols+j] * right->value[j*right->num_cols+i+k];
                }
                set_elem(result, i, k, res);
                k++;
            }
        }
        return result;
    }
    if (left->num_cols == right->num_rows) {
        double res1;
        size_t k1 = 0;
        for (size_t j = 0; left->num_cols; j++) {
            while (k1 < right->num_rows) {
                res1 = 0;
                for (size_t i = 0; left->num_rows; i++) {
                    res1 = res1 + left->value[i*left->num_cols+j] * right->value[i*right->num_cols+j+k1];
                }
            set_elem(result, j, k1, res1);
            k1++;
            }
        }
        return result;
    }
    free(result);
    return NULL;
}

