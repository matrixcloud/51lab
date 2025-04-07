#include <reg51.h>

__sbit __at (0xA6) LCD_RS;
__sbit __at (0xA5) LCD_RW; 
__sbit __at (0xA7) LCD_EN;

#define LCD_DATA_PORT P0

/**
 * @brief  LCD1602延时函数，12MHz调用可延时1ms
 * @param  无
 * @retval 无
 */
void lcd_delay()
{
    unsigned char i, j;

    i = 2;
    j = 239;
    do {
        while (--j);
    } while (--i);
}

/**
 * @brief  LCD1602写命令
 * @param  command 要写入的命令
 * @retval 无
 */
void lcd_write_command(unsigned char command)
{
    LCD_RS       = 0;
    LCD_RW       = 0;
    LCD_DATA_PORT = command;
    LCD_EN       = 1;
    lcd_delay();
    LCD_EN = 0;
    lcd_delay();
}

/**
 * @brief  LCD1602写数据
 * @param  data 要写入的数据
 * @retval 无
 */
void lcd_write_data(unsigned char data)
{
    LCD_RS       = 1;
    LCD_RW       = 0;
    LCD_DATA_PORT = data;
    LCD_EN       = 1;
    lcd_delay();
    LCD_EN = 0;
    lcd_delay();
}

/**
 * @brief  LCD1602设置光标位置
 * @param  line 行位置，范围：1~2
 * @param  column 列位置，范围：1~16
 * @retval 无
 */
void lcd_set_cursor(unsigned char line, unsigned char column)
{
    if (line == 1) {
        lcd_write_command(0x80 | (column - 1));
    } else if (line == 2) {
        lcd_write_command(0x80 | (column - 1 + 0x40));
    }
}

/**
 * @brief  LCD1602初始化函数
 * @param  无
 * @retval 无
 */
void lcd_init()
{
    lcd_write_command(0x38); // 八位数据接口，两行显示，5*7点阵
    lcd_write_command(0x0c); // 显示开，光标关，闪烁关
    lcd_write_command(0x06); // 数据读写操作后，光标自动加一，画面不动
    lcd_write_command(0x01); // 光标复位，清屏
}

/**
 * @brief  在LCD1602指定位置上显示一个字符
 * @param  line 行位置，范围：1~2
 * @param  column 列位置，范围：1~16
 * @param  ch 要显示的字符
 * @retval 无
 */
void lcd_show_char(unsigned char line, unsigned char column, char ch)
{
    lcd_set_cursor(line, column);
    lcd_write_data(ch);
}

/**
 * @brief  在LCD1602指定位置开始显示所给字符串
 * @param  line 起始行位置，范围：1~2
 * @param  column 起始列位置，范围：1~16
 * @param  str 要显示的字符串
 * @retval 无
 */
void lcd_show_str(unsigned char line, unsigned char column, char *str)
{
    unsigned char i;
    lcd_set_cursor(line, column);
    for (i = 0; str[i] != '\0'; i++) {
        lcd_write_data(str[i]);
    }
}

/**
 * @brief  返回值=x的y次方
 */
int lcd_pow(int x, int y)
{
    unsigned char i;
    int res = 1;
    for (i = 0; i < y; i++) {
        res *= x;
    }
    return res;
}

/**
 * @brief  在LCD1602指定位置开始显示所给数字
 * @param  line 起始行位置，范围：1~2
 * @param  column 起始列位置，范围：1~16
 * @param  num 要显示的数字，范围：0~65535
 * @param  length 要显示数字的长度，范围：1~5
 * @retval 无
 */
void lcd_show_num(unsigned char line, unsigned char column, unsigned int num, unsigned char length)
{
    unsigned char i;
    lcd_set_cursor(line, column);
    for (i = length; i > 0; i--) {
        lcd_write_data(num / lcd_pow(10, i - 1) % 10 + '0');
    }
}

/**
 * @brief  在LCD1602指定位置开始以有符号十进制显示所给数字
 * @param  line 起始行位置，范围：1~2
 * @param  column 起始列位置，范围：1~16
 * @param  num 要显示的数字，范围：-32768~32767
 * @param  length 要显示数字的长度，范围：1~5
 * @retval 无
 */
void lcd_show_signed_num(unsigned char line, unsigned char column, int num, unsigned char length)
{
    unsigned char i;
    unsigned int num1;
    lcd_set_cursor(line, column);
    if (num >= 0) {
        lcd_write_data('+');
        num1 = num;
    } else {
        lcd_write_data('-');
        num1 = -num;
    }
    for (i = length; i > 0; i--) {
        lcd_write_data(num1 / lcd_pow(10, i - 1) % 10 + '0');
    }
}

/**
 * @brief  在LCD1602指定位置开始以十六进制显示所给数字
 * @param  line 起始行位置，范围：1~2
 * @param  column 起始列位置，范围：1~16
 * @param  num 要显示的数字，范围：0~0xFFFF
 * @param  length 要显示数字的长度，范围：1~4
 * @retval 无
 */
void lcd_show_hex(unsigned char line, unsigned char column, unsigned int num, unsigned char length)
{
    unsigned char i, single_num;
    lcd_set_cursor(line, column);
	for (i = length; i > 0; i--) {
        single_num = num / lcd_pow(16, i - 1) % 16;
        if (single_num < 10) {
            lcd_write_data(single_num + '0');
        } else {
            lcd_write_data(single_num - 10 + 'A');
        }
    }
}

/**
 * @brief  在LCD1602指定位置开始以二进制显示所给数字
 * @param  line 起始行位置，范围：1~2
 * @param  column 起始列位置，范围：1~16
 * @param  num 要显示的数字，范围：0~1111 1111 1111 1111
 * @param  length 要显示数字的长度，范围：1~16
 * @retval 无
 */
void lcd_show_bin(unsigned char line, unsigned char column, unsigned int num, unsigned char length)
{
    unsigned char i;
    lcd_set_cursor(line, column);
    for (i = length; i > 0; i--) {
        lcd_write_data(num / lcd_pow(2, i - 1) % 2 + '0');
    }
}
