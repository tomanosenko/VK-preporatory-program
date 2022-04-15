#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

Matrix* create_matrix_from_file(const char* path_file) {
    Matrix *ptr_matrix = malloc(sizeof(Matrix));
    if (!ptr_matrix) {
        fprintf(stderr, "can`t allocate memory");
        return NULL;
    }
    FILE *matrix_data = fopen(path_file, "r");
    if (!matrix_data) {
        perror("Not file exist");
        free(ptr_matrix);
        return NULL;
    }
    fscanf(matrix_data, "%zu%zu", &ptr_matrix->num_rows, &ptr_matrix->num_rows);
        for (size_t i=0; i < ptr_matrix->num_rows; i++) {
            for (size_t j=0; j < ptr_matrix->num_cols; j++) {
                fscanf(matrix_data, "%lf", &ptr_matrix->value[i*ptr_matrix->num_cols+j]);
            }
    }
    fclose(matrix_data);
    return ptr_matrix;
}
<<<<<<< HEAD:project/src/creating_matrix.c

Matrix* create_matrix(size_t rows, size_t cols) {
    if (!rows || !cols)
        return NULL;
    Matrix* new_matrix = malloc(sizeof(Matrix));
    if (!new_matrix) {
        fprintf(stderr, MEM_ERR);
        return NULL;
    }
    new_matrix -> num_rows = rows;
    new_matrix -> num_cols = cols;
    new_matrix -> value = calloc(rows * cols, sizeof(double));
    if (!(new_matrix -> value)) {
        free(new_matrix);
        puts("The file doesn't exist");
        return NULL;
    }
    return new_matrix;
}

int check_for_exist(const Matrix *matrix) {
    if (!matrix || !(matrix->value)) {
        fprintf(stderr, EXIST_ERR);
        return 1;
    }
    return 0;
}

void free_matrix(Matrix* matrix) {
    if (matrix != NULL) {
        if (matrix -> value != NULL) {
            free(matrix -> value);
        }
    free(matrix);
    }
}
=======
>>>>>>> parent of dfe6c71... The last commit, I hope:project/src/create_matrix_from_file.c
