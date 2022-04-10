
#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <stddef.h>

typedef struct Matrix {
    int num_rows;
    int num_cols;
    double** value;
} Matrix;

// Init/release operations
Matrix* create_matrix_from_file(const char* path_file);
Matrix* create_matrix(size_t rows, size_t cols);
void free_matrix(Matrix* matrix);
int check_for_exist(Matrix *matrix);

// Basic operations
int get_rows(const Matrix* matrix, size_t rows);
int get_cols(const Matrix* matrix, size_t cols);
int get_elem(const Matrix* matrix, size_t row, size_t col, double* val);
int set_elem(Matrix* matrix, size_t row, size_t col, double val);

//Math operations
Matrix* mul_scalar(const Matrix* matrix, double val);
Matrix* transp(const Matrix* matrix);

Matrix* sum(const Matrix* left, const Matrix* right);
Matrix* sub(const Matrix* left, const Matrix* right);
Matrix* mul(const Matrix* left, const Matrix* right);

// Extra operations
int det(const Matrix* matrix, double* val);
Matrix* adj(const Matrix* matrix);
Matrix* inv(const Matrix* matrix);


#endif //_MATRIX_H_
