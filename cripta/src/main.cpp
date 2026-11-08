#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include "map.h"

static void enableAnsi() {
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD mode = 0;
	GetConsoleMode(h, &mode);
	SetConsoleMode(h, mode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);
}

static void draw(const Map& map, int px, int py) {
	std::string out = "\x1b[H";
	for (int y = 0; y < map.height(); ++y) {
		for (int x = 0; x < map.width(); ++x) {
			if (x == px && y == py)
				out += "\x1b[32m@\x1b[0m";
			else if (map.tileAt(x, y) == '#')
				out += "\x1b[90m#\x1b[0m";
			else
				out += map.tileAt(x, y);
		}
		out += '\n';
	}
	out += "\nMove: WASD  Quit: Q\n";
	std::cout << out << std::flush;
}

int main() {
	enableAnsi();
	std::cout << "\x1b[2J\x1b[?25l";

	Map map(80, 24);
	int px = 2, py = 2;

	bool running = true;
	while (running) {
		draw(map, px, py);

		int dx = 0, dy = 0;
		switch (_getch()) {
		case 'w': case 'W': dy = -1; break;
		case 's': case 'S': dy = 1; break;
		case 'a': case 'A': dx = -1; break;
		case 'd': case 'D': dx = 1; break;
		case 'q': case 'Q': running = false; break;
		}
		if (map.isWalkable(px + dx, py + dy)) {
			px += dx;
			py += dy;
		}
	}

	std::cout << "\x1b[?25h\x1b[2J\x1b[Hsee you soon.\n";
	return 0;
}