#include <SFML/Graphics.hpp>
#include <string>
#include "Menu.h"

using namespace sf;

void main() 
{
	RenderWindow MENU(VideoMode(1000, 800), "Main Menu", Style::Default);
	Menu mainMenu(MENU.getSize().x, MENU.getSize().y);

	//set background
	RectangleShape background;
	background.setSize(Vector2f(1000, 800));
	Texture Maintexture;
	Maintexture.loadFromFile("chess wallpaper.jpg");
	background.setTexture(&Maintexture);

	while (MENU.isOpen()) {

		Event event;
		while (MENU.pollEvent(event)) {
			if (event.type == Event::Closed) {
				
				MENU.close();
			}

			if (event.type == Event::KeyReleased) {
				
				if (event.key.code == Keyboard::Up) {
					
					mainMenu.MoveUp();
					break;
				}

				if (event.key.code == Keyboard::Down) {
					
					mainMenu.MoveDown();
					break;
				}

				if (event.key.code == Keyboard::Return) {

					RenderWindow PLAY(VideoMode(960, 720), "Name");
					RenderWindow Settings(VideoMode(960, 720), "Settings");
					RenderWindow About(VideoMode(960, 720), "About");

					int x = mainMenu.MenuPressed();
					if (x == 0) {
						
						while (PLAY.isOpen())
						{
							
							Event aevent;

								while (PLAY.pollEvent(aevent)) {
									if (aevent.type == Event::Closed) 
									{
										PLAY.close();
									}

									if (aevent.type == Event::KeyPressed) 
									{
										if (aevent.key.code == Keyboard::Escape) 
										{
											PLAY.close();
										}
									}
								}
								Settings.close();
								About.close();
								PLAY.clear();
								PLAY.display();
						}
					}
					if (x == 1) {

						while (Settings.isOpen())
						{

							Event aevent;
							while (Settings.pollEvent(aevent)) {
								if (aevent.type == Event::Closed)
								{
									Settings.close();
								}
								if (aevent.type == Event::KeyPressed) {

									if (aevent.key.code == Keyboard::Escape)
									{
										Settings.close();
									}
								}
							}
							PLAY.close();
							Settings.clear();
							About.close();
							Settings.display();
						}
					}
					if (x == 2) {

						while (About.isOpen())
						{

							Event aevent;
							while (About.pollEvent(aevent)) {
								if (aevent.type == Event::Closed)
								{
									About.close();
								}
								if (aevent.type == Event::KeyPressed) {

									if (aevent.key.code == Keyboard::Escape)
									{
										About.close();
									}
								}
							}
							PLAY.close();
							About.clear();
							Settings.close();
							About.display();
						}
					}
					if (x == 3) 
						MENU.close();
					break;
					
				}
				
			}
		}
		MENU.clear();
		MENU.draw(background);
		mainMenu.draw(MENU);
		MENU.display();
	}//end of window function

}//end main functions