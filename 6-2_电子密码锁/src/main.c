#include <8052.h>
#include <string.h>
#include "lcd1602.h"
#include "matrixkey.h"

#define PASS_LEN 8

const char* PASS = "225ABC";

void show_result(char* input) {
    if (strcmp(input, PASS) == 0) {
        lcd_show_str(1, 12, "OK");
    } else {
        lcd_show_str(1, 12, "ERR");
    }
}

void main() 
{
    lcd_init(); 
    lcd_show_str(1, 1, "Password: ");
    char input[PASS_LEN + 1];
    unsigned int i = 0;

    while (1) {
        char key = keydown();
        
        switch (key) {
            case '#':
                input[i++] = '\0';
                show_result(input);
                i = 0;
                break;
            case '\0':
                break;
            default:
                if (i >= PASS_LEN) {
                    break; 
                }
                input[i++] = key;
                lcd_show_str(2, 1, input);
                break;
        }
    }
}