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

    print_matrix (stdout, (int *) mtx, 5, 5);

    return 0;
}
