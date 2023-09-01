#include <stdio.h>
#include "SimpleMatrix.h"

int main (){

    int mtx [5][5] = {
        {0,  1,  2,  3,  4},
        {10, 11, 12, 13, 14},
        {20, 21, 22, 23, 24},
        {30, 31, 32, 33, 34},
        {40, 41, 42, 43, 44}
    };

    int *multiplication_result = multiply_matrices ((int *)mtx, (int *)mtx, 5);

    print_matrix (stdout, multiplication_result, 5, 5);

    free (multiplication_result);

    return 0;
}
