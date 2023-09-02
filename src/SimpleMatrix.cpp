#include "SimpleMatrix.h"

void print_matrix_bad (FILE *stream, const int matrix[MATRIX_SIZE_Y][MATRIX_SIZE_X]){
    PushLog(2);

    custom_assert (stream != NULL, pointer_is_null, (void)0);

    print_x_axis (stream, MATRIX_SIZE_X);

    for (size_t y = 0; y < MATRIX_SIZE_Y; y++){
        fprintf (stream, "%7lu| ", y);

        for (size_t x = 0; x < MATRIX_SIZE_X; x++){
            fprintf (stream, "%-7d", matrix[y][x]);
        }
        fputs ("\n", stream);
    }

    RETURN ;
}

void print_matrix (FILE *stream, const int *matrix, size_t sizeY, size_t sizeX){
    PushLog(2);

    custom_assert (stream != NULL,               pointer_is_null, (void)0);
    custom_assert (matrix != NULL,               pointer_is_null, (void)0);
    custom_assert ((sizeX != 0) && (sizeY != 0), invalid_value,   (void)0);

    print_x_axis (stream, sizeX);

    for (size_t index = 0; index < sizeX * sizeY; index++){
        if (!(index % sizeX)){
            if (index)
                fputs ("\n", stream);

            fprintf (stream, "%7lu| ", index / sizeX);
        }

        fprintf (stream, "%-7d", *(int *) ((size_t)matrix + index * sizeof (int)));
    }

    fputs ("\n", stream);

    RETURN;
}

void print_x_axis (FILE *stream, size_t sizeX){
    PushLog(3);

    custom_assert (stream != NULL, pointer_is_null, (void)0);
    custom_assert (sizeX != 0,     invalid_value,   (void)0);

    fputs ("    Y\\X| ", stream);

    for (size_t x = 0; x < sizeX; x++)
        fprintf (stream, "%-6lu|", x);

    fputs ("\n", stream);
    fputs ("———————|—", stream);

    for (size_t x = 0; x < sizeX; x++)
        fprintf (stream, "———————");

    fputs ("\n", stream);

    RETURN;
}

int *multiply_matrices (const int *a_matrix, const int *b_matrix, size_t matrixSize){
    PushLog(2);

    custom_assert ((a_matrix != NULL) && (b_matrix != NULL), pointer_is_null, NULL);
    custom_assert (matrixSize != 0,                          invalid_value,   NULL);

    int *out_matrix = (int *) calloc (matrixSize * matrixSize, sizeof (int));

    custom_assert (out_matrix != NULL, pointer_is_null, NULL);

    for (size_t index = 0; index < matrixSize * matrixSize; index++){
        * (int *) ((size_t) out_matrix + index * sizeof (int)) =\
            get_multiplication_element (a_matrix, b_matrix, matrixSize, index / matrixSize, index % matrixSize);
    }

    RETURN out_matrix;
}

int get_multiplication_element (const int *a_matrix, const int *b_matrix, size_t matrixSize, size_t elementY, size_t elementX){
    PushLog(3);

    custom_assert ((a_matrix != NULL) && (b_matrix != NULL),           pointer_is_null, 0);
    custom_assert (matrixSize != 0,                                    invalid_value,   0);
    custom_assert ((elementX < matrixSize) && (elementY < matrixSize), invalid_value,   0);

    int element = 0;

    printf ("Finding element (%lu;%lu): \n", elementX, elementY);

    for (size_t index = 0; index < matrixSize; index++){
        int a_element = * (int *) ((size_t) a_matrix + (index + elementY * matrixSize) * sizeof (int));
        int b_element = * (int *) ((size_t)b_matrix + (elementX + matrixSize * index) * sizeof (int));

        element += a_element * b_element;

        printf ("Multiplying A [%lu][%lu] = %d by B [%lu][%lu] = %d\n",\
            elementY, index, a_element, index, elementX, b_element);
    }

    puts ("");

    RETURN element;

}

void print_triangle_array (FILE *stream, const int array [], size_t size){
    PushLog(2);

    custom_assert (stream != NULL, pointer_is_null, (void)0);
    custom_assert (array != NULL,  pointer_is_null, (void)0);

    long double row_count_double = (sqrt (1 + 8 * ((long double) size)) - 1) / 2;
    size_t row_count = (size_t) row_count_double;

    custom_assert (fabs(row_count_double - row_count) < EPS, invalid_value, (void)0);

    for (size_t y = 0; y < row_count; y++){
        fprintf (stream, "%7lu| ", y);

        for (size_t x = 0; x <= y; x++){
            fprintf (stream, "%-5d ", array [x + y * (y + 1) / 2]);
        }
        fputs ("\n", stream);
    }

    RETURN ;
}
