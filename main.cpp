#define OLC_PGE_APPLICATION
#include "olcPixelGameEngine.h"
#include "vector.h"




struct mesh {
	std::vector<Triangle> tris;
};



class olcEngine3D : public olc::PixelGameEngine
{
public:
	olcEngine3D()
	{
		// Name your application
		sAppName = "olcEngine3D";
	}

private:
	mesh meshCube;
	Matrix4 matProj, matResize, matRotZ, matRotX;
	std::vector<Triangle> triangles;


	float fTheta = 0.0f;
	int count = 0;



public:
	bool OnUserCreate() override
	{
		meshCube.tris = {
			// SOUTH
			{ {0.0f, 0.0f, 0.0f},    {0.0f, 1.0f, 0.0f},    {1.0f, 1.0f, 0.0f} },
			{ {0.0f, 0.0f, 0.0f},    {1.0f, 1.0f, 0.0f},    {1.0f, 0.0f, 0.0f} },
	
			//{ EAST       
			{ {1.0f, 0.0f, 0.0f},    {1.0f, 1.0f, 0.0f},    {1.0f, 1.0f, 1.0f} },
			{ {1.0f, 0.0f, 0.0f},    {1.0f, 1.0f, 1.0f},    {1.0f, 0.0f, 1.0f} },
			  
			//{ NORTH         
			{ {1.0f, 0.0f, 1.0f},    {1.0f, 1.0f, 1.0f},    {0.0f, 1.0f, 1.0f} },
			{ {1.0f, 0.0f, 1.0f},    {0.0f, 1.0f, 1.0f},    {0.0f, 0.0f, 1.0f} },
		
			//{ WEST      
			{ {0.0f, 0.0f, 1.0f},    {0.0f, 1.0f, 1.0f},    {0.0f, 1.0f, 0.0f} },
			{ {0.0f, 0.0f, 1.0f},    {0.0f, 1.0f, 0.0f},    {0.0f, 0.0f, 0.0f} },
			  
			//{ TOP     
			{ {0.0f, 1.0f, 0.0f},    {0.0f, 1.0f, 1.0f},    {1.0f, 1.0f, 1.0f} },
			{ {0.0f, 1.0f, 0.0f},    {1.0f, 1.0f, 1.0f},    {1.0f, 1.0f, 0.0f} },
			
			//{ BOTTOM        
			{ {1.0f, 0.0f, 1.0f},    {0.0f, 0.0f, 1.0f},    {0.0f, 0.0f, 0.0f} },
			{ {1.0f, 0.0f, 1.0f},    {0.0f, 0.0f, 0.0f},    {1.0f, 0.0f, 0.0f} },

		};


		matProj.m[0][0] = 0.5f * (float)ScreenHeight();
		matProj.m[1][0] = 0;
		matProj.m[2][0] = 0;
		matProj.m[3][0] = 0.5f * (float)ScreenWidth();

		matProj.m[0][1] = 0;
		matProj.m[1][1] = 0.5f * (float)ScreenHeight();
		matProj.m[2][1] = 0;
		matProj.m[3][1] = 0.5f * (float)ScreenHeight();

		matProj.m[0][2] = 0;
		matProj.m[1][2] = 0;
		matProj.m[2][2] = 1;
		matProj.m[3][2] = 0;

		matProj.m[0][3] = 0;
		matProj.m[1][3] = 0;
		matProj.m[2][3] = 0;
		matProj.m[3][3] = 1;

		matResize.m[0][0] = 1;
		matResize.m[1][0] = 0;
		matResize.m[2][0] = 0;
		matResize.m[0][1] = 0;
		matResize.m[1][1] = 1;
		matResize.m[2][1] = 0;
		matResize.m[0][2] = 0;
		matResize.m[1][2] = 0;
		matResize.m[2][2] = 1;
		matResize.m[3][3] = 1;

		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		Clear(olc::BLACK);
		triangles.clear();
		
		fTheta += 1.0f * fElapsedTime;

		// Rotation Z
		matRotZ.m[0][0] = cosf(fTheta);
		matRotZ.m[0][1] = sinf(fTheta);
		matRotZ.m[1][0] = -sinf(fTheta);
		matRotZ.m[1][1] = cosf(fTheta);
		matRotZ.m[2][2] = 1.0f;
		matRotZ.m[3][3] = 1.0f;

		// Rotation X
		matRotX.m[0][0] = 1.0f;
		matRotX.m[1][1] = cosf(fTheta * 0.5f);
		matRotX.m[1][2] = sinf(fTheta * 0.5f);
		matRotX.m[2][1] = -sinf(fTheta * 0.5f);
		matRotX.m[2][2] = cosf(fTheta * 0.5f);
		matRotX.m[3][3] = 1.0f;

		for (auto& tris : meshCube.tris) {
			Triangle triProjected, triRotatedX, triRotatedXZ, triResized;
			Vec3 triVec, checkVec;

			//Projection
		

			triRotatedX =  tris.multiplyByMatrix(matRotX);
		    triRotatedXZ = triRotatedX.multiplyByMatrix(matRotZ);
			//triRotatedXZ = tris;

			//triResized = triRotatedXZ.multiplyByMatrix(matResize);
			//triResized.calculateCrossProduct();
			//triResized.calculateDotProduct(Vec3::m_North);


			triProjected = triRotatedXZ.multiplyByMatrix(matProj);

						




	

			
			//Translate to center and resize
			//triProjected.p[0].x += 1.0f; triProjected.p[0].y += 1.0f;
			//triProjected.p[1].x += 1.0f; triProjected.p[1].y += 1.0f;
			//triProjected.p[2].x += 1.0f; triProjected.p[2].y += 1.0f;
			//triProjected.cross.x += 1.0f;	triProjected.cross.y += 1.0f;
			//
			//
			//
			//triProjected.p[0].x *= 0.5f * (float)ScreenWidth() ;
			//triProjected.p[0].y *= 0.5f * (float)ScreenHeight();
			//triProjected.p[1].x *= 0.5f * (float)ScreenWidth() ;
			//triProjected.p[1].y *= 0.5f * (float)ScreenHeight();
			//triProjected.p[2].x *= 0.5f * (float)ScreenWidth() ;
			//triProjected.p[2].y *= 0.5f * (float)ScreenHeight();



			triangles.push_back(triProjected);
		}

		


		//std::sort(triangles.begin(), triangles.end(), [](triangle& t1, triangle& t2) {
		//	return t1.p[0].z + t1.p[1].z + t1.p[2].z > t2.p[0].z + t2.p[1].z + t2.p[2].z;
		//	});


		for (auto& tris : triangles) {

			//if (tris.dot = 0) {
			//FillTriangle(tris.p[0].x, tris.p[0].y, tris.p[1].x, tris.p[1].y, tris.p[2].x, tris.p[2].y, olc::WHITE);
			DrawTriangle(tris.p[0].x, tris.p[0].y, tris.p[1].x, tris.p[1].y, tris.p[2].x, tris.p[2].y, olc::WHITE);
			//DrawLine(tris.p[0].x, tris.p[0].y, tris.cross.x , tris.cross.y ,olc::YELLOW);
				
				
			//}

			

			//DrawString(0, count++ * 10, std::to_string(tris.dot), olc::WHITE, 1);
		}
		DrawString(0, 0, std::to_string(count++), olc::WHITE, 1);

		return true;
	}
};

int main()
{
	olcEngine3D demo;
	if (demo.Construct(400, 200, 2, 2))
		demo.Start();
	return 0;
}
