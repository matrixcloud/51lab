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
    unsigned char step = 0;
    P2 = 0xFE;

    while (1) {
        if (P3_1 == 0) {
            delay(20);         // 按下防抖
            while (P3_1 == 0); // 直到松开
            delay(20);         // 松开防抖
            if (step == 0) {
                step = 7;
            } else {
                step--;
            }
            P2 = ~(0x01 << step); // 0000_0001 -> ~(0000_0010) = 1111_1101
        }
        if (P3_0 == 0) {
            delay(20);         // 按下防抖
            while (P3_0 == 0); // 直到松开
            delay(20);         // 松开防抖
            step++;
            if (step > 7) step = 0;
            P2 = ~(0x01 << step); // 0000_0001 -> ~(0000_0010) = 1111_1101
        }
    }
}