#pragma once
#include "ban.h"
#include "bong.h"
#include "vot.h"

class Game
{
private:
	Ban _ban;
	Bong _bong;
	Vot _vot;
	int _diem;
	Vot _bot;
	int _x;
public:
	Game();
	void Start();
	void Vacham();
	void Bot();
};
