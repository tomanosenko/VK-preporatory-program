
#ifndef PROJECT_INCLUDE_DOP_H_
#define PROJECT_INCLUDE_DOP_H_

#include "matrix.h"

Matrix* adj(const Matrix* matrix);
Matrix* inv(const Matrix* matrix);
int det(const Matrix* matrix, double* val);
Matrix*get_minor(const Matrix* matrix, size_t row, size_t col);


#endif  //  PROJECT_INCLUDE_DOP_H_
