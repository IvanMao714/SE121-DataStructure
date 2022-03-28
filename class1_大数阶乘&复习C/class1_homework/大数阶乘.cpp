#include<stdio.h>
#define MAX 100000                // ��Ϊ10000������򻺴���С�����

int main()
{
    int numN = 0;                 // ������N
    while (scanf("%d",&numN) != EOF)
    {
        if (numN < 1 || numN >= 10000)
        {
            break;
        }
        
        int array[MAX] = {0};   
        array[1] = 1;            // ��array[1]��ʼ
        int point = 1;           // point��ʾλ�����տ�ʼֻ��һλarray[1] �� array[1] = 1������Ϊ0��0���κ���Ϊ0
        int carry = 0;           // carry��ʾ��λ�����տ�ʼ��λΪ0
        int j = 0;

        for (int i = 2; i <= numN; i++)     // N�Ľ׳�
        {
            for (j = 1; j <= point; j++)    // ѭ��array[]����ÿһλ����i��
            {
                int temp = array[j] * i + carry;    // temp������ʾ�����ǽ�λ��ֵ
                carry = temp / 10;                  // �����λ��С
                array[j] = temp % 10;               // ���㱾λֵ
            }
            // �������һλ�Ľ�λ���
            // ���ڼ�����������һλҲ�ÿ��ǽ�λ�����������ѭ������
            // ��Ϊ�������һλ���Խ���λ������ 12 * ��λ��8�����Խ���λ
            while(carry)                        // ����λ������ʱ��ѭ�������þ��ǽ�һ�����ָ�ָ��ÿһλ����������
            {
                array[j] = carry % 10;
                carry = carry / 10;
                j++;                            // ��ʾ��һλ
            }
            printf("%d\n",point);
            point = j - 1;                      // ��������while��ѭ����j++,����λ����һλ�������ȥ
        }
        
        for (int i = point; i >= 1; i--)        // �����ӡ���
        {
            printf("%d", array[i]);
        }
    }
}
