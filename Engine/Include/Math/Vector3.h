#pragma once

#include "MathHelper.h"
#include "Vector2.h"

namespace Engine {

	struct Vector3 
	{
		float x;
		float y;
		float z;

		Vector3()
		{
			x = y = z = 0.0f;
		}

		Vector3(float xV, float yV, float zV)
		{
			x = xV;
			y = yV;
			z = zV;
		}

		Vector3(const Vector2& r) {
			x = r.x;
			y = r.y;
			z = 0.0f;
		}

		Vector3(const Vector3& r)
		{
			x = r.x;
			y = r.y;
			z = r.z;
		}

		inline float Length() {
			return sqrtf((x*x) + (y*y) + (z*z));
		}

		inline Vector3 Normalise() {
			float length = Length();
			return Vector3(x /= length, y /= length, z /= length);
		}

		inline Vector3 Rotate(const float r) {
			double radii = ToRadians(r);
			double cos = std::cos(radii);
			double sin = std::sin(radii);

			return Vector3();
		}

		inline float Dot(const Vector3& r) {
			return (x * r.x) +(y * r.y) + (z * r.z);
		}

		inline Vector3 Cross(const Vector3& r) {
			float x_ = ((y * r.z) - (z * r.y));
			float y_ = ((z * r.x) - (x * r.z));
			float z_ = ((x * r.y) - (y * r.x));

			return Vector3(x_, y_, z_);
		}

		inline Vector3 Add(const Vector3& r) {
			return Vector3(x + r.x, y + r.y, z + r.z);
		}

		inline Vector3 Add(const float r)
		{
			return Vector3(x + r, y + r, z + r);
		}

		inline Vector3 Sub(const Vector3& r) {
			return Vector3(x - r.x, y - r.y, z - r.z);
		}

		inline Vector3 Sub(const float r)
		{
			return Vector3(x - r, y - r, z - r);
		}

		inline Vector3 Mul(const Vector3& r) {
			return Vector3(x * r.x, y * r.y, z * r.z);
		}

		inline Vector3 Mul(const float r)
		{
			return Vector3(x * r, y * r, z * r);
		}

		inline Vector3 Div(const Vector3& r) {
			return Vector3(x / r.x, y / r.y, z / r.z);
		}

		inline Vector3 Div(const float r)
		{
			return Vector3(x / r, y / r, z / r);
		}

		std::string ToString() {
			return "{" + std::to_string(x) + "," + std::to_string(y) + "}";
		}

		inline const Vector3& operator=(const Vector3& rhs) {
			x = rhs.x;
			y = rhs.y;
			z = rhs.z;

			return *this;
		}
	};


	inline Vector3 operator+(Vector3 lhs, const Vector3& rhs) {
		return lhs.Add(rhs);
	}

	inline Vector3 operator-(Vector3 lhs, const Vector3& rhs) {
		return lhs.Sub(rhs);
	}

	inline Vector3 operator-(Vector3 lhs, const float rhs) {
		return lhs.Sub(rhs);
	}

	inline Vector3 operator*(Vector3 lhs, const Vector3& rhs) {
		return lhs.Mul(rhs);
	}

	inline Vector3 operator/(Vector3 lhs, const Vector3& rhs) {
		return lhs.Div(rhs);
	}

	inline void operator-=(Vector3 lhs, const Vector3& rhs) {
		lhs.x -= rhs.x;
		lhs.y -= rhs.y;
		lhs.z -= rhs.z;
	}

	inline void operator-=(Vector3 lhs, const float rhs) {
		lhs.x -= rhs;
		lhs.y -= rhs;
		lhs.z -= rhs;
	}

	inline void operator+=(Vector3 lhs, const Vector3& rhs) {
		lhs.x += rhs.x;
		lhs.y += rhs.y;
		lhs.z += rhs.z;
	}

	inline void operator*=(Vector3 lhs, const Vector3& rhs) {
		Vector3 result = lhs.Mul(rhs);
		lhs.x = result.x;
		lhs.y = result.y;
		lhs.z = result.z;
	}

	inline void operator/=(Vector3 lhs, const Vector3& rhs) {
		Vector3 result = lhs.Div(rhs);
		lhs.x = result.x;
		lhs.y = result.y;
		lhs.z = result.z;
	}
}