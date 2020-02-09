#include "global.h"

void console_color(ui theColour);
void console_xy(int x, int y);
void clrscr();
void dup(unsigned char character, int n);
void print_status(char *status, int color);
void printUsage();
void draw_header();
void draw_stat();
void print_result();
void set_title(string title);
void print_special_char(wchar_t value);
//!!!todo move to algo-specific
void extract_key(char *buffer);
