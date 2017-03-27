#pragma once
#  define EXPORT __declspec(dllexport)

#include "Render\ShapeData.h"
#include "Math\Vector2.h"
#include "Math\Vector3.h"
#include "Math\Matrix3.h"
#include "Math\Matrix4.h"
#include <vector>

#include <assert.h>
#include "Globals.h"

namespace Engine {

	class EXPORT ShapeFactory
	{
	public:
		static ShapeData MakeTriangle();
		static ShapeData MakeCube();
		static ShapeData MakeArrow();
		static ShapeData MakePlane(uint dimensions = 10);
		static ShapeData GenerateNormalLines(const ShapeData& data);
	};
}