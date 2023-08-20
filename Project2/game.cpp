#include "game.h"
#include "Windows.h"
#include <SFML/Graphics.hpp>
#include <conio.h>
#include <chrono>
#include <iostream>
#include <ctime>

using namespace sf;

Game::Game(){
	_ban = Ban(558, 641);
	_vot = Vot(282,413);
	_bong = Bong(280,90,0.0f,120.0f,2.0f);
	_diem = 0;
	_bot = Vot(282,60);
	_x = 0;
}

void Game::Vacham(){
	srand(time(NULL));
	float x_bong = _bong.get_X() - 7.5;
	float y_bong = _bong.get_Y() - 7.5;
	int x_vot = _vot.get_X();
	int y_vot = _vot.get_Y();
	std::cout <<"     --->  x bong: " << x_bong << "  y bong: " << y_bong << "  x vot: " << x_vot << "  y vot:  " << y_vot << std::endl;
	if(x_bong > x_vot-20 && x_bong < x_vot+20 && y_bong > y_vot - 30 && y_bong < y_vot + 30){
		if(x_bong <= 282 && x_bong >= 190){
			float x = -90 + rand() % 21;
			_bong.set_Z(x);
		}
		if(x_bong <= 374 && x_bong > 282){
			float x = -110 + rand() % 21;
			_bong.set_Z(x);
		}
		if(x_bong < 190 && x_bong >= 99){
			float x = -80 + rand() % 21;
			_bong.set_Z(x);
		}
		if(x_bong <= 466 && x_bong > 374){
			float x = -120 + rand() % 21;
			_bong.set_Z(x);
		}
		if(x_bong < 99){
			float x = -70 + rand() % 31;
			_bong.set_Z(x);
		}
		if(x_bong > 466){
			float x = -140 + rand() % 31;
			_bong.set_Z(x);
		}
	}
}

void Game::Bot(){
	srand(time(NULL));
	float x_bong = _bong.get_X() - 7.5;
	float y_bong = _bong.get_Y() - 7.5;
	int x_bot = _bot.get_X();
	int y_bot = _bot.get_Y();
	//std::cout <<"     --->  x bong: " << x_bong << "  y bong: " << y_bong << "  x bot: " << x_bot << "  y bot:  " << y_bot << std::endl;
	if(x_bong > x_bot-20 && x_bong < x_bot+20 && y_bong > y_bot - 30 && y_bong < y_bot){
		if(x_bong <= 282 && x_bong >= 230){
			float x = 60 + rand() % 31;
			_bong.set_Z(x);
		}
		if(x_bong <= 334 && x_bong > 282){
			float x = 90 + rand() % 31;
			_bong.set_Z(x);
		}
		if(x_bong < 230 && x_bong >= 178){
			float x = 45 + rand() % 56;
			_bong.set_Z(x);
		}
		if(x_bong <= 386 && x_bong > 334){
			float x = 80 + rand() % 56;
			_bong.set_Z(x);
		}
		if(x_bong < 178){
			float x = 50 + rand() % 11;
			_bong.set_Z(x);
		}
		if(x_bong > 386){
			float x = 120 + rand() % 11;
			_bong.set_Z(x);
		}
	}
}

void Game::Start(){
	int x = 0, y = 0;
	RenderWindow window( VideoMode(_ban.get_W(),_ban.get_H()), "SFML Image Example");
	Texture ban, vot, bong, bot;
	if (!ban.loadFromFile("./img/anh1.png")) {
		// Xử lý lỗi khi không thể nạp hình ảnh
		return ;
	}
	if (!vot.loadFromFile("./img/anh2.png")) {
		// Xử lý lỗi khi không thể nạp hình ảnh
		return ;
	}
	if (!bong.loadFromFile("./img/anh3.png")) {
		// Xử lý lỗi khi không thể nạp hình ảnh
		return ;
	}
	if (!bot.loadFromFile("./img/anh2.png")) {
		// Xử lý lỗi khi không thể nạp hình ảnh
		return ;
	}
	Sprite sprite_ban(ban);
	Sprite sprite_vot(vot);
	Sprite sprite_bong(bong);
	Sprite sprite_bot(bot);

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
			if (event.type == sf::Event::MouseMoved) {
				x = event.mouseMove.x;
				y = event.mouseMove.y;
			}
		}

		window.clear( Color::White);
		window.draw(sprite_ban);

		_bong.Chuyendong();
		sprite_bong.setPosition(_bong.get_X()-7.5,_bong.get_Y()-7.5);
		window.draw(sprite_bong);
		Vacham();

		int newx = x, newy = y;
		if(y < 215) newy = 215;
		if(y > 600) newy = 600;
		if(x < 40) newx = 40;
		if(x > 520) newx = 520;
		_vot.set_X(newx);
		_vot.set_Y(newy);
		sprite_vot.setPosition(_vot.get_X()-20,_vot.get_Y()-30);
		std::cout << "x:  " << x << "  y:  " << y << std::endl;
		window.draw(sprite_vot);

		Bot();
		_bot.set_X(_bong.get_X());
		sprite_bot.setPosition(_bot.get_X()-20,_bot.get_Y()-30);
		window.draw(sprite_bot);

		_bong.set_V(_bong.get_V() + 0.001);

		window.display();
	}
}