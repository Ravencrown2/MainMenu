#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#define MAX_NUMBER_OF_ITEMS 4


class Menu
{
public:
	Menu(float width, float height);
	
	void draw(RenderWindow& window);
	void MoveUp();
	void MoveDown();
	
	int MenuPressed() {
		return MenuSelected;
	}

	~Menu();

private:
	int MenuSelected;
	Music music;
	Font font;
	Text Mainmenu[MAX_NUMBER_OF_ITEMS];
};