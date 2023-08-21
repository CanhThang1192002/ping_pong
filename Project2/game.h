#pragma once
#include "ban.h"
#include "bong.h"
#include "vot.h"

class Game
{
private:
	Ban _ban;
	Bong _bong;
	Vot _vot1;
	Vot _vot2;
	int _diem;
	int _x;
public:
	Game();
	void Start_bot();
	void Vacham();
	void Bot();
	void Start_nguoi();
	void Hainguoi();
	int game_start();
};
