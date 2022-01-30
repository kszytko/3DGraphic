#pragma once


struct Matrix4 {
	float m[4][4];

	Matrix4() {
		m[0][0] = 0; m[0][1] = 0; m[0][2] = 0; m[0][3] = 0;
		m[1][0] = 0; m[1][1] = 0; m[1][2] = 0; m[1][3] = 0;
		m[2][0] = 0; m[2][1] = 0; m[2][2] = 0; m[2][3] = 0;
		m[3][0] = 0; m[3][1] = 0; m[3][2] = 0; m[3][3] = 0;
	}

};

struct Vec3 {
	float x = 0;
	float y = 0;
	float z = 0;

	Vec3(float _x, float _y, float _z) : x(_x), y(_y), z(_z) {}
	Vec3() {}

	Vec3& operator=(const Vec3& rhs) = default;

	Vec3 operator-(const Vec3& rhs) const {
		return { this->x - rhs.x, this->y - rhs.y, this->z - rhs.z };
	}
	Vec3& operator -= (const Vec3& rhs) {
		this->x -= rhs.x;
		this->y -= rhs.y;
		this->z -= rhs.z;
		return *this;
	}

	float dot_product(const Vec3& rhs) const {
		return rhs.x * this->x + rhs.y * this->y + rhs.z * this->z;
	}

	Vec3 cross_product(const Vec3& rhs) const {
		return {
			this->y * rhs.z - this->z * rhs.y,
			this->z * rhs.x - this->x * rhs.z,
			this->x * rhs.y - this->y * rhs.x
		};
	}

	Vec3 multiplyByMatrix(const Matrix4& rhs) const {
		float x = rhs.m[0][0] * this->x + rhs.m[1][0] * this->y + rhs.m[2][0] * this->z + rhs.m[3][0];
		float y = rhs.m[0][1] * this->x + rhs.m[1][1] * this->y + rhs.m[2][1] * this->z + rhs.m[3][1];
		float z = rhs.m[0][2] * this->x + rhs.m[1][2] * this->y + rhs.m[2][2] * this->z + rhs.m[3][2];
		float w = rhs.m[0][3] * this->x + rhs.m[1][3] * this->y + rhs.m[2][3] * this->z + rhs.m[3][3];

		if (w != 0) {
			x /= w; y /= w; z /= w;
		}

		return { x,y,z };
	}


	static const Vec3 m_UnitX;
	static const Vec3 m_UnitY;
	static const Vec3 m_UnitZ;
	static const Vec3 m_Zero;

	static const Vec3 m_North;
	static const Vec3 m_South;
	static const Vec3 m_West;
	static const Vec3 m_East;
	static const Vec3 m_Up;
	static const Vec3 m_Down;

};






const Vec3 Vec3::m_UnitX(1.0f, 0.0f, 0.0f);
const Vec3 Vec3::m_UnitY(0.0f, 1.0f, 0.0f);
const Vec3 Vec3::m_UnitZ(0.0f, 0.0f, 1.0f);
const Vec3 Vec3::m_Zero(0.0f, 0.0f, 0.0f);

const Vec3 Vec3::m_North(0.0f, 0.0f, -1.0f);
const Vec3 Vec3::m_South(0.0f, 0.0f, 1.0f);
const Vec3 Vec3::m_West(-1.0f, 0.0f, 0.0f);
const Vec3 Vec3::m_East(1.0f, 0.0f, 0.0f);
const Vec3 Vec3::m_Up(0.0f, 1.0f, 0.0f);
const Vec3 Vec3::m_Down(0.0f, -1.0f, 0.0f);