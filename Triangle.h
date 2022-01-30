#pragma once
#include "Vec3.h"
#include "Mat4.h"


struct Triangle {
	Vec3 p0;
	Vec3 p1;
	Vec3 p2;


	Triangle() {}
	Triangle(const Vec3 _p0, const Vec3 _p1, const Vec3 _p2) {
		p0 = _p0;
		p1 = _p1;
		p2 = _p2;
	};

	//Triangle(const Vec3 _p0, const Vec3 _p1, const Vec3 _p2, const Vec3 _cross) :
	//	Triangle(_p0, _p1, _p2) {
	//	cross = _cross;
	//}
	//
	//Triangle multiplyByMatrix(const Mat4& m) const {
	//	return {
	//		m * p[0], m* p[1], m* p[2],
	//		cross
	//	};
	//};
	//
	//void calculateCrossProduct() {
	//	Vec3 v, w;
	//	v = p[2] - p[0];
	//	w = p[1] - p[0];
	//	cross = v.cross_product(w);
	//}
	//
	//float calculateDotProduct(const Vec3& v) {
	//	dot = cross.dot_product(v);
	//	return dot;
	//}
};


