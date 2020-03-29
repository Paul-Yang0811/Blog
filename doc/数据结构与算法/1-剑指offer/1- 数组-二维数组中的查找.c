/*
 * 在一个二维数组中（每个一维数组的长度相同），
 * 每一行都按照从左到右递增的顺序排序，每一列都按照从上到下递增的顺序排序。
 * 请完成一个函数，输入这样的一个二维数组和一个整数，判断数组中是否含有该整数。
*/
#include <stdio.h>

int find_num(int *arr, int row, int col, int target)
{
    int i = 0, j = 0;

    for (i = 0; i < row; i++)
        for (j = 0; j < col; j++) {
            printf("a[%d][%d] = %d\n", i ,j, arr[i * row + j]);
        }
    i = 0;
    j = col-1;

    while (i < row && j >= 0) {
        if ( target ==  arr[i * row + j] ) {
            printf("i = %d, j = %d\n", i, j);
            return 1;
        } else if (target >  arr[i * row + j]) {
            i++;
        } else {
            j--;
        }
    }

    return 0;
}

int main() 
{
    int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    int ret = find_num(*arr, 3, 3, 9);
    
    printf("ret = %d\n", ret);
    return 0;
}
