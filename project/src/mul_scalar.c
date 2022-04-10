

#include <stdio.h>
#include "matrix.h"

Matrix* mul_scalar(const Matrix* matrix, double val) {
    for (int i=0; i < get_rows(matrix); i++) {
        for (int j=0; j < get_cols(matrix); j++) {
            (double)(get_elem(matrix, get_rows(matrix), get_cols(matrix))) *= val;
        }
    }
}
