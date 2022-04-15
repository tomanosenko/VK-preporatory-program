

#ifndef PROJECT_INCLUDE_SUPPORT_H_
#define PROJECT_INCLUDE_SUPPORT_H_

#include <stddef.h>
#include <utils.h>

Matrix* get_minor(const Matrix* matrix, size_t row, size_t col);
int check_for_exist(const Matrix *matrix);
typedef double (* arifmetic_func)(double, double);
Matrix* arifmetic(const Matrix* left, const Matrix* right, arifmetic_func fn);

#endif  //  PROJECT_INCLUDE_SUPPORT_H_

