#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

using namespace sf;

const int arr_cnt = 4;

struct Card{
	RectangleShape sprite;
	int id;
};

int main()
{
	int CARD_W = 200;
	int CARD_H = 200;

	RenderWindow window(VideoMode(1200, 800), "Card Game!");
	window.setFramerateLimit(60);

	Vector2i mouse_pos;
	int click_cnt = 0;     //마우스 누른 횟수

	//폰트
	Font font;
	font.loadFromFile("c:/Windows/Fonts/Arial.ttf");

	//텍스트
	Text text;
	text.setFont(font);
	text.setCharacterSize(30);
	text.setFillColor(Color::White);
	text.setPosition(0, 0);
	char info[40];

	struct Card cards[arr_cnt][arr_cnt];
	for (int i = 0; i < arr_cnt; i++) 
	{
		for (int j = 0; j < arr_cnt; j++)
		{
			cards[i][j].sprite.setSize(Vector2f(CARD_W, CARD_H));
			cards[i][j].sprite.setPosition(j * CARD_W, i * CARD_H);
			cards[i][j].sprite.setFillColor(Color(i * 64, j * 64, 128));
		}
	}

	while (window.isOpen())
	{
		mouse_pos = Mouse::getPosition(window);

		Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case Event::Closed :
				window.close();
				break;
			//한 번 누르면 한 번만 적용
			case Event::MouseButtonPressed:
				if (event.mouseButton.button == Mouse::Left)
				{
					click_cnt++;
				}
			}
		}

		sprintf(info, "(%d, %d) / CLICKS : %d\n", mouse_pos.x, mouse_pos.y, click_cnt);
		text.setString(info);

		window.clear(Color::Black);
		for (int i = 0; i < arr_cnt; i++)
		{
			for (int j = 0; j < arr_cnt; j++)
			{
				window.draw(cards[i][j].sprite);
			}
		}

		window.draw(text);

		window.display();
	}

	return 0;
}
