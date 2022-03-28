#include<stdio.h>
#define MAX 100000                // 若为10000，则会因缓存区小而溢出

int main()
{
    int numN = 0;                 // 正整数N
    while (scanf("%d",&numN) != EOF)
    {
        if (numN < 1 || numN >= 10000)
        {
            break;
        }
        
        int array[MAX] = {0};   
        array[1] = 1;            // 从array[1]开始
        int point = 1;           // point表示位数，刚开始只有一位array[1] 且 array[1] = 1，不能为0，0乘任何数为0
        int carry = 0;           // carry表示进位数，刚开始进位为0
        int j = 0;

        for (int i = 2; i <= numN; i++)     // N的阶乘
        {
            for (j = 1; j <= point; j++)    // 循环array[]，让每一位都与i乘
            {
                int temp = array[j] * i + carry;    // temp变量表示不考虑进位的值
                carry = temp / 10;                  // 计算进位大小
                array[j] = temp % 10;               // 计算本位值
            }
            // 处理最后一位的进位情况
            // 由于计算数组的最后一位也得考虑进位情况，所以用循环讨论
            // 因为可能最后一位可以进多位；比如 12 * 本位数8，可以进两位
            while(carry)                        // 当进位数存在时，循环的作用就是将一个数分割，分割的每一位放入数组中
            {
                array[j] = carry % 10;
                carry = carry / 10;
                j++;                            // 表示下一位
            }
            printf("%d\n",point);
            point = j - 1;                      // 由于上面while中循环有j++,所以位会多出一位，这里减去
        }
        
        for (int i = point; i >= 1; i--)        // 逆序打印结果
        {
            printf("%d", array[i]);
        }
    }
}
