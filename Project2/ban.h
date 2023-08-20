#pragma once

class Ban{
private:
	int _w;
	int _h;

public:
	Ban();
	Ban(int,int);
	void set_W(int);
	void set_H(int);
	int get_W();
	int get_H();

};