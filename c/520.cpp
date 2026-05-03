#include <stdio.h>

int main(int argc, char const *argv[])
{
    /* 初始化二维数组 */
    int a[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 0, 11, 12},
        {13, 14, 15, 16}
    };
    
    int q, w, e;

    // 取数组中的值
    q = *(*(a+1)+0);  // a[1][0]
    w = *(*a+1);      // a[0][1]
    e = *(*(a+2)+1);  // a[2][1]

    // 打印值
    printf("%d\n", q);
    printf("%d\n", w);
    printf("%d\n", e);

    return 0;
}