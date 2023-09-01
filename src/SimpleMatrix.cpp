#include "SimpleMatrix.h"

void print_matrix_bad (FILE *stream, const int matrix[MATRIX_SIZE_Y][MATRIX_SIZE_X]){

    print_x_axis (stream, MATRIX_SIZE_X);

    for (size_t y = 0; y < MATRIX_SIZE_Y; y++){
        fprintf (stream, "%-7lu       ", y);

        for (size_t x = 0; x < MATRIX_SIZE_X; x++){
            fprintf (stream, "%-7d", matrix[y][x]);
        }
        fputs ("\n", stream);
    }
}

void print_matrix (FILE *stream, const int *matrix, size_t sizeY, size_t sizeX){
    print_x_axis (stream, sizeX);

    for (size_t index = 0; index < sizeX * sizeY; index++){
        if (!(index % sizeX)){
            if (index)
                fputs ("\n", stream);

            fprintf (stream, "%-7lu   ", index / sizeX);
        }

        fprintf (stream, "%-7d", *(matrix + index));
    }

    fputs ("\n", stream);
}

void print_x_axis (FILE *stream, size_t sizeX){
    fputs ("Y\\X       ", stream);

    for (size_t x = 0; x < sizeX; x++)
        fprintf (stream, "%-7lu", x);

    fputs ("\n\n", stream);
}

int *multiply_matrices (const int *a_matrix, const int *b_matrix, size_t matrixSize){

    int *out_matrix = (int *) calloc (matrixSize * matrixSize, sizeof (int));

    for (size_t index = 0; index < matrixSize * matrixSize; index++){
        *(out_matrix + index) = get_multiplication_element (a_matrix, b_matrix, matrixSize, index / matrixSize, index % matrixSize);
    }

    return out_matrix;
}

int get_multiplication_element (const int *a_matrix, const int *b_matrix, size_t matrixSize, size_t elementY, size_t elementX){
    int element = 0;

    printf ("Finding element (%lu;%lu): \n", elementX, elementY);

    for (size_t index = 0; index < matrixSize; index++){
        int a_element = *(a_matrix + index + elementY * matrixSize);
        int b_element = *(b_matrix + elementX + matrixSize * index);

        element += a_element * b_element;

        printf ("Multiplying A [%lu][%lu] = %d by B [%lu][%lu] = %d\n",\
            elementY, index, a_element, index, elementX, b_element);
    }

    puts ("");

    return element;

}
