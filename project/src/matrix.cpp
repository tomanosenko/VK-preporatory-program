
#include "matrix.h"
#include "exceptions.h"
#include <iostream>
#include <fstream>
#include <math.h>
#include <typeinfo>

bool is_equal(double first_digit, double second_digit) {
        double epsilon = 1e-07;
        if (fabs(first_digit - second_digit) <= epsilon)
            return true;
        return false;
    }

// Базовые опперации 

namespace prep {
    size_t Matrix::getRows() const
     {
         return rows;
     }

    size_t Matrix::getCols() const
    {
        return cols;
    }
    
    double Matrix::operator()(size_t i, size_t j) const {
        if (i > rows || j > cols) {
            OutOfRange(i, j, *this);
        }
        return value[cols * i + j];
    }

    double& Matrix::operator()(size_t i, size_t j) {
        if (i > rows || j > cols) {
           OutOfRange(i, j, *this);
        }
        double &val = value[cols * i + j];
        return val;
    }

    // Конструкторы

    // Создание нулевой матрицы

    Matrix::Matrix(size_t num_rows, size_t num_cols) {
        if (num_rows > 0 && num_cols > 0) {
        rows = num_rows;
        cols =  num_cols;
        value.reserve(rows*cols);
        }
    }

    // Создание матрицы из файла
    Matrix:: Matrix(std::istream& is) {
        is >> rows; 
        is >> cols;
        value.reserve(rows*cols);
        if ((rows == 0)|| (cols == 0) ||  (!(typeid(rows) == typeid (std::size_t))  || (!(typeid(cols) == typeid (std::size_t))))) {
            InvalidMatrixStream();
        } else {
            for (size_t i = 0; i < rows; i++) {
                for (size_t j = 0; j < cols; j++) {
                    if (!(typeid(value[i*cols+j]) == typeid(double))) {
                        InvalidMatrixStream();
                    }
                    is >> value[i*cols+j];
                }
            }
        }
    }

    // Операторы сравнения

    bool Matrix::operator==(const Matrix& rhs) const {
        if ((rows == rhs.rows) && (cols == rhs.cols)) {
            bool buf = true;
            for (size_t i = 0; i < rhs.rows; i++) {
                for (size_t j = 0; j < rhs.cols; j++) {
                    if (!is_equal(value[i * cols + j], rhs.value[i * cols + j]))
                        buf = false;
                }
            }
            return buf;
        }
        return false;
    }

    bool Matrix::operator!=(const Matrix& rhs) const {
        if ((rows == rhs.rows) && (cols == rhs.cols)) {
            bool buf = false;
            for (size_t i = 0; i < rhs.rows; i++) {
                for (size_t j = 0; j < rhs.cols; j++) {
                    if (!is_equal(value[i * cols + j], rhs.value[i * cols + j]))
                        buf = true;
                }
            }
            return buf;
        }
        return true;
    }

     // Вывод матрицы в поток

    std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        for (size_t i = 0; i < matrix.rows; i++) {
                for (size_t j = 0; j < matrix.cols; j++) {
                    if (j == 0) {
                        os << matrix.value[i * matrix.cols];
                    }
                    if (j == matrix.cols) {
                        os << " " << matrix.value[i * matrix.cols + j] << std::endl;
                    }
                    os  << " " << matrix.value[i * matrix.cols + j];
                }
        }
        return os;
    }
    
    // Базовые методы

    /*
    double Matrix::operator()(size_t i, size_t j) const {
        InvalidMatrixStream
    }
    */
}



