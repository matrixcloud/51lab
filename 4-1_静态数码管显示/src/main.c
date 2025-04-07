#include <8052.h>

typedef unsigned int u16;
typedef unsigned char u8;

#define SMG_A_DP_PORT P0 // 数码管段码口

const u8 GSMG_CODE[17] = {
    0x3f, // 0011_1111 -> abcdef, 0
    0x06, // 0000_0110 -> bc, 1
    0x5b, // 2
    0x4f, // 3
    0x66,
    0x6d,
    0x7d,
    0x07,
    0x7f,
    0x6f,
    0x77,
    0x7c,
    0x39,
    0x5e,
    0x79,
    0x71, // 0111_0001 -> abcd, F
    0x00, // 0000_0000 -> 空
};

void display(u8 loc, u8 number) {
    switch (loc) {
        case 7:
            P2_4 = 0;
            P2_3 = 0;
            P2_2 = 1;
            break;
        case 6:
            P2_4 = 0;
            P2_3 = 1;
            P2_2 = 0;
            break;
        case 5:
            P2_4 = 0;
            P2_3 = 1;
            P2_2 = 1;
            break;
        case 4:
            P2_4 = 1;
            P2_3 = 0;
            P2_2 = 0;
            break;
        case 3:
            P2_4 = 1;
            P2_3 = 0;
            P2_2 = 1;
            break;
        case 2:
            P2_4 = 1;
            P2_3 = 1;
            P2_2 = 0;
            break;
        case 1:
            P2_4 = 1;
            P2_3 = 1;
            P2_2 = 1;
            break;
        case 0:
        default:
            P2_4 = 0;
            P2_3 = 0;
            P2_2 = 0;
            break;
    }
    SMG_A_DP_PORT = GSMG_CODE[number];
}

void main() {
    display(3, 6);
    while (1);
}

