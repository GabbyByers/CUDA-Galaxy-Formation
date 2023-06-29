#include <iostream>
#include "kernel.cuh"
#include "SFML/Graphics.hpp"
#include "Game.h"

#include "Simulation.h"

int main() {
	Game game(500, 500);
	Simulation simulation(&game, 10000);

	while (game.open()) {
		game.eventHandler();
		game.window->clear(sf::Color(0, 0, 0));
		game.window->display();
	}

	return 0;
}