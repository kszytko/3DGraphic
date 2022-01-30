#pragma once

#include "Mesh.h"

class Cube : public Mesh {
	Cube (float size = 1.0f)
	{
		const float side = size / 2.0f;

		vertices = {
			-side, -side, -side, // 0
			 side, -side, -side, // 1
			-side,  side, -side, // 2
			 side,  side, -side, // 3
			-side, -side,  side, // 4
			 side, -side,  side, // 5
			-side,  side,  side, // 6
			 side,  side,  side  // 7
		};

		indicates = {
				0,2,1, 2,3,1,
				1,3,5, 3,7,5,
				2,6,3, 3,6,7,
				4,5,7, 4,7,6,
				0,4,2, 2,4,6,
				0,1,4, 1,5,4
		};
	}
};