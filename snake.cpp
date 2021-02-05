#include <snake.h>

void Snake::set_direction() {
	char ch = _getch();
	if (ch == 72 && direction != 'd') {
		direction = 'u';
	}
	else if (ch == 80 && direction != 'u') {
		direction = 'd';
	}
	else if (ch == 75 && direction != 'r') {
		direction = 'l';
	}
	else if (ch == 77 && direction != 'l') {
		direction = 'r';
	}
}

char Snake::get_direction() {
	return direction;
}

int Snake::get_head_posx() {
	return snake_units[0].get_posx();
}

int Snake::get_head_posy() {
	return snake_units[0].get_posy();
}

void Snake::change_head_pos() {
	if (direction == 'u') {
		snake_units[0].set_pos(snake_units[0].get_posx(), snake_units[0].get_posy() - 1);
	}
	else if (direction == 'd') {
		snake_units[0].set_pos(snake_units[0].get_posx(), snake_units[0].get_posy() + 1);
	}
	else if (direction == 'l') {
		snake_units[0].set_pos(snake_units[0].get_posx() - 1, snake_units[0].get_posy());
	}
	else if (direction == 'r') {
		snake_units[0].set_pos(snake_units[0].get_posx() + 1, snake_units[0].get_posy());
	}
}

bool Snake::is_snake_eat_food(Food food) {
	if (snake_units[0].get_posx() == food.get_posx() && snake_units[0].get_posy() == food.get_posy()) {
		return true;
	} else {
		return false;
	}
}

void Snake::add_head() {
	Unit head(MIDDLE_OF_SCREEN, MIDDLE_OF_SCREEN);
	snake_units.push_back(head);
}

void Snake::add_unit() {
	Unit new_value(0, 0);
	int snake_units_size = snake_units.size() - 1;
	if (direction == 'u') {
		new_value.set_pos(snake_units[snake_units_size].get_posx(), snake_units[snake_units_size].get_posy() + 1);
		snake_units.push_back(new_value);
	} else if(direction == 'd') {
		new_value.set_pos(snake_units[snake_units_size].get_posx(), snake_units[snake_units_size].get_posy() - 1);
		snake_units.push_back(new_value);
	} else if (direction == 'l') {
		new_value.set_pos(snake_units[snake_units_size].get_posx() + 1, snake_units[snake_units_size].get_posy());
		snake_units.push_back(new_value);
	} else if (direction == 'r') {
		new_value.set_pos(snake_units[snake_units_size].get_posx() - 1, snake_units[snake_units_size].get_posy());
		snake_units.push_back(new_value);
	}
}

bool Snake::is_out_of_board(bool running) {
	//if snake go out of board this function return
	//false and make running variable in int main to
	//false and game will end.
	if (snake_units[0].get_posy() < 1 || snake_units[0].get_posy() > WINY - 2) {
		return false;
	}
	else if (snake_units[0].get_posx() < 1 || snake_units[0].get_posx() > WINX - 2) {
		return false;
	}
	else {
		return true;
	}
}

bool Snake::bite_itself (bool running) {
	for (int index = 1; index < snake_units.size(); index++) {
		if (snake_units[index].get_posx() == this -> get_head_posx() && snake_units[index].get_posy() == this -> get_head_posy()) {
			return false;
		}
	}

	return true;
}

void Snake::draw_snake() {
	//draw head with red color
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);
	gotopos(snake_units[0].get_posx(), snake_units[0].get_posy());
	cout << 0 << flush;

	//snake body units with blue color
	SetConsoleTextAttribute(hConsole, 9);
	for (int index = 1; index < snake_units.size(); index++) {
		gotopos(snake_units[index].get_posx(), snake_units[index].get_posy());
		cout << '0' << flush;
	}

	//make cursur color white again! (white will use in walls)
	SetConsoleTextAttribute(hConsole, 15);
}

void Snake::sort_units() {
	for (int index = snake_units.size() - 1; index > 0; index--) {
		snake_units[index].set_pos(snake_units[index - 1].get_posx(), snake_units[index - 1].get_posy());
	}
}

int Snake::size() {
	return snake_units.size();
}