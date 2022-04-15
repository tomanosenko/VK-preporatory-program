
#ifndef PROJECT_INCLUDE_ARIFM_H_
#define PROJECT_INCLUDE_ARIFM_H_

#include "matrix.h"

Matrix* arifmetic(const Matrix* left, const Matrix* right, arifmetic_func fn);
double summary(double x, double y);
double subtract(double x, double y);
Matrix* sum(const Matrix* left, const Matrix* right);
Matrix* sub(const Matrix* left, const Matrix* right);
Matrix* mul(const Matrix* left, const Matrix* right);
Matrix* mul_scalar(const Matrix* matrix, double val);
Matrix* transp(const Matrix* matrix);

#endif  //  PROJECT_INCLUDE_GETTERS_SETTERS_H_

