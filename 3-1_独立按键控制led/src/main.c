#include <8052.h>

void main() {
    while (1) {
        if (P3_1 == 0) {
            P2_7 = 0;
        } else {
            P2_7 = 1;
        }
    }
}