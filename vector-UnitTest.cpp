
#include "vector.h"
#include "gtest/gtest.h"


class Test : public testing::Test {
public:
	float x, y, z;

	void SetUp() override {
	
	}
};

//EXPECT_EQ(str, double_expected)

TEST_F(Test, InitialVector2)
{
	x = 1.0f; y = 2.0f; z = 3.0f;
	Vec3 vec{ x,y,z };

	EXPECT_EQ(x, vec.x);
	EXPECT_EQ(y, vec.y);
	EXPECT_EQ(z, vec.z);
}

TEST_F(Test, dot_productProduct_FromNull_IsNull2) {
	Vec3 vec1;
	Vec3 vec2;
	float dot = vec1.dot_product(vec2);
	EXPECT_EQ(dot, 0.0f);
}

		
TEST_F(Test, dot_productProduct_IsValid_2D) {
	Vec3 vec1{ 1.0f, 0.0f, 0.0f };
	Vec3 vec2{ 1.0f, 1.0f, 0.0f };
	EXPECT_EQ(vec1.dot_product(vec2), 1.0f);
}

TEST_F(Test, dot_productProduct_IsValid_3D) {
	Vec3 vec1{ 1.0f, 0.0f, 0.0f };
	Vec3 vec2{ 1.0f, 1.0f, 1.0f };
	EXPECT_EQ(vec1.dot_product(vec2), 1.0f);
}

TEST_F(Test, dot_productProduct_IsValid_Minus_2D) {
	Vec3 vec1{ 1.0f, 0.0f, 0.0f };
	Vec3 vec2{ -1.0f, 1.0f, 0.0f };
	EXPECT_EQ(vec1.dot_product(vec2), -1.0f);
}

TEST_F(Test, dot_productProduct_IsValid_Minus_3D) {
	Vec3 vec1{ 1.0f, 0.0f, 0.0f };
	Vec3 vec2{ -1.0f, -1.0f, -1.0f };
	EXPECT_EQ(vec1.dot_product(vec2), -1.0f);
}


//cross_product PRODUCT
TEST_F(Test, cross_productProduct_SimplePlus) {
	Vec3 vec1{ 1.0f, 0.0f, 0.0f };
	Vec3 vec2{ 0.0f, 1.0f, 0.0f };

	Vec3 vec3 = vec1.cross_product(vec2);

	EXPECT_EQ(vec3.x, 0.0f);
	EXPECT_EQ(vec3.y, 0.0f);
	EXPECT_EQ(vec3.z, 1.0f);
}

TEST_F(Test, cross_productProduct_SimpleMinus) {
	Vec3 vec1{ 1.0f, 0.0f, 0.0f };
	Vec3 vec2{ 0.0f, 1.0f, 0.0f };

	Vec3 vec3 = vec2.cross_product(vec1);

	EXPECT_EQ(vec3.x, 0.0f);
	EXPECT_EQ(vec3.y, 0.0f);
	EXPECT_EQ(vec3.z, -1.0f);
}

TEST_F(Test, cross_productProduct_45_zMinus) {
	Vec3 vec1{ 1.0f, 0.0f, 0.0f };
	Vec3 vec2{ 1.0f, 1.0f, 0.0f };

	Vec3 vec3 = vec1.cross_product(vec2);

	EXPECT_EQ(vec3.x, 0.0f);
	EXPECT_EQ(vec3.y, 0.0f);
	EXPECT_EQ(vec3.z, 1.0f);
}

TEST_F(Test, cross_productProduct_SimpleMinus2) {
	Vec3 vec1{ 1.0f, 0.0f, 1.0f };
	Vec3 vec2{ 1.0f, 1.0f, 1.0f };

	Vec3 vec3 = vec2.cross_product(vec1);

	EXPECT_EQ(vec3.x, 1.0f);
	EXPECT_EQ(vec3.y, 0.0f);
	EXPECT_EQ(vec3.z, -1.0f);
}


