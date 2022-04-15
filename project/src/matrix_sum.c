
#include <stdio.h>
#include "matrix.h"
#include <stdio.h>

Matrix* sum(const Matrix* left, const Matrix* right) {
    Matrix *result = malloc(sizeof(Matrix));
    if (!(check_for_exist(left) || check_for_exist(right))) {
        puts("can`t sum non-existing matrix");
        free(result);
        return NULL;
    }
    if ((left->num_cols == right->num_cols) && (left->num_rows == right->num_rows)) {
        size_t M = left->num_cols;
        for (size_t i = 0; left->num_rows; i++) {
            for (size_t j = 0; right->num_cols; j++) {
                set_elem(result, i, j, left->value[i*M+j] + right->value[i*M+j]);
            }
        }
    return result;
    } else {
        puts("error");
        free(result);
        return NULL;
    }
}


