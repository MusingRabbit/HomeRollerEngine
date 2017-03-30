#include "ObjLoader.h"
#include "Util\StringHelper.h"
#include "Util\File.h"

using namespace std;

namespace Engine {

	ShapeData ObjLoader::LoadFile(const string& filePath)
	{
		ObjModel data;
		ShapeData result;
		vector<string> lines;
		File::ReadLines("res\\models\\" + filePath + ".obj", lines);

		for (uint i = 0; i < lines.size(); i++)
		{
			ProcessLine(lines[i], data);
		}

		return result;
	}

	void ObjLoader::ProcessLine(const std::string & line, ObjModel & data)
	{
		vector<string> tokens;
		StringHelper::SplitString(line, ' ', tokens);

		if (tokens.size() < 1 || tokens[0] == "#") {
			return;
		}

		if (tokens[0] == "v") {
			data.vertices.push_back(GetVector3(tokens));
		}
		else if (tokens[0] == "f") {
			data.indices.push_back(stoi(tokens[1])-1);
			data.indices.push_back(stoi(tokens[2])-1);
			data.indices.push_back(stoi(tokens[3])-1);
		}
		else if (tokens[0] == "vt") {
			data.uvCoords.push_back(GetVector2(tokens));
		}
		else if (tokens[0] == "vn") {
			data.normals.push_back(GetVector3(tokens));
		}

	}
	
	Vector3 ObjLoader::GetVector3(vector<string>& tokens)
	{
		float x = stof(tokens[1]);
		float y = stof(tokens[2]);
		float z = stof(tokens[3]);

		return Vector3(x,y,z);
	}

	Vector2 ObjLoader::GetVector2(vector<string>& tokens)
	{
		float x = stof(tokens[1]);
		float y = stof(tokens[2]);
		
		return Vector2(x,y);
	}

	ShapeData ObjLoader::ObjModelToShapeData(ObjModel & data)
	{
		ShapeData result;

		for (uint i = 0; i < data.vertices.size(); i++) {
			
		}

		return result;
	}


}
