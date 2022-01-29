#pragma once
#include "vector.h"


float Vec3::dot_product(const Vec3& rhs) const {
	return rhs.x * this->x + rhs.y * this->y + rhs.z * this->z;
}

Vec3 Vec3::cross_product(const Vec3& rhs) const{
	return {
		this->y * rhs.z - this->z * rhs.y,
		this->z * rhs.x - this->x * rhs.z,
		this->x * rhs.y - this->y * rhs.x
	};
}

Vec3 Vec3::multiplyByMatrix(const Matrix4& rhs) const {
	float x = rhs.m[0][0] * this->x + rhs.m[1][0] * this->y + rhs.m[2][0] * this->z + rhs.m[3][0];
	float y = rhs.m[0][1] * this->x + rhs.m[1][1] * this->y + rhs.m[2][1] * this->z + rhs.m[3][1];
	float z = rhs.m[0][2] * this->x + rhs.m[1][2] * this->y + rhs.m[2][2] * this->z + rhs.m[3][2];
	float w = rhs.m[0][3] * this->x + rhs.m[1][3] * this->y + rhs.m[2][3] * this->z + rhs.m[3][3];

	if (w != 0) {
		x /= w; y /= w; z /= w;
	}
	
	return { x,y,z };
}

Triangle Triangle::multiplyByMatrix(const Matrix4& rhs) const {
	return {
		this->p[0].multiplyByMatrix(rhs),
		this->p[1].multiplyByMatrix(rhs),
		this->p[2].multiplyByMatrix(rhs),
		cross
	};
};

void Triangle::calculateCrossProduct() {
	Vec3 v, w;
	v = p[2] - p[0];
	w = p[1] - p[0];
	cross = v.cross_product(w);
}

float Triangle::calculateDotProduct(const Vec3& v) {
	dot = cross.dot_product(v);
	return dot;
}

const Vec3 Vec3::m_UnitX(1.0f, 0.0f, 0.0f);
const Vec3 Vec3::m_UnitY(0.0f, 1.0f, 0.0f);
const Vec3 Vec3::m_UnitZ(0.0f, 0.0f, 1.0f);
const Vec3 Vec3::m_Zero (0.0f, 0.0f, 0.0f);

const Vec3 Vec3::m_North( 0.0f,  0.0f, -1.0f);
const Vec3 Vec3::m_South( 0.0f,  0.0f,  1.0f);
const Vec3 Vec3::m_West (-1.0f,  0.0f,  0.0f);
const Vec3 Vec3::m_East ( 1.0f,  0.0f,  0.0f);
const Vec3 Vec3::m_Up   ( 0.0f,  1.0f,  0.0f);
const Vec3 Vec3::m_Down ( 0.0f, -1.0f,  0.0f);