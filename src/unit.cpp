#include <unit.h>

Unit::Unit(int _posx, int _posy) {
	posx = _posx;
	posy = _posy;
}

void Unit::set_pos(int _posx, int _posy) {
	posx = _posx;
	posy = _posy;
}

int Unit::get_posx() {
	return posx;
}

int Unit::get_posy() {
	return posy;
}

void Unit::sumx(Unit pos) {
	int sum = this->posx + pos.get_posx();
	this->set_pos(sum, this->get_posy());
}

void Unit::sumy(Unit pos) {
	int sum = this->posy + pos.get_posy();
	this->set_pos(this->get_posx(), sum);
}
