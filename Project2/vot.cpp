#include "vot.h"
#include <cmath>

Vot::Vot(){
	_x = 0;
	_y = 0;
	_z = 0;
	_v = 0;
}

Vot::Vot(float x,float y){
	_x = x;
	_y = y;
	_z = 0;
	_v = 0;
}

Vot::Vot(float x,float y,float z){
	_x = x;
	_y = y;
	_z = z;
	_v = 0;
}

Vot::Vot(float x,float y,float z,float v){
	_x = x;
	_y = y;
	_z = z;
	_v = v;
}

void Vot::set_X(float x){
	_x = x;
}

void Vot::set_Y(float y){
	_y = y;
}

void Vot::set_Z(float z){
	_z = z;
}

void Vot::set_V(float v){
	_v = v;
}
	
float Vot::get_X(){
	return _x;
}
	
float Vot::get_Y(){
	return _y;
}
	
float Vot::get_Z(){
	return _z;
}
	
float Vot::get_V(){
	return _v;
}

void Vot::Dichuyen(){
	_x += _v * std::cos(_z * 3.14159265f / 180.0f);  
    _y += _v * std::sin(_z * 3.14159265f / 180.0f);
}