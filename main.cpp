#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"

#include "Vec3.h"
#include "Mat4.h"
#include "Triangle.h"
#include "Cube.h"


class olcEngine3D : public olc::PixelGameEngine
{
public:
	olcEngine3D()
	{
		// Name your application
		sAppName = "olcEngine3D";
	}

private:
	Cube cube;
	Mat4 matProj, matRot, matTran, matRotTran;


	float fTheta_X = 0.0f;
	float fTheta_Y = 0.0f;
	float fTheta_Z = 0.0f;


	float fPos_X = 0.0f;
	float fPos_Y = 0.0f;
	float fPos_Z = 0.0f;

	int count = 0;



public:
	bool OnUserCreate() override
	{

		matProj = {
				(float)ScreenHeight() / 2,	0.0f,						0.0f,	0.0f,
				0.0f,						(float)ScreenHeight() / 2,	0.0f,	0.0f,
				0.0f,						0.0f,						1.0f,	0.0f,
				(float)ScreenWidth() / 2,	(float)ScreenHeight() / 2,	0.0f,	1.0f,
		};


	
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		Clear(olc::BLACK);


		// Standard FPS Control scheme, but turn instead of strafe
		if (GetKey(olc::Q).bHeld)
			fTheta_X -= 2.0f * fElapsedTime;
		if (GetKey(olc::W).bHeld)
			fTheta_X += 2.0f * fElapsedTime;
		if (GetKey(olc::A).bHeld)
			fTheta_Y -= 2.0f * fElapsedTime;
		if (GetKey(olc::S).bHeld)
			fTheta_Y += 2.0f * fElapsedTime;
		if (GetKey(olc::Z).bHeld)
			fTheta_Z -= 2.0f * fElapsedTime;
		if (GetKey(olc::X).bHeld)
			fTheta_Z += 2.0f * fElapsedTime;

		if (GetKey(olc::UP).bHeld)
			fPos_Y += 2.0f * fElapsedTime;
		if (GetKey(olc::DOWN).bHeld)
			fPos_Y -= 2.0f * fElapsedTime;
		if (GetKey(olc::LEFT).bHeld)
			fPos_X -= 2.0f * fElapsedTime;
		if (GetKey(olc::RIGHT).bHeld)
			fPos_X += 2.0f * fElapsedTime;



		matRot = Mat4::RotationX(fTheta_X) * Mat4::RotationY(fTheta_Y) * Mat4::RotationZ(fTheta_Z);
		matTran = Mat4::Translation(fPos_X, fPos_Y, fPos_Z);
		matRotTran = matRot * matTran;

		Draw(cube);


		return true;
	}

	void Draw(const Mesh& triList)
	{
		ProcessVertices(triList.vertices, triList.indices);
	}

	void ProcessVertices(const std::vector<Vec3>& vertices, const std::vector<size_t>& indices) {
		std::vector<Vec3> verticesOut (vertices.size());

		std::transform(vertices.begin(), vertices.end(), verticesOut.begin(), [this](auto& v) {
			return matRot * matTran * v;
			});


		AssembleTriangles(verticesOut, indices);
	}

	void AssembleTriangles(const std::vector<Vec3>& vertices, const std::vector<size_t>& indices) {

		for (size_t i = 0; i < indices.size() / 3; i++) {
			const auto& v0 = vertices[indices[i * 3]];
			const auto& v1 = vertices[indices[i * 3 + 1]];
			const auto& v2 = vertices[indices[i * 3 + 2]];

			CheckAndProcessTriangle(v0, v1, v2);
		}
	}

	void CheckAndProcessTriangle(const Vec3& v0, const Vec3& v1, const Vec3& v2){
		const auto eyepos = Vec3::m_North;

		//if( (v1 - v0).dot_product(v2- v0) )

		Triangle tris(v0, v1, v2);

		tris.p0 = matProj * tris.p0;
		tris.p1 = matProj * tris.p1;
		tris.p2 = matProj * tris.p2;

		DrawTriangleToScreen(tris);
	}

	void DrawTriangleToScreen(const Triangle& tris) {
		DrawTriangle(tris.p0.x, tris.p0.y, tris.p1.x, tris.p1.y, tris.p2.x, tris.p2.y, olc::WHITE);


	}
};

int main()
{
	olcEngine3D demo;
	if (demo.Construct(400, 200, 2, 2))
		demo.Start();
	return 0;
}
