#pragma once
#include "MathHelper.h"
#include "Globals.h"

namespace Engine {

	class EXPORT Vector2
	{
	public:

		float x;
		float y;

		Vector2();

		Vector2(float x, float y);

		Vector2(const Vector2& r);

		Vector2 Normalise();

		Vector2 Rotate(const float r);

		Vector2 Add(const Vector2& r);

		Vector2 Add(const float r);

		Vector2 Sub(const Vector2& r);

		Vector2 Sub(const float r);

		Vector2 Mul(const Vector2& r);

		Vector2 Mul(const float r);

		Vector2 Div(const Vector2& r);

		Vector2 Div(const float r);

		float Length();

		float Dot(const Vector2& r);

		std::string ToString();
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