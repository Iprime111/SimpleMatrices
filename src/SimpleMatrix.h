#ifndef SIMPLEMATRIX_H_
#define SIMPLEMATRIX_H_

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "../CustomAssert/CustomAssert.h"

const double EPS = 1.0e-6;

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

/*!
    @brief Multiplies two square matrices
    @param[in] a_matrix First matrix
    @param[in] b_matrix Second matrix
    @param[in] matrixSize Size of the both matrices
    @return Pointer to dynamicly allocated memory with resulting matrix stored inside
    @note Returned memory region must be deallocated with free ()
*/
int *multiply_matrices (const int *a_matrix, const int *b_matrix, size_t matrixSize);

/*!
    @brief Computes one element of the matrix for a matrix multiplication
    @param[in] a_matrix First matrix
    @param[in] b_matrix Second matrix
    @param[in] matrixSize Size of the both matrices
    @param[in] elementY Y position of an element that is being found
    @param[in] elementX X position of an element that is being found
    @return Value of an element of a matrix multiplication
*/
int get_multiplication_element (const int *a_matrix, const int *b_matrix, size_t matrixSize, size_t elementY, size_t elementX);

/*!
    @brief Prints triangle array in a given stream
    @param[in] stream Output stream
    @param[in] array Triangle array
    @param[in] size Given array size
*/
void print_triangle_array (FILE *stream, const int array [], size_t size);

#endif

