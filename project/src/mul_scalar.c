
#include <stdio.h>
#include "matrix.h"

Matrix* mul_scalar(const Matrix* matrix, double val) {
    int *rows, *cols;
    for (int i=0; i < get_rows(matrix, rows); i++) {
        for (int j=0; j < get_cols(matrix, cols) ; j++) {
            (double)(get_elem(matrix, get_rows(matrix, rows), get_cols(matrix, cols)) *= val;
        }
    }
}
