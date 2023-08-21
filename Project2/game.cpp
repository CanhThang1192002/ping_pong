#include "game.h"
#include "Windows.h"
#include <SFML/Graphics.hpp>
#include <conio.h>
#include <chrono>
#include <iostream>
#include <ctime>

using namespace sf;

Game::Game(){
	_ban = Ban();
	_vot1 = Vot();
	_vot2 = Vot();
	_bong = Bong(280,90,0.0f,120.0f,2.0f);
	_diem = 0;
	_x = 0;
}

void Game::Vacham(){
	srand(time(NULL));
	float x_bong = _bong.get_X() - 7.5;
	float y_bong = _bong.get_Y() - 7.5;
	float x_vot = _vot1.get_X();
	float y_vot = _vot1.get_Y();
	std::cout <<"     --->  x bong: " << x_bong << "  y bong: " << y_bong << "  x vot: " << x_vot << "  y vot:  " << y_vot << std::endl;
	if(x_bong > x_vot-20 && x_bong < x_vot+20 && y_bong > y_vot - 30 && y_bong < y_vot + 30){
		if(x_bong <= 282 && x_bong >= 190){
			float x = -92.5 + rand() % 22;
			_bong.set_Z(x);
		}
		if(x_bong <= 374 && x_bong > 282){
			float x = -108.5 + rand() % 22;
			_bong.set_Z(x);
		}
		if(x_bong < 190 && x_bong >= 99){
			float x = -76 + rand() % 19;
			_bong.set_Z(x);
		}
		if(x_bong <= 466 && x_bong > 374){
			float x = -122 + rand() % 19;
			_bong.set_Z(x);
		}
		if(x_bong < 99){
			float x = -61.5 + rand() % 15;
			_bong.set_Z(x);
		}
		if(x_bong > 466){
			float x = -132.5 + rand() % 15;
			_bong.set_Z(x);
		}
	}
}

void Game::Bot(){
	srand(time(NULL));
	float x_bong = _bong.get_X() - 7.5;
	float y_bong = _bong.get_Y() - 7.5;
	float x_bot = _vot2.get_X();
	float y_bot = _vot2.get_Y();
	//std::cout <<"     --->  x bong: " << x_bong << "  y bong: " << y_bong << "  x bot: " << x_bot << "  y bot:  " << y_bot << std::endl;
	if(x_bong > x_bot-20 && x_bong < x_bot+20 && y_bong > y_bot - 30 && y_bong < y_bot){
		if(x_bong <= 282 && x_bong >= 230){
			float x = 60 + rand() % 47;
			_bong.set_Z(x);
		}
		if(x_bong <= 334 && x_bong > 282){
			float x = 74 + rand() % 47;
			_bong.set_Z(x);
		}
		if(x_bong < 230 && x_bong >= 178){
			float x = 50.5 + rand() % 54;
			_bong.set_Z(x);
		}
		if(x_bong <= 386 && x_bong > 334){
			float x = 76 + rand() % 54;
			_bong.set_Z(x);
		}
		if(x_bong < 178){
			float x = 47.5 + rand() % 27;
			_bong.set_Z(x);
		}
		if(x_bong > 386){
			float x = 106.5 + rand() % 27;
			_bong.set_Z(x);
		}
	}
}

void Game::Start_bot(){
	float x = 0, y = 0;
	_ban.set_W(558);
	_ban.set_H(641);
	_vot1.set_X(282);
	_vot1.set_Y(413);
	_vot2.set_X(282);
	_vot2.set_Y(60);
	_bong.set_X(280);
	_bong.set_Y(90);
	RenderWindow window( VideoMode(850,641), "mot nguoi choi");
	Texture bg,ban, vot, bong, bot, text1, text2;
	if (!bg.loadFromFile("./img/bg1.png")) {
		// Xử lý lỗi khi không thể nạp hình ảnh
		return ;
	}
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
	if (!text1.loadFromFile("./img/botScore.png")) {
		// Xử lý lỗi khi không thể nạp hình ảnh
		return ;
	}
	if (!text2.loadFromFile("./img/yourScore.png")) {
		// Xử lý lỗi khi không thể nạp hình ảnh
		return ;
	}
	Sprite sprite_bg(bg);
	Sprite sprite_ban(ban);
	Sprite sprite_vot(vot);
	Sprite sprite_bong(bong);
	Sprite sprite_bot(bot);
	Sprite sprite_text1(text1);
	Sprite sprite_text2(text2);

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
			if (event.type ==  Event::MouseMoved) {
				x = event.mouseMove.x;
				y = event.mouseMove.y;
			}
		}

		window.clear( Color::White);
		window.draw(sprite_bg);
		sprite_text1.setPosition(600,20);
		window.draw(sprite_text1);
		sprite_text2.setPosition(600,350);
		window.draw(sprite_text2);

		window.draw(sprite_ban);

		_bong.Chuyendong();
		sprite_bong.setPosition(_bong.get_X()-7.5,_bong.get_Y()-7.5);
		window.draw(sprite_bong);
		Vacham();

		float newx = x, newy = y;
		if(y < 215) newy = 215;
		if(y > 600) newy = 600;
		if(x < 40) newx = 40;
		if(x > 520) newx = 520;
		_vot1.set_X(newx);
		_vot1.set_Y(newy);
		sprite_vot.setPosition(_vot1.get_X()-20,_vot1.get_Y()-30);
		std::cout << "x:  " << x << "  y:  " << y << std::endl;
		window.draw(sprite_vot);

		Bot();
		_vot2.set_X(_bong.get_X());
		sprite_bot.setPosition(_vot2.get_X()-20,_vot2.get_Y()-30);
		window.draw(sprite_bot);

		_bong.set_V(_bong.get_V() + 0.001);

		window.display();
	}
}

void Game::Hainguoi(){
	srand(time(NULL));
	float x_bong = _bong.get_X() - 7.5;
	float y_bong = _bong.get_Y() - 7.5;
	float x_vot1 = _vot1.get_X();
	float y_vot1 = _vot1.get_Y();
	float x_vot2 = _vot2.get_X();
	float y_vot2 = _vot2.get_Y();
	if(x_bong > x_vot1-12 && x_bong < x_vot1 && y_bong > y_vot1 - 33 && y_bong < y_vot1 + 20){
		if(y_bong <= 336 && y_bong > 279){
			float x = -6 + rand() % 18;
			_bong.set_Z(x);
		}
		if(y_bong <= 393 && y_bong > 336){
			float x = -12 + rand() % 18;
			_bong.set_Z(x);
		}
		if(y_bong <= 279 && y_bong > 222){
			float x = 0 + rand() % 17;
			_bong.set_Z(x);
		}
		if(y_bong <= 450 && y_bong > 393){
			float x = -17.5 + rand() % 18;
			_bong.set_Z(x);
		}
		if(y_bong <= 222){
			float x = 15 + rand() % 7;
			_bong.set_Z(x);
		}
		if(y_bong > 450){
			float x = -22 + rand() % 10;
			_bong.set_Z(x);
		}
	}

	if(x_bong > x_vot2-10 && x_bong < x_vot2+12 && y_bong > y_vot2 - 33 && y_bong < y_vot2 + 33){
		if(y_bong <= 336 && y_bong > 279){
			float x = -174 + rand() % 18;
			_bong.set_Z(x);
		}
		if(y_bong <= 393 && y_bong > 336){
			float x = -168 + rand() % 18;
			_bong.set_Z(x);
		}
		if(y_bong <= 279 && y_bong > 222){
			float x = 163 + rand() % 190;
			_bong.set_Z(x);
		}
		if(y_bong <= 450 && y_bong > 393){
			float x = -180 + rand() % 19;
			_bong.set_Z(x);
		}
		if(y_bong <= 222){
			float x = 158.5 + rand() % 18;
			_bong.set_Z(x);
		}
		if(y_bong > 450){
			float x = -158 + rand() % 10;
			_bong.set_Z(x);
		}
	}
}

void Game::Start_nguoi(){
	float x = 0, y = 0;
	_ban.set_W(900);
	_ban.set_H(515);
	_vot1.set_X(140);
	_vot1.set_Y(320);
	_vot2.set_X(745);
	_vot2.set_Y(320);
	_bong.set_X(444);
	_bong.set_Y(320);
	_bong.set_Z(0.0f);
	_bong.set_V(0.25f);
	_vot1.set_V(10.0f);
	_vot2.set_V(10.0f);
	_vot1.set_Z(77.0f);
	_vot2.set_Z(103.0f);

	RenderWindow window( VideoMode(900,600), "hai nguoi choi");
	Texture bg,ban, vot1, vot2, bong,text1,text2;
	if (!ban.loadFromFile("./img/anh4.png")) {
		// Xử lý lỗi khi không thể nạp hình ảnh
		return ;
	}
	if (!vot1.loadFromFile("./img/vot1.png")) {
		// Xử lý lỗi khi không thể nạp hình ảnh
		return ;
	}
	if (!vot2.loadFromFile("./img/vot2.png")) {
		// Xử lý lỗi khi không thể nạp hình ảnh
		return ;
	}
	if (!bong.loadFromFile("./img/anh3.png")) {
		// Xử lý lỗi khi không thể nạp hình ảnh
		return ;
	}
	if (!bg.loadFromFile("./img/bg2.png")) {
		// Xử lý lỗi khi không thể nạp hình ảnh
		return ;
	}
	if (!text1.loadFromFile("./img/aScore.png")) {
		// Xử lý lỗi khi không thể nạp hình ảnh
		return ;
	}
	if (!text2.loadFromFile("./img/bScore.png")) {
		// Xử lý lỗi khi không thể nạp hình ảnh
		return ;
	}
	Sprite sprite_ban(ban);
	Sprite sprite_vot1(vot1);
	Sprite sprite_vot2(vot2);
	Sprite sprite_bong(bong);
	Sprite sprite_bg(bg);
	Sprite sprite_text1(text1);
	Sprite sprite_text2(text2);

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
			/*if (event.type ==  Event::MouseMoved) {
			x = event.mouseMove.x;
			y = event.mouseMove.y;
			}
			std::cout << x << "  " << y << std::endl;*/

			//di chuyen vot 1:
			if(Keyboard::isKeyPressed(Keyboard::A)){
				if(_vot1.get_X() > 50){
					_vot1.set_Z(180.0f);
					_vot1.Dichuyen();
				}
			}

			if(Keyboard::isKeyPressed(Keyboard::D)){
				if(_vot1.get_X() < 400){
					_vot1.set_Z(0.0f);
					_vot1.Dichuyen();
				}
			}

			if(Keyboard::isKeyPressed(Keyboard::W)){
				if(_vot1.get_Y() > 120){
					_vot1.set_Z(-75.96375653f);
					_vot1.Dichuyen();
				}
			}

			if(Keyboard::isKeyPressed(Keyboard::S)){
				if(_vot1.get_Y() < 560){
					_vot1.set_Z(104.03624347f);
					_vot1.Dichuyen();
				}
			}

			// di chuyen vot 2
			if(Keyboard::isKeyPressed(Keyboard::Left)){
				if(_vot2.get_X() > 490){
					_vot2.set_Z(180.0f);
					_vot2.Dichuyen();
				}
			}

			if(Keyboard::isKeyPressed(Keyboard::Right)){
				if(_vot2.get_X() < 850){
					_vot2.set_Z(0.0f);
					_vot2.Dichuyen();
				}
			}

			if(Keyboard::isKeyPressed(Keyboard::Up)){
				if(_vot2.get_Y() > 120){
					_vot2.set_Z(-104.03624347f);
					_vot2.Dichuyen();
				}
			}

			if(Keyboard::isKeyPressed(Keyboard::Down)){
				if(_vot2.get_Y() < 560){
					_vot2.set_Z(75.96375653f);
					_vot2.Dichuyen();
				}
			}
		}

		window.clear( Color::White);

		window.draw(sprite_bg);

		sprite_text1.setPosition(50,20);
		window.draw(sprite_text1);

		sprite_text2.setPosition(650,20);
		window.draw(sprite_text2);

		sprite_ban.setPosition(0,85);
		window.draw(sprite_ban);

		sprite_vot1.setPosition(_vot1.get_X()-12,_vot1.get_Y()-33);
		window.draw(sprite_vot1);

		sprite_vot2.setPosition(_vot2.get_X()-12,_vot2.get_Y()-33);
		window.draw(sprite_vot2);

		sprite_bong.setPosition(_bong.get_X()-7.5,_bong.get_Y()-7.5);
		window.draw(sprite_bong);
		_bong.Chuyendong();


		Hainguoi();
		_bong.set_V(_bong.get_V() + 0.00001f);
		window.display();
	}
}

int Game::game_start(){
	RenderWindow window(VideoMode(500, 700), "start game");

	Texture bg,text,anh5,choiDon,choiDoi,online;

	if (!bg.loadFromFile("./img/bg3.png")) {
		return 0; // Thoát nếu không thể tải hình ảnh
	}
	if (!text.loadFromFile("./img/anh6.png")) {
		return 0; // Thoát nếu không thể tải hình ảnh
	}
	if (!anh5.loadFromFile("./img/anh5.png")) {
		return 0; // Thoát nếu không thể tải hình ảnh
	}
	if (!choiDon.loadFromFile("./img/1nguoi.png")) {
		return 0; // thoát nếu không thể tải hình ảnh
	}
	if (!choiDoi.loadFromFile("./img/2nguoi.png")) {
		return 0; // thoát nếu không thể tải hình ảnh
	}
	if (!online.loadFromFile("./img/online.png")) {
		return 0; // thoát nếu không thể tải hình ảnh
	}
	Sprite sprite_bg(bg);
	Sprite sprite_text(text);
	Sprite sprite_anh5(anh5);
	Sprite sprite_choiDon(choiDon);
	Sprite sprite_choiDoi(choiDoi);
	Sprite sprite_online(online);

	while (window.isOpen()) {
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
			if (event.type == Event::MouseButtonPressed) {
				if (event.mouseButton.button == Mouse::Left) {
					//std::cout << "Mouse Clicked at: " << event.mouseButton.x << ", " << event.mouseButton.y << std::endl;
					if(event.mouseButton.x > 155 && event.mouseButton.x < 345 && event.mouseButton.y > 405 && event.mouseButton.y < 477){
						window.close();
						return 1;
					}
					if(event.mouseButton.x > 155 && event.mouseButton.x < 345 && event.mouseButton.y > 505 && event.mouseButton.y < 577){
						window.close();
						return 2;
					}
				}
			}
		}

		window.clear();
		window.draw(sprite_bg);
		
				sprite_text.setPosition(50,10);
				window.draw(sprite_text);
		
				sprite_anh5.setPosition(50,130);
				window.draw(sprite_anh5);
		
				sprite_choiDon.setPosition(150,400);
				window.draw(sprite_choiDon);
		
				sprite_choiDoi.setPosition(150,500);
				window.draw(sprite_choiDoi);

				sprite_online.setPosition(150,600);
				window.draw(sprite_online);
		
		window.display();
	}
	return 0;
}