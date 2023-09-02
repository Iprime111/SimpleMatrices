#include <stdio.h>
#include "SimpleMatrix.h"

int main (){

    PushLog (1);
    int test_matrix [5][5] = {
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

    int *multiplication_result = multiply_matrices ((int *)test_matrix, (int *)test_matrix, 5);

    print_matrix (stdout, multiplication_result, 5, 5);

    free (multiplication_result);

    puts ("\nTriangle array print:");

    print_triangle_array (stdout, triangle_array, 15);

    RETURN 0;
}
