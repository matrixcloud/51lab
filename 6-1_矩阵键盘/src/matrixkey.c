#include <8052.h>
#include "delay.h"

char keydown() {
    char key = '\0';
    // the first row
    P1 = 0xFF;
    P1_7 = 0;
    if (P1_3 == 0) {
        delay(10); 
        if (P1_3 == 0) {
            while (P1_3 == 0);
            delay(10);
            key = '1';
        }
    }
    if (P1_2 == 0) {
        delay(10); 
        if (P1_2 == 0) {
            while (P1_2 == 0);
            delay(10);
            key = '2';
        }
    }
    if (P1_1 == 0) {
        delay(10); 
        if (P1_1 == 0) {
            while (P1_1 == 0);
            delay(10);
            key = '3';
        }
    }
    if (P1_0 == 0) {
        delay(10); 
        if (P1_0 == 0) {
            while (P1_0 == 0);
            delay(10);
            key = '4';
        }
    }

    // the second row
    P1 = 0xFF;
    P1_6 = 0;
    if (P1_3 == 0) {
        delay(10); 
        if (P1_3 == 0) {
            while (P1_3 == 0);
            delay(10);
            key = '5';
        }
    }
    if (P1_2 == 0) {
        delay(10); 
        if (P1_2 == 0) {
            while (P1_2 == 0);
            delay(10);
            key = '6';
        }
    }
    if (P1_1 == 0) {
        delay(10); 
        if (P1_1 == 0) {
            while (P1_1 == 0);
            delay(10);
            key = '7';
        }
    }
    if (P1_0 == 0) {
        delay(10); 
        if (P1_0 == 0) {
            while (P1_0 == 0);
            delay(10);
            key = '8';
        }
    }
    // the third row
    P1 = 0xFF;
    P1_5 = 0;
    if (P1_3 == 0) {
        delay(10); 
        if (P1_3 == 0) {
            while (P1_3 == 0);
            delay(10);
            key = '9';
        }
    }
    if (P1_2 == 0) {
        delay(10); 
        if (P1_2 == 0) {
            while (P1_2 == 0);
            delay(10);
            key = 'A';
        }
    }
    if (P1_1 == 0) {
        delay(10); 
        if (P1_1 == 0) {
            while (P1_1 == 0);
            delay(10);
            key = 'B';
        }
    }
    if (P1_0 == 0) {
        delay(10); 
        if (P1_0 == 0) {
            while (P1_0 == 0);
            delay(10);
            key = 'C';
        }
    }
    // the fourth row
    P1 = 0xFF;
    P1_4 = 0;
    if (P1_3 == 0) {
        delay(10); 
        if (P1_3 == 0) {
            while (P1_3 == 0);
            delay(10);
            key = 'D';
        }
    }
    if (P1_2 == 0) {
        delay(10); 
        if (P1_2 == 0) {
            while (P1_2 == 0);
            delay(10);
            key = 'E';
        }
    }
    if (P1_1 == 0) {
        delay(10); 
        if (P1_1 == 0) {
            while (P1_1 == 0);
            delay(10);
            key = 'F';
        }
    }
    if (P1_0 == 0) {
        delay(10); 
        if (P1_0 == 0) {
            while (P1_0 == 0);
            delay(10);
            key = '*';
        }
    }

    return key;
}