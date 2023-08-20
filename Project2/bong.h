#pragma once
class Bong
{
private:
	float _x;
	float _y;
	float _h;
	float _z;
	float _v;
public:
	Bong();
	Bong(float,float);
	Bong(float,float,float);
	Bong(float,float,float,float);
	Bong(float,float,float,float,float);
	void set_X(float);
	void set_Y(float);
	void set_H(float);
	void set_Z(float);
	void set_V(float);
	float get_X();
	float get_Y();
	float get_H();
	float get_Z();
	float get_V();
	void Chuyendong();
};
