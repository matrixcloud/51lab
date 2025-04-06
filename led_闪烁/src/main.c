#include <8052.h>

// 12MHz时实现毫秒级延迟的写法
void delay(unsigned int ms)
{
    unsigned int i, j;
    for (i = ms; i > 0; i--)
        for (j = 123; j > 0; j--);
}

void main() {
    P2 = 0xFE;
    delay(500);
    P2 = 0xFF;
    delay(500);
}