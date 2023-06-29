#pragma once
#include "Vec3f.h"
#include "Particle.cuh"
#include "cuda_runtime.h"
#include "device_launch_parameters.h"

void deviceSimulation(Particle* device_particles, int num_particles);
void deviceRenderer(int* device_pixel_particle_counts, unsigned char* device_image_pixels, int num_pixels);

Particle* allocateDeviceParticles(int num_particles);
int* allocateDeviceParticlePositions(int num_particles);
int* allocateDevicePixelParticleCounts(int num_pixels);
unsigned char* allocateDeviceImagePixels(int num_pixels);

void freeDeviceParticles(Particle* device_particles);
void freeDeviceParticlePositions(int* device_particle_positions);
void freeDevicePixelParticleCounts(int* device_pixel_particle_counts);
void freeDeviceImagePixels(unsigned char* device_image_pixels);