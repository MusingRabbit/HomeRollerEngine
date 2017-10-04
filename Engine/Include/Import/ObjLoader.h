#pragma once
#include "Render\ShapeData.h"
#include "Math\Vector3.h"
#include "Math\Vector2.h"
#include <string>
#include <vector>

using namespace std;

namespace Engine {

	struct Face{
		Face(){}
		vector<int> data[3]; //3 being the count of verts in a tri
	};

	struct ObjModel {
		vector<Vector3> vertices;
		vector<Vector3> normals;
		vector<Vector2> uvCoords;
		vector<Face> faces;

		bool hasNormals() { return normals.size() > 0; }
		bool hasUVCoords() { return uvCoords.size() > 0; }
	};

	class ObjLoader
	{
	public:
		static ShapeData LoadFile(const std::string& filePath);

	private :
		static void ProcessLine(const std::string& line, ObjModel& shapeData);

		static Vector3 GetVector3(vector<string>& tokens);
		static Vector2 GetVector2(vector<string>& tokens);
		static Face GetFace(vector<string>& tokens);

		static ShapeData ObjModelToShapeData(ObjModel& data);
		
	};

}
