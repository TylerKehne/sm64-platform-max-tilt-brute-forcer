#pragma once

#include <vector>
#include <cstdio>
#include <cstdint>

#include "vmath.hpp"

using namespace std;

#ifndef SURFACE_H
#define SURFACE_H

class Surface
{
public:
	VecVec3s vectors;
	Vec3f normal;
	float originOffset;
	int plat_idx;
	bool top;

	Surface(bool top) {
		this->top = top;

		reset_vectors();

		normal[0] = 0.0f;
		normal[1] = 1.0f;
		normal[2] = 0.0f;

		originOffset = -vectors[0][1];
	}

	void reset_vectors() {
		vectors[0][0] = 307;
		vectors[0][1] = 307;
		vectors[0][2] = -306;

		if (top) {
			vectors[1][0] = -306;
			vectors[1][1] = 307;
			vectors[1][2] = -306;
			vectors[2][0] = -306;
			vectors[2][1] = 307;
			vectors[2][2] = 307;
		}
		else {
			vectors[1][0] = -306;
			vectors[1][1] = 307;
			vectors[1][2] = 307;
			vectors[2][0] = 307;
			vectors[2][1] = 307;
			vectors[2][2] = 307;
		}
	}

	void rotate(const Mat4& m);
	void repr();
};

typedef std::array<Surface, 2> Vec2S;

Surface const* find_floor(Vec3f& pos, Vec2S& triangles, float* height);

#endif