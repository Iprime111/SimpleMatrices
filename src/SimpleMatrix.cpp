#include "SimpleMatrix.h"

void print_matrix_bad (FILE *stream, const int matrix[MATRIX_SIZE_Y][MATRIX_SIZE_X]){

    print_x_axis (stream, MATRIX_SIZE_X);

    for (size_t y = 0; y < MATRIX_SIZE_Y; y++){
        fprintf (stream, "%-5lu     ", y);

        for (size_t x = 0; x < MATRIX_SIZE_X; x++){
            fprintf (stream, "%-5d", matrix[y][x]);
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

            fprintf (stream, "%-5lu     ", index / sizeX);
        }

        fprintf (stream, "%-5d", *(matrix + index));
    }

    fputs ("\n", stream);
}

void print_x_axis (FILE *stream, size_t sizeX){
    fputs ("Y\\X       ", stream);

    for (size_t x = 0; x < sizeX; x++)
        fprintf (stream, "%-5lu", x);

    fputs ("\n\n", stream);
}

int *multiply_matrixes (const int *a_matrix, const int *b_matrix, size_t sizeX, size_t sizeY){

    return NULL;
}
