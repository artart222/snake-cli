#ifndef SNAKE_H
#define SNAKE_H

#include <system.h>
#include <food.h>
#include <unit.h>
#include <vector>

class Snake {
	private: char direction;
	private: vector <Unit> snake_units;

	public: void set_direction();

	public: char get_direction();

	public: int get_head_posx();

	public: int get_head_posy();	

	public: void change_head_pos();

	public: bool is_snake_eat_food(Food food);

	public: void add_head();

	public: void add_unit();

	public: bool is_out_of_board(bool running);

	public: bool bite_itself(bool running);

	public: void draw_snake();

	public: void sort_units();

	public: int size();
};

#endif
