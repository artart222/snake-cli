#include <snake.h>
#include <food.h>
#include <unit.h>
#include <system.h>

int main() {
	system("mode con: cols=48 lines=27");
	showConsoleCursor(0);
	srand(time(NULL));

	bool running = true;
	bool condition1;
	bool condition2;

	Snake snake;
	snake.add_head();
	Food food;
	food.set_new_pos((rand() % 46) + 1, (rand() % 25) + 1);

	while (running) {
		if (snake.get_direction() == 'r' || snake.get_direction() == 'l') {
			sleep(FPS);
		} else {
			sleep(FPS * 2);
		}
		
		clear_screen();
		draw_wall();
	
		food.draw_food();

		snake.sort_units();

		if (_kbhit() == 1) {
			snake.set_direction();
		}
		snake.change_head_pos();

		condition1 = snake.is_out_of_board(running);
		condition2 = snake.bite_itself(running);

		if (condition1 == false || condition2 == false) {
			running = false;
		}

		snake.draw_snake();

		if (snake.is_snake_eat_food(food)) {
			snake.add_unit();
			food.set_new_pos((rand() % 46) + 1, (rand() % 25) + 1);
		}
	}

	return 0;
}
