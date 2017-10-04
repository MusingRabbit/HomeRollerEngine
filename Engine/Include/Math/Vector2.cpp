#include "Vector2.h"

namespace Engine {

	Vector2::Vector2() {
		x = y = 0.0f;
	}

	Vector2::Vector2(float _x, float _y)
	{
		x = _x;
		y = _y;
	}

	Vector2::Vector2(const Vector2& r) {
		x = r.x;
		y = r.y;
	}

	float Vector2::Length() {
		return sqrtf((x*x) + (y*y));
	}

	Vector2 Vector2::Normalise() {
		float length = Length();
		return Vector2(x /= length, y /= length);
	}

	Vector2 Vector2::Rotate(const float r) {
		double radii = ToRadians(r);
		double cos = std::cos(radii);
		double sin = std::sin(radii);

		float xPos = static_cast<float>(x * cos - y * sin);
		float yPos = static_cast<float>(x * sin + y * cos);

		return Vector2(xPos, yPos);
	}

	float Vector2::Dot(const Vector2& r) {
		return (x * r.x) + y * r.y;
	}

	Vector2 Vector2::Add(const Vector2& r) {
		return Vector2(x + r.x, y + r.y);
	}

	Vector2 Vector2::Add(const float r) {
		return Vector2(x + r, y + r);
	}

	Vector2 Vector2::Sub(const Vector2& r) {
		return Vector2(x - r.x, y - r.y);
	}

	Vector2 Vector2::Sub(const float r) {
		return Vector2(x - r, y - r);
	}

	Vector2 Vector2::Mul(const Vector2& r) {
		return Vector2(x * r.x, y * r.y);
	}

	Vector2 Vector2::Div(const Vector2& r) {
		return Vector2(x / r.x, y / r.y);
	}

	Vector2 Vector2::Mul(const float r) {
		return Vector2(x * r, y * r);
	}

	Vector2 Vector2::Div(const float r) {
		return Vector2(x / r, y / r);
	}

	std::string Vector2::ToString() {
		return "{" + std::to_string(x) + "," + std::to_string(y) + "}";
	}
}