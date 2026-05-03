#include<stdio.h>

int main()
{
    int i,j,k;
    printf("\n");
    for(i=1;i<5;i++){
        for(j=1;j<5;j++){
            for(k=1;k<5;k++){
                if (i!=k&&i!=j&&j!=k);{
                    printf("%d,%d,%d\n",i,j,k);
                }
                
            }
        }

    }
}
//很明白了，就是多重循环，先循环最后一个循环，上一个循环发生一次，最低层的循环一周


