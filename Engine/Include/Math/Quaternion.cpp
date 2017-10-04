#include "Quaternion.h"

namespace Engine {

	Quaternion::Quaternion() {
		x = y = z = w = 0.0f;
	}

	Quaternion::Quaternion(const float xV, const float yV, const float zV, const float wV) {
		x = xV;
		y = yV;
		z = zV;
		w = wV;
	}

	float Quaternion::Length() {
		return sqrtf(x*x + y*y + z*z + w*w);
	}

	Quaternion Quaternion::Normalise() {
		Quaternion result;
		float length = Length();
		result.x /= length;
		result.y /= length;
		result.z /= length;
		result.w /= length;
		return result;
	}

	Quaternion Quaternion::Conjugate() {
		return Quaternion(-x, -y, -z, w);
	}

	Quaternion Quaternion::Mul(Quaternion& r) const {
		float _w = (w * r.w) - (x * r.x) - (y * r.y) - (z * r.z);
		float _x = (x * r.w) + (w * r.x) + (y * r.z) - (z * r.y);
		float _y = (y * r.w) + (w * r.y) + (z * r.x) - (x * r.z);
		float _z = (z * r.w) + (w * r.z) + (x * r.y) - (y * r.x);
		return Quaternion(_x, _y, _z, _w);
	}

	Quaternion Quaternion::Mul(float _x, float _y, float _z) const {
		float rW = (-x * _x) - (y * _y) - (z * _z);
		float rX = (w * _x) + (y * _z) - (z * _y);
		float rY = (w * _y) + (z * _x) - (x * _z);
		float rZ = (w * _z) + (x * _y) - (y * _x);
		return Quaternion(rX, rY, rZ, rW);
	}

}