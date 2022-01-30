#pragma once
#include "Vec3.h"


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
		cross = _cross;
	}

	Triangle multiplyByMatrix(const Matrix4& rhs) const {
		return {
			this->p[0].multiplyByMatrix(rhs),
			this->p[1].multiplyByMatrix(rhs),
			this->p[2].multiplyByMatrix(rhs),
			cross
		};
	};

	void calculateCrossProduct() {
		Vec3 v, w;
		v = p[2] - p[0];
		w = p[1] - p[0];
		cross = v.cross_product(w);
	}

	float calculateDotProduct(const Vec3& v) {
		dot = cross.dot_product(v);
		return dot;
	}
};


