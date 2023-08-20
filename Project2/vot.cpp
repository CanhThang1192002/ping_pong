#include "vot.h"

Vot::Vot(){
	_x = 0;
	_y = 0;
	_z = 0;
	_v = 0;
}

Vot::Vot(int x,int y){
	_x = x;
	_y = y;
	_z = 0;
	_v = 0;
}

Vot::Vot(int x,int y,int z){
	_x = x;
	_y = y;
	_z = z;
	_v = 0;
}

Vot::Vot(int x,int y,int z,int v){
	_x = x;
	_y = y;
	_z = z;
	_v = v;
}

void Vot::set_X(int x){
	_x = x;
}

void Vot::set_Y(int y){
	_y = y;
}

void Vot::set_Z(int z){
	_z = z;
}

void Vot::set_V(int v){
	_v = v;
}
	
int Vot::get_X(){
	return _x;
}
	
int Vot::get_Y(){
	return _y;
}
	
int Vot::get_Z(){
	return _z;
}
	
int Vot::get_V(){
	return _v;
}