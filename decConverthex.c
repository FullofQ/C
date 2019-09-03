#include<stdio.h>
void main()
{
    int i, x; // x表示欲转换的10进制数
    int data[10], index=0;  // data数组存放转换后的16进制数，index表示下标
    scanf("%d", &x);  // 接受欲转换的10进制数

    for(i=0; i<10; i++)  // 对数组data进行初始赋值操作
        data[i] = 0;
    printf("%d convert to hex:\n", x);

    // 反复相除取余，并将余数存放在data数组中
    while(x>0){
        data[index] = x%16;
        x = x/16;
        index++;
    }

    // 逆序输出data数组中的元素，即为10进制数对应的16进制数
    for(i=index-1; i>=0; i--)
        printf("%d", data[i]);
    printf("\n");
}