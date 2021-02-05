#ifndef UNIT_H
#define UNIT_H

#include <system.h>

class Unit {
	private: int posx, posy;

	public: Unit(int _posx, int _posy);

	public: void set_pos(int _posx, int _posy);

	public: int get_posx();

	public: int get_posy();

	public: void sumx(Unit pos);

	public: void sumy(Unit pos);
};

#endif
