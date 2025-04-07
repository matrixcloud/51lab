#include "lcd1602.h"

void main() {
    lcd_init();
    lcd_show_str(1, 1, "Hello, World!");
}