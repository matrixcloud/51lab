#ifndef __LCD1602_H__
#define __LCD1602_H__

// 用户调用函数：
void lcd_init();
void lcd_show_char(unsigned char line, unsigned char column, char ch);
void lcd_show_str(unsigned char line, unsigned char column, char *str);
void lcd_show_num(unsigned char line, unsigned char column, unsigned int num, unsigned char length);
void lcd_show_signed_num(unsigned char line, unsigned char column, int num, unsigned char length);
void lcd_show_hex(unsigned char line, unsigned char column, unsigned int num, unsigned char length);
void lcd_show_bin(unsigned char line, unsigned char column, unsigned int num, unsigned char length);

#endif
