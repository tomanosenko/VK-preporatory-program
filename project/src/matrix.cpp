
#include "matrix.h"
#include "exceptions.h"
#include <iostream>
#include <fstream>

namespace prep {
    size_t Matrix::getRows() const
     {
         return rows;
     }

    size_t Matrix::getCols() const
    {
        return cols;
    }

    explicit Matrix::Matrix(size_t num_rows, size_t num_cols)
    {
        value = new double[rows*cols];
        rows = num_rows;
        cols = num_cols;
        for (size_t i=0; i<num_rows; i++) {
            for (size_t j=0; i<num_cols; j++)
                value[i * cols + j];
        }
    }

    Matrix& Matrix::operator=(const Matrix& rhs) {
        if ((rhs.rows > 0) && (rhs.cols > 0)) {
            rows = rhs.rows;
            cols = rhs.cols;
            value = new double[rows*cols];
            for (size_t i=0; i < rows; i++) {
                for (size_t j=0; i < cols; j++) {
                    value[i * cols + j] = rhs.value[i * cols + j];
                }
            }
        }
        return *this;
    } 
}
