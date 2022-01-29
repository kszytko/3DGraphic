#include "pch.h"
#include "CppUnitTest.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace vectorUnitTest
{
	TEST_CLASS(vectorUnitTest)
	{
	public:
		float x, y, z;
		
		TEST_METHOD(InitialVector)
		{
			x = 1.0f; y = 2.0f; z = 3.0f;
			Vec3 vec{ x,y,z };

			Assert::AreEqual(x, vec.x);
			Assert::AreEqual(y, vec.y);
			Assert::AreEqual(z, vec.z);
		}

		TEST_METHOD(dot_productProduct_FromNull_IsNull) {
			Vec3 vec1;
			Vec3 vec2;
			float dot = vec1.dot_product(vec2);
			Assert::AreEqual(dot, 0.0f);
		}
		
		//TEST_METHOD(dot_productProduct_IsValid_2D) {
		//	Vec3 vec1{ 1.0f, 0.0f, 0.0f };
		//	Vec3 vec2{ 1.0f, 1.0f, 0.0f };
		//	Assert::AreEqual(vec1.dot_product(vec2), 1.0f);
		//}
		//
		//TEST_METHOD(dot_productProduct_IsValid_3D) {
		//	Vec3 vec1{ 1.0f, 0.0f, 0.0f };
		//	Vec3 vec2{ 1.0f, 1.0f, 1.0f };
		//	Assert::AreEqual(vec1.dot_product(vec2), 1.0f);
		//}
		//
		//TEST_METHOD(dot_productProduct_IsValid_Minus_2D) {
		//	Vec3 vec1{ 1.0f, 0.0f, 0.0f };
		//	Vec3 vec2{ -1.0f, 1.0f, 0.0f };
		//	Assert::AreEqual(vec1.dot_product(vec2), -1.0f);
		//}
		//
		//TEST_METHOD(dot_productProduct_IsValid_Minus_3D) {
		//	Vec3 vec1{ 1.0f, 0.0f, 0.0f };
		//	Vec3 vec2{ -1.0f, -1.0f, -1.0f };
		//	Assert::AreEqual(vec1.dot_product(vec2), -1.0f);
		//}
		
		
		//cross_product PRODUCT
		//TEST_METHOD(cross_productProduct_SimplePlus) {
		//	Vec3 vec1{ 1.0f, 0.0f, 0.0f };
		//	Vec3 vec2{ 0.0f, 1.0f, 0.0f };
		//
		//	Vec3 vec3 = vec1.cross_product(vec2);
		//
		//	Assert::AreEqual(vec3.x, 0.0f);
		//	Assert::AreEqual(vec3.y, 0.0f);
		//	Assert::AreEqual(vec3.z, 1.0f);
		//}
		//
		//TEST_METHOD(cross_productProduct_SimpleMinus) {
		//	Vec3 vec1{ 1.0f, 0.0f, 0.0f };
		//	Vec3 vec2{ 0.0f, 1.0f, 0.0f };
		//
		//	Vec3 vec3 = vec2.cross_product(vec1);
		//
		//	Assert::AreEqual(vec3.x, 0.0f);
		//	Assert::AreEqual(vec3.y, 0.0f);
		//	Assert::AreEqual(vec3.z, -1.0f);
		//}
		//
		//TEST_METHOD(cross_productProduct_45_zMinus) {
		//	Vec3 vec1{ 1.0f, 0.0f, 0.0f };
		//	Vec3 vec2{ 1.0f, 1.0f, 0.0f };
		//
		//	Vec3 vec3 = vec1.cross_product(vec2);
		//
		//	Assert::AreEqual(vec3.x, 0.0f);
		//	Assert::AreEqual(vec3.y, 0.0f);
		//	Assert::AreEqual(vec3.z, 1.0f);
		//}
		//
		//TEST_METHOD(cross_productProduct_SimpleMinus2) {
		//	Vec3 vec1{ 1.0f, 0.0f, 1.0f };
		//	Vec3 vec2{ 1.0f, 1.0f, 1.0f };
		//
		//	Vec3 vec3 = vec2.cross_product(vec1);
		//
		//	Assert::AreEqual(vec3.x, 1.0f);
		//	Assert::AreEqual(vec3.y, 0.0f);
		//	Assert::AreEqual(vec3.z, 0.0f);
		//}
	};
}
