#include <system.h>

void gotopos(short x, short y) {
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);
}

void sleep(int mili) {
	Sleep(mili);
}

void clear_screen() {
	system("cls");
}

void draw_wall() {
	for (int x = 0; x < WINX; x++) {
		gotopos(x, 0);
		cout << char(220) << flush;
	}

	for (int y = 1; y < WINY - 1; y++) {
		gotopos(0, y);
		cout << char(219) << flush;
	}
	for (int y = 1; y < WINY - 1; y++) {
		gotopos(WINX - 1, y);
		cout << char(219) << flush;
	}

	for (int x = 0; x < WINX; x++) {
		gotopos(x, WINY - 1);
		cout << char(223) << flush;
	}
}

void showConsoleCursor(bool showFlag) {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
}