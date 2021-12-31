#pragma once

#include <vector>
#include "Surface.hpp"
#include "vmath.hpp"

using namespace std;

#ifndef PLATFORM_H
#define PLATFORM_H

class Platform
{
public:
	Vec3f pos = { 0, 0, 0 };
	Vec3f normal = { 0, 1, 0 };
	Mat4 transform = { {} };
	bool oTiltingPyramidMarioOnPlatform = false;
	Vec2S triangles = { Surface(true), Surface(false) };

	Platform() { };

	Platform(int16_t x, int16_t y, int16_t z, Vec3f startNormal) {
		pos[0] = x;
		pos[1] = y;
		pos[2] = z;
		normal = startNormal;

		create_transform_from_normals();

		triangles[0].rotate(transform);
		triangles[1].rotate(transform);
	}

	void create_transform_from_normals();
	void platform_logic(Vec3f& marioPos);
};

float approach_by_increment(float goal, float src, float inc);

#endif