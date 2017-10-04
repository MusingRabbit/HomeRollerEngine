#pragma once
#include "MathHelper.h"

namespace Engine {

	class Quaternion
	{
	public:
		float x, y, z, w;

		Quaternion();

		Quaternion(const float xV, const float yV, const float zV, const float wV);

		float Length();

		Quaternion Normalise();
		Quaternion Conjugate();
		Quaternion Mul(Quaternion& r) const;
		Quaternion Mul(float x, float y, float z) const;
	};
}