
#include <stdio.h>
#include "matrix.h"

Matrix* create_matrix_from_file(const char* path_file) {
    Matrix matrix[][];
    FILE *matrix_data = fopen(path_file, "r");
    if (matrix_data == NULL) {
        puts("error");
    } else {
        fscanf(matrix_data, "%d%d", Matrix.num_row, Matrix.num_col);
        for (int i=0, i < (Matrix.num_row*Matrix.num_col), i++) {
            for (int j=0, j < (Matrix.num_row*Matrix.num_col), j++) {
                matrix[i][j] = fscanf(&Matrix.value);
            }
        }
    }
    
} 
