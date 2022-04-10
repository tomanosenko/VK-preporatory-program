
#include <stdio.h>
#include "matrix.h"

Matrix* transp(const Matrix* matrix) {
    int *rows, *cols;
    for (int i=0; i < get_rows(matrix, rows); i++) {
        for (int j=0; j < get_cols(matrix, cols) ; j++) {
            get_elem(matrix, get_rows(matrix, rows), get_cols(matrix, cols)) = get_elem(matrix, get_rows(matrix, cols), get_cols(matrix, rows));
        }
    }
}