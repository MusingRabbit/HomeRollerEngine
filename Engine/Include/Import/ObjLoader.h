#pragma once
#include "Render\ShapeData.h"
#include "Math\Math.h"
#include <string>
#include <vector>

using namespace std;

namespace Engine {

	struct ObjModel {
		vector<Vector3> vertices;
		vector<Vector3> normals;
		vector<Vector2> uvCoords;
		vector<int> indices;
	};

	class ObjLoader
	{
	public:
		static ShapeData LoadFile(const std::string& filePath);

	private :
		static void ProcessLine(const std::string& line, ObjModel& shapeData);

		static Vector3 GetVector3(vector<string>& tokens);
		static Vector2 GetVector2(vector<string>& tokens);
		static ShapeData ObjModelToShapeData(ObjModel& data);
		
	};

}
