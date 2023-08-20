#pragma once

class Vot
{
private:
	int _x;
	int _y;
	int _z;
	int _v;

public:
	Vot();
	Vot(int,int);
	Vot(int,int,int);
	Vot(int,int,int,int);
	void set_X(int);
	void set_Y(int);
	void set_Z(int);
	void set_V(int);
	int get_X();
	int get_Y();
	int get_Z();
	int get_V();

};
