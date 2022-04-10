#include <stdio.h>
#include "matrix.h"

Matrix* sum(const Matrix* left, const Matrix* right) {
    Matrix *result;
    size_t *rows_l, *cols_l, *rows_r, *cols_r;
    if ((check_for_exist(left) == 1) && (check_for_exist(right) == 1)) {
        double *summand1, *summand2, sum;
        if ((get_rows(left, rows_l) == get_rows(right, rows_r)) && (get_cols(left, cols_l) == get_cols(right, cols_r))) {
            for (int i = 0; get_rows(left, rows_l); i++) {
                for (int j = 0; get_cols(left, cols_l); j++) {
                    sum = get_elem(left, i, j, summand1) + get_elem(right, i, j, summand2);
                    set_elem(result, i, j, sum);
                }
             }
        return result;
        } else {
            puts("error");
        return;
        }
    }
}
