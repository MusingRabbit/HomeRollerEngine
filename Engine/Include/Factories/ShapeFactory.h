#pragma once
#  define EXPORT __declspec(dllexport)

#include "Render\ShapeData.h"
#include "Math\Math.h"
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
		static ShapeData MakeTestCube();
		static ShapeData MakePlane(uint dimensions = 10);
		static ShapeData GenerateNormalLines(const ShapeData& data);
	};
}