#ifndef SYSTEM_H
#define SYSTEM_H

#include <windows.h>
#include <conio.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

#define GAMEX 46
#define GAMEY 25

//These two variables are for console lenght and width.
//These are bigger than GAMEX and GAMEY becuase contain
//walls of border
#define WINX 48
#define WINY 27

#define MIDDLE_OF_SCREEN 11
#define FPS 1000 / 40
#define MAX_UNIT WINX * WINY

using namespace std;

void gotopos(short x, short y);

void sleep(int mili);

void clear_screen();

void draw_wall();

void showConsoleCursor(bool showFlag);

#endif