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

	float dot_product(const Vec3&) const;
	Vec3 cross_product(const Vec3&) const;
	Vec3 multiplyByMatrix(const Matrix4&) const;

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

struct Triangle {
	Vec3 p[3];
	Vec3 cross;
	float dot;

	Triangle() {}
	Triangle(const Vec3 _p0, const Vec3 _p1, const Vec3 _p2) {
		p[0] = _p0;
		p[1] = _p1;
		p[2] = _p2;
	};

	Triangle(const Vec3 _p0, const Vec3 _p1, const Vec3 _p2, const Vec3 _cross) : 
		Triangle(_p0, _p1, _p2) {
		cross=_cross;
	}

	Triangle multiplyByMatrix(const Matrix4&) const;
	void calculateCrossProduct();
	float calculateDotProduct(const Vec3&);
};

