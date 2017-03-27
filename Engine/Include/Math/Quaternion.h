#pragma once
#include "MathHelper.h"
#include "Vector3.h"

namespace Engine {

	struct Quaternion
	{
		float x, y, z, w;

		Quaternion()
		{
			x = y = z = w = 0.0f;
		}

		Quaternion(const float xV, const float yV, const float zV, const float wV)
		{
			x = xV;
			y = yV;
			z = zV;
			w = wV;
		}

		float Length() 
		{
			return sqrtf(x*x + y*y + z*z + w*w);
		}

		Quaternion Normalise() 
		{
			Quaternion result;
			float length = Length();
			result.x /= length;
			result.y /= length;
			result.z /= length;
			result.w /= length;
			return result;
		}

		Quaternion Conjugate() 
		{
			return Quaternion(-x, -y, -z, w);
		}

		Quaternion Mul(Quaternion r)
		{
			float _w = (w * r.w) - (x * r.x) - (y * r.y) - (z * r.z);
			float _x = (x * r.w) + (w * r.x) + (y * r.z) - (z * r.y);
			float _y = (y * r.w) + (w * r.y) + (z * r.x) - (x * r.z);
			float _z = (z * r.w) + (w * r.z) + (x * r.y) - (y * r.x);
			return Quaternion(_x, _y, _z, _w);
		}

		Quaternion Mul(Vector3 r)
		{
			float _w = (-x * r.x) - (y * r.y) - (z * r.z);
			float _x = (w * r.x) + (y * r.z) - (z * r.y);
			float _y = (w * r.y) + (z * r.x) - (x * r.z);
			float _z = (w * r.z) + (x * r.y) - (y * r.x);
		}
	};
}