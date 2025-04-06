#include <8052.h>

// 12MHz时实现毫秒级延迟的写法
void delay(unsigned int ms)
{
    unsigned int i, j;
    for (i = ms; i > 0; i--)
        for (j = 123; j > 0; j--);
}

const unsigned char HEX_VALS[] = {0xFE, 0xFD, 0xFB, 0xF7, 0xEF, 0xDF, 0xBF, 0x7F};

void main() {
    while(1) {
        for (int i = 0; i <= 7; i++) {
            P2 = HEX_VALS[i];
            delay(500);
        }
        for (int i = 6; i >= 1; i--) {
            P2 = HEX_VALS[i];
            delay(500);
        }
    }
}