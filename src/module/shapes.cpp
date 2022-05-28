#include <shapes.h>
#include <iostream>
#include <graphics.h>


void print_text(std::string text, int x, int  y , int size)
{
    char *logo = new char[text.length() + 1];
    strcpy(logo, text.c_str());
    settextstyle(BOLD_FONT, HORIZ_DIR, size);
    outtextxy(x - textwidth(logo) / 2, y - textheight(logo) / 2, logo);
}
