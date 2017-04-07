#include "ObjLoader.h"
#include "Util\StringHelper.h"
#include "Util\File.h"
#include <iostream>

using namespace std;

namespace Engine {

	ShapeData ObjLoader::LoadFile(const string& filePath)
	{
		ObjModel data;
		vector<string> lines;
		File::ReadLines("res\\models\\" + filePath + ".obj", lines);

		for (uint i = 0; i < lines.size(); i++)
		{
			ProcessLine(lines[i], data);
		}

		return ObjModelToShapeData(data);
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
			data.faces.push_back(GetFace(tokens));
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

	Face ObjLoader::GetFace(vector<string>& tokens)
	{
		Face result;

		for (int i = 1; i < tokens.size(); i++) {
			vector<string> el;
			StringHelper::SplitString(tokens[i], '/', el);

			for (int j = 0; j < el.size(); j++) {
				string s = el[j];
				int value = s == "" ? -1 :stoi(el[j])-1;
				result.data[i-1].push_back(value);
			}
		}

		return result;
	}




	ShapeData ObjLoader::ObjModelToShapeData(ObjModel & data)
	{
		ShapeData result;
		bool hasNormals = data.hasNormals();
		bool hasUVs = data.hasUVCoords();

		for (uint i = 0; i < data.vertices.size(); i++) {
			Vertex v;
			v.position = data.vertices[i];
			result.vertices.push_back(v);
		}

		for (uint i = 0; i < data.faces.size(); i++) {
			Face& face = data.faces[i];

			GLushort idx1 = (GLushort)face.data[0][0];
			GLushort idx2 = (GLushort)face.data[1][0];
			GLushort idx3 = (GLushort)face.data[2][0];

			Vertex& v1 = result.vertices[(int)idx1];
			Vertex& v2 = result.vertices[(int)idx2];
			Vertex& v3 = result.vertices[(int)idx3];

			if (hasUVs) {
				v1.uvCoord = data.uvCoords[face.data[0][1] ];
				v2.uvCoord = data.uvCoords[face.data[1][1] ];
				v3.uvCoord = data.uvCoords[face.data[2][1] ];
			}

			if (hasNormals) {
				v1.normal = data.normals[face.data[0][2] ];
				v2.normal = data.normals[face.data[1][2] ];
				v3.normal = data.normals[face.data[2][2] ];
			}
			else {
				Vector3 a, b, n;
				a = v1.position - v2.position;
				b = v1.position - v3.position;
				n = a.Cross(b);
				v1.normal = n;
				v2.normal = n;
				v3.normal = n;
			}

			result.indices.push_back(idx1);
			result.indices.push_back(idx2);
			result.indices.push_back(idx3);
		}

		return result;
	}


}
