#include <8052.h>
#include "lcd1602.h"
#include "matrixkey.h"

void main() 
{
    lcd_init(); // 初始化LCD1602
    lcd_show_str(1, 1, "Key: "); // 显示提示信息
    while (1) {
        char key = keydown();
        if (key) {
            lcd_show_char(2, 1, key); // 显示按键值
        }
    }
}