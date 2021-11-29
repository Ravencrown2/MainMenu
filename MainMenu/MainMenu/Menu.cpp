#include "Menu.h"
#include <string>

Menu::Menu(float width, float height) {
	
	if (!font.loadFromFile("Queensila.ttf")) {
		//error check
	}

	music.openFromFile("Evening in the Tavern.ogg");  //music Loop
	music.setVolume(20);
	music.play();
	music.setLoop(true);

	//play
	Mainmenu[0].setFont(font);
	Mainmenu[0].setString("Play");
	Mainmenu[0].setFillColor(Color::White);
	Mainmenu[0].setPosition(400, 200);
	Mainmenu[0].setCharacterSize(70);
	Mainmenu[0].setStyle(Text::Regular);

	
	//Settings
	Mainmenu[1].setFont(font);
	Mainmenu[1].setString("Settings");
	Mainmenu[1].setFillColor(Color::White);
	Mainmenu[1].setPosition(400, 300);
	Mainmenu[1].setCharacterSize(70);
	Mainmenu[1].setStyle(Text::Regular);

	//About
	Mainmenu[2].setFont(font);
	Mainmenu[2].setString("About");
	Mainmenu[2].setFillColor(Color::White);
	Mainmenu[2].setPosition(400, 400);
	Mainmenu[2].setCharacterSize(70);
	Mainmenu[2].setStyle(Text::Regular);

	//Exit
	Mainmenu[3].setFont(font);
	Mainmenu[3].setString("Exit");
	Mainmenu[3].setFillColor(Color::White);
	Mainmenu[3].setPosition(400, 500);
	Mainmenu[3].setCharacterSize(70);
	Mainmenu[3].setStyle(Text::Regular);


	MenuSelected = -1;
}

Menu::~Menu() {
}

//Draw Menu
void Menu::draw(RenderWindow& window) {
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; ++i) {
		window.draw(Mainmenu[i]);
	}
}


//move up 
void Menu::MoveUp() {

	if (MenuSelected - 1 >= 0) {
		Mainmenu[MenuSelected].setFillColor(Color::White);

		MenuSelected--;

		if (MenuSelected == -1) {
			MenuSelected = 2;
		}
		Mainmenu[MenuSelected].setFillColor(Color::Red);
	}

}

//move down 
void Menu::MoveDown() {

	if (MenuSelected + 1 <= MAX_NUMBER_OF_ITEMS) {
		Mainmenu[MenuSelected].setFillColor(sf::Color::White);

		MenuSelected++;

		if (MenuSelected == 4) {
			MenuSelected = 0;
		}
		Mainmenu[MenuSelected].setFillColor(Color::Red);
	}

}