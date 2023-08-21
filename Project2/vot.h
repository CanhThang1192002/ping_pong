#pragma once

class Vot
{
private:
	float _x;
	float _y;
	float _z;
	float _v;

public:
	Vot();
	Vot(float,float);
	Vot(float,float,float);
	Vot(float,float,float,float);
	void set_X(float);
	void set_Y(float);
	void set_Z(float);
	void set_V(float);
	float get_X();
	float get_Y();
	float get_Z();
	float get_V();
	void Dichuyen();
};
