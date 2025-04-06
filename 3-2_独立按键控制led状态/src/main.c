#include <8052.h>

// 12MHz时实现毫秒级延迟的写法
void delay(unsigned int ms)
{
    unsigned int i, j;
    for (i = ms; i > 0; i--)
        for (j = 123; j > 0; j--);
}

void main()
{
    while (1) {
        if (P3_1 == 0) {
            delay(20);         // 按下防抖
            while (P3_1 == 0); // 直到松开
            delay(20);         // 松开防抖
            P2_7 = !P2_7;
        }
    }
}