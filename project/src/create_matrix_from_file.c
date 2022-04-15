#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"


#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

#define NUMBER_MATRIX_SIZE 2

#define ALLOCATE_ERR "Can't allocate memory"
#define ACCESS_ERR "No access"
#define INPUT_SIZE_ERR "Uncorrect input(size)"
#define INPUT_ELEM_ERR "Uncorrect input(elem)"

Matrix* create_matrix_from_file(const char* path_file) {
    FILE* matrix_file = fopen(path_file, "r");
    if (!matrix_file) {
        fprintf(stderr, ACCESS_ERR);
        return NULL;
    }
    Matrix* matrix = malloc(sizeof(Matrix));
    if (!matrix) {
        fprintf(stderr, ALLOCATE_ERR);
        fclose(matrix_file);
        return NULL;
    }
    if (fscanf(matrix_file, "%zu%zu", &matrix -> num_rows, &matrix -> num_cols) != NUMBER_MATRIX_SIZE) {
        fprintf(stderr, INPUT_SIZE_ERR);
        free(matrix);
        fclose(matrix_file);
        return NULL;
    }
    matrix -> value = malloc(matrix -> num_rows * matrix -> num_cols * sizeof(double));
        if (!matrix -> value) {
            fprintf(stderr, ALLOCATE_ERR);
            free(matrix -> value);
            free(matrix);
            fclose(matrix_file);
            return NULL;
        }
        for (size_t i = 0; i < matrix -> num_rows; i++) {
            for (size_t j = 0; j < matrix -> num_cols; j++) {
                int buf = fscanf(matrix_file, "%lf", &(matrix -> value[i * matrix -> num_cols + j]));
                if (buf != 1 && buf == EOF) {
                fprintf(stderr, INPUT_ELEM_ERR);
                    free(matrix -> value);
                    free(matrix);
                    fclose(matrix_file);
                    return NULL;
                }
            }
        }
        fclose(matrix_file);
    return matrix;
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
