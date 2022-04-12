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
