#include <food.h>

void Food::set_new_pos(int _x, int _y) {
	x = _x;
	y = _y;
}

int Food::get_posx() {
	return x;
}

int Food::get_posy() {
	return y;
}

void Food::draw_food() {
	gotopos(x, y);
	cout << char(254) << flush;
}

/*void Food::generae_food_pos(vector <Snake> snake_units) {
	vector <vector <int>> possible_food_pos;
	
	for (int y = 1; y < GAMEY; y++) {
		for (int x = 1; x < GAMEX; x++) {
			possible_food_pos.push_back(vector <int> {x, y});
		}
	}

	for (int y = 0; y < possible_food_pos.size(); y++) {
		for (int x = 0; x < possible_food_pos.size(); x++) {
			for (int index = 0; index < snake_units.size(); index++) {
				if (snake_units[index].get_posx() == NULL, snake_units.get_posy() == NULL) {
					
				}
			}
		}
	}

	int random_index = rand() % possible_food_pos.size();
	this -> set_new_pos(possible_food_pos[0][0], possible_food_pos[0][1]);
}*/