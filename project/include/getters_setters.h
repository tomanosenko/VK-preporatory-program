#ifndef PROJECT_INCLUDE_GETTERS_SETTERS_H_
#define PROJECT_INCLUDE_GETTERS_SETTERS_H_

#include "matrix.h"

int get_rows(const Matrix* matrix, size_t* rows);
int get_cols(const Matrix* matrix, size_t* cols);
int get_elem(const Matrix* matrix, size_t row, size_t col, double* val);
int set_elem(Matrix* matrix, size_t row, size_t col, double val);

#endif  //  PROJECT_INCLUDE_GETTERS_SETTERS_H_
