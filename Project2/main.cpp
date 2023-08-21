#include "game.h"
using namespace std;

int main() {
	Game game;
	int x;
	x = game.game_start();
	if(x == 1){
		game.Start_bot();
	}
	if(x == 2){
		game.Start_nguoi();
	}
	return 0;
}

