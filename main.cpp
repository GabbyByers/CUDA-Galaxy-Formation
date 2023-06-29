#include <iostream>
#include "kernel.cuh"

#include "SFML/Graphics.hpp"
#include "Game.h"

class Simulation {
public:
	Game* game = nullptr;

	Particle* device_particles = nullptr;
	int* device_particle_positions = nullptr;
	int* device_pixel_particle_counts = nullptr;
	unsigned char* device_image_pixels = nullptr;

	int* host_particle_positions = nullptr;
	int* host_pixel_particle_counts = nullptr;
	unsigned char* host_image_pixels = nullptr;

	Simulation(Game* game, int num_particles) {
		this->game = game;
		device_particles = allocateDeviceParticles(num_particles);
		device_particle_positions = allocateDeviceParticlePositions(num_particles);
		device_pixel_particle_counts = allocateDevicePixelParticleCounts(game->numPixels());
		device_image_pixels = allocateDeviceImagePixels(game->numPixels());
	}
};

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