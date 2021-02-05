#ifndef FOOD_H
#define FOOD_H

#include <system.h>

class Food {
	private: int x, y;

	public: void set_new_pos(int _x, int _y);

	public: int get_posx();

	public: int get_posy();

	public: void draw_food();

	//public: void generae_food_pos(vector <Snake> snake_units);
};

#endif
