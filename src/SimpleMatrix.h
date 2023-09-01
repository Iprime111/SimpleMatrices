#ifndef SIMPLEMATRIX_H_
#define SIMPLEMATRIX_H_

#include <stdio.h>

const size_t MATRIX_SIZE_X = 5,
             MATRIX_SIZE_Y = 5;

/*!
    @brief Prints matrix of MATRIX_SIZE_X by MATRIX_SIZE_Y size to the given stream
    @param[in] stream Output stream
    @param[in] matrix Matrix for printing
    @note Works only for constant size matrixes
*/
void print_matrix_bad (FILE *stream, const int matrix[MATRIX_SIZE_X][MATRIX_SIZE_Y]);

/*!
    @brief Prints matrix of sizeX by sizeY size to the given stream
    @param[in] stream Output stream
    @param[in] matrix Matrix for printing
    @param[in] sizeY Matrix rows count
    @param[in] sizeX Matrix column count
*/
void print_matrix (FILE *stream, const int *matrix, size_t sizeY, size_t sizeX);

/*!
    @brief Prints x axis for matrix visualistion
    @param[in] stream Output stream
    @param[in] sizeX Quantity of the printed numbers on the axis
*/
void print_x_axis (FILE *stream, size_t sizeX);

int *multiply_matrixes (const int *a_matrix, const int *b_matrix, size_t sizeX, size_t sizeY);

#endif

