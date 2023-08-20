#include "bong.h"
#include <SFML/Graphics.hpp>
#include <cmath>

Bong::Bong(){
	_x = 0;
	_y = 0;
	_h = 0;
	_z = 0;
	_v = 0;
}

Bong::Bong(float x,float y){
	_x = x;
	_y = y;
	_h = 0;
	_z = 0;
	_v = 0;
}

Bong::Bong(float x,float y,float h){
	_x = x;
	_y = y;
	_h = h;
	_z = 0;
	_v = 0;
}

Bong::Bong(float x,float y,float h,float z){
	_x = x;
	_y = y;
	_h = h;
	_z = z;
	_v = 0;
}

Bong::Bong(float x,float y,float h,float z,float v){
	_x = x;
	_y = y;
	_h = h;
	_z = z;
	_v = v;
}

void Bong::set_X(float x){
	_x = x;
}

void Bong::set_Y(float y){
	_y = y;
}

void Bong::set_H(float h){
	_h = h;
}

void Bong::set_Z(float z){
	_z = z;
}

void Bong::set_V(float v){
	_v = v;
}
	
float Bong::get_X(){
	return _x;
}
	
float Bong::get_Y(){
	return _y;
}

float Bong::get_H(){
	return _h;
}
	
float Bong::get_Z(){
	return _z;
}
	
float Bong::get_V(){
	return _v;
}

void Bong::Chuyendong(){
	_x += _v * std::cos(_z * 3.14159265f / 180.0f);  //_v van toc, _z goc so vs truc ox;
    _y += _v * std::sin(_z * 3.14159265f / 180.0f);
	//_h = _h + (_v * std::sin(ampha)*t - (10*t*t)/2)/20;
	//_v = sqrt(pow(_v*sin(ampha) - 10*t, 2) + pow(_v*cos(ampha),2));
}