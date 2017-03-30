#pragma once

#include "MathHelper.h"

namespace Engine {
	struct Vector2 {
		float x;
		float y;

		Vector2()
		{
			x = y = 0.0f;
		}

		Vector2(float x, float y)
		{
			x = x;
			y = y;
		}

		Vector2(const Vector2& r)
		{
			x = r.x;
			y = r.y;
		}

		float Length() {
			return sqrtf((x*x) + (y*y));
		}

		Vector2 Normalise() {
			float length = Length();
			return Vector2(x /= length, y /= length);
		}

		Vector2 Rotate(const float r) {
			double radii = ToRadians(r);
			double cos = std::cos(radii);
			double sin = std::sin(radii);

			float x = static_cast<float>(x * cos - y * sin);
			float y = static_cast<float>(x * sin + y * cos);

			return Vector2(x,y);
		}

		float Dot(const Vector2& r) {
			return (x * r.x) + y * r.y;
		}

		Vector2 Add(const Vector2& r) {
			return Vector2(x + r.x, y + r.y);
		}

		Vector2 Add(const float r)
		{
			return Vector2(x + r, y + r);
		}

		Vector2 Sub(const Vector2& r) {
			return Vector2(x - r.x, y - r.y);
		}

		Vector2 Sub(const float r)
		{
			return Vector2(x - r, y - r);
		}

		Vector2 Mul(const Vector2& r) {
			return Vector2(x * r.x, y * r.y);
		}

		Vector2 Mul(const float r)
		{
			return Vector2(x * r, y * r);
		}

		Vector2 Div(const Vector2& r) {
			return Vector2(x / r.x, y / r.y);
		}

		Vector2 Div(const float r)
		{
			return Vector2(x / r, y / r);
		}

		std::string ToString() {
			return "{" + std::to_string(x) + "," + std::to_string(y) + "}";
		}

	};


	inline Vector2 operator+(Vector2 lhs, const Vector2& rhs) {
		return lhs.Add(rhs);
	}

	inline Vector2 operator-(Vector2 lhs, const Vector2& rhs) {
		return lhs.Sub(rhs);
	}

	inline Vector2 operator-(Vector2 lhs, const float rhs) {
		return lhs.Sub(rhs);
	}

	inline Vector2 operator*(Vector2 lhs, const Vector2& rhs) {
		return lhs.Mul(rhs);
	}

	inline Vector2 operator/(Vector2 lhs, const Vector2& rhs) {
		return lhs.Div(rhs);
	}

	inline void operator-=(Vector2 lhs, const Vector2& rhs) {
		lhs.x -= rhs.x;
		lhs.y -= rhs.y;
	}

	inline void operator-=(Vector2 lhs, const float rhs) {
		lhs.x -= rhs;
		lhs.y -= rhs;
	}

	inline void operator+=(Vector2 lhs, const Vector2& rhs) {
		lhs.x += rhs.x;
		lhs.y += rhs.y;
	}

	inline void operator*=(Vector2 lhs, const Vector2& rhs) {
		Vector2 result = lhs.Mul(rhs);
		lhs.x = result.x;
		lhs.y = result.y;
	}

	inline void operator/=(Vector2 lhs, const Vector2& rhs) {
		Vector2 result = lhs.Div(rhs);
		lhs.x = result.x;
		lhs.y = result.y;
	}
}