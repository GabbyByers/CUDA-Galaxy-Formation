#pragma once

class Simulation {
public:
	Game* game = nullptr;
	int num_pixels;
	int num_particles;

	Particle* device_particles = nullptr;
	int* device_particle_positions = nullptr;
	int* device_pixel_particle_counts = nullptr;
	unsigned char* device_image_pixels = nullptr;

	int* host_particle_positions = nullptr;
	int* host_pixel_particle_counts = nullptr;
	unsigned char* host_image_pixels = nullptr;

	Simulation(Game* game, int num_particles) {
		this->game = game;
		this->num_particles = num_particles;
		num_pixels = game->numPixels();

		device_particles = allocateDeviceParticles(num_particles);
		device_particle_positions = allocateDeviceParticlePositions(num_particles);
		device_pixel_particle_counts = allocateDevicePixelParticleCounts(game->numPixels());
		device_image_pixels = allocateDeviceImagePixels(game->numPixels());
	}

	~Simulation() {
		freeDeviceParticles(device_particles);
		freeDeviceParticlePositions(device_particle_positions);
		freeDevicePixelParticleCounts(device_pixel_particle_counts);
		freeDeviceImagePixels(device_image_pixels);
	}
};