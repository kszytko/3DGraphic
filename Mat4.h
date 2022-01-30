#include "Vec3.h"

class Mat4 {
public:


	Vec3 operator*(const Vec3& v) const {
		float x = cells[0][0] * v.x + cells[1][0] * v.y + cells[2][0] * v.z + cells[3][0];
		float y = cells[0][1] * v.x + cells[1][1] * v.y + cells[2][1] * v.z + cells[3][1];
		float z = cells[0][2] * v.x + cells[1][2] * v.y + cells[2][2] * v.z + cells[3][2];
		float w = cells[0][3] * v.x + cells[1][3] * v.y + cells[2][3] * v.z + cells[3][3];

		if (w != 0) {
			x /= w; y /= w; z /= w;
		}

		return { x,y,z };
	}

	Mat4 operator*(const Mat4& rhs) const {
		Mat4 out;

		for (size_t row = 0; row < 4; row++) {
			for (size_t col = 0; col < 4; col++) {
				out.cells[row][col] = 0;
				for (size_t i = 0; i < 4; i++)
				{
					out.cells[row][col] += this->cells[row][i] * rhs.cells[i][col];
				}
			}
		}
		return out;
	}

	Mat4& operator*=(const Mat4& rhs) {
		return *this = *this * rhs;
	}

	static Mat4 RotationX(float theta) {
		float cosT = cosf(theta);
		float sinT = sinf(theta);

		return{
				1.0f,	0.0f,	0.0f,	0.0f,
				0.0f,	cosT,	sinT,	0.0f,
				0.0f,	-sinT,	cosT,	0.0f,
				0.0f,	0.0f,	0.0f,	1.0f,
		};
	}
	static Mat4 RotationY(float theta) {
		float cosT = cosf(theta);
		float sinT = sinf(theta);

		return{
				cosT,	0.0f,	-sinT,	0.0f,
				0.0f,	1.0f,	0.0f,	0.0f,
				sinT,	0.0f,	cosT,	0.0f,
				0.0f,	0.0f,	0.0f,	1.0f,
		};
	}

	static Mat4 RotationZ(float theta) {
		float cosT = cosf(theta);
		float sinT = sinf(theta);

		return{
				cosT,	sinT,	0.0f,	0.0f,
				-sinT,	cosT,	0.0f,	0.0f,
				0.0f,	0.0f,	1.0f,	0.0f,
				0.0f,	0.0f,	0.0f,	1.0f,
		};
	}

	static Mat4 Translation(const Vec3& v) {
		return Translation(v.x, v.y, v.z);
	}

	static Mat4 Translation(float x, float y, float z) {
		return{
				1.0f,	0.0f,	0.0f,	0.0f,
				0.0f,	1.0f,	0.0f,	0.0f,
				0.0f,	0.0f,	1.0f,	0.0f,
				x,		y,		z,		1.0f
		};
	}

public:
	float cells[4][4];

};