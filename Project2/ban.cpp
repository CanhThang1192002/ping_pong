#include "ban.h"

Ban::Ban(){
	_w = 0;
	_h = 0;
}

Ban::Ban(int w, int h){
	_w = w;
	_h = h;
}

void Ban::set_W(int w){
	_w = w;
}

void Ban::set_H(int h){
	_h = h;
}

int Ban::get_W(){
	return _w;
}

int Ban::get_H(){
	return _h;
}