#include <stdio.h>
#include "matrix.h"

Matrix* sum(const Matrix* l, const Matrix* r)
    if (get_rows(l, r.rows) == get_rows(l, l.cols)) && (get_rows(r, r.rows) == get_rows(r, r.cols)) {
    for (int i=0; i < get_rows(l, rows); i++) {
        for (int j=0; j < get_cols(l, cols); j++) {
            (get_elem(l, get_rows(l, l.rows), get_cols(l, l.cols)) += (get_elem(r, get_rows(r, r.rows), get_cols(r, r.cols))
        }
    }
 }