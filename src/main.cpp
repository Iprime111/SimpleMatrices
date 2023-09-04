#include <stdio.h>
#include "SimpleMatrix.h"
#include <CustomAssert.h>

int main (){
    PushLog (1);

    const size_t test_matrix_size = 5;

    int test_matrix [test_matrix_size][test_matrix_size] = {
        {0,  1,  2,  3,  4},
        {10, 11, 12, 13, 14},
        {20, 21, 22, 23, 24},
        {30, 31, 32, 33, 34},
        {40, 41, 42, 43, 44}
    };

    int triangle_array [15] = {
        1,
        2, 3,
        4, 5, 6,
        7, 8, 9, 10,
        11, 12, 13, 14, 15
    };

    int *multiplication_result = multiply_matrices ((int *)test_matrix, (int *)test_matrix, test_matrix_size);

    print_matrix (stdout, multiplication_result, test_matrix_size, test_matrix_size);

    free (multiplication_result);

    puts ("\nTriangle array print:");

    print_triangle_array (stdout, triangle_array, 15);

    RETURN 0;
}
