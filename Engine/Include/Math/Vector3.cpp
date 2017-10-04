#include "Vector3.h"

namespace Engine {

	Vector3::Vector3() {
		x = y = z = 0.0f;
	}

	Vector3::Vector3(float xV, float yV, float zV) {
		x = xV;
		y = yV;
		z = zV;
	}

	Vector3::Vector3(const Vector2& r) {
		x = r.x;
		y = r.y;
		z = 0.0f;
	}

	Vector3::Vector3(const Vector3& r) {
		x = r.x;
		y = r.y;
		z = r.z;
	}


	float Vector3::Length() {
		return sqrtf((x*x) + (y*y) + (z*z));
	}

	Vector3 Vector3::Normalise() {
		float length = Length();
		return Vector3(x /= length, y /= length, z /= length);
	}

	Vector3 Vector3::Rotate(const float r) const {
		double radii = ToRadians(r);
		double cos = std::cos(radii);
		double sin = std::sin(radii);

		return Vector3();
	}

	float Vector3::Dot(const Vector3& r) {
		return (x * r.x) + (y * r.y) + (z * r.z);
	}

	Vector3 Vector3::Cross(const Vector3& r) const {
		float x_ = ((y * r.z) - (z * r.y));
		float y_ = ((z * r.x) - (x * r.z));
		float z_ = ((x * r.y) - (y * r.x));

		return Vector3(x_, y_, z_);
	}

	Vector3 Vector3::Add(const Vector3& r) const {
		return Vector3(x + r.x, y + r.y, z + r.z);
	}

	Vector3 Vector3::Add(const float r) const {
		return Vector3(x + r, y + r, z + r);
	}

	Vector3 Vector3::Sub(const Vector3& r) const {
		return Vector3(x - r.x, y - r.y, z - r.z);
	}

	Vector3 Vector3::Sub(const float r) const {
		return Vector3(x - r, y - r, z - r);
	}

	Vector3 Vector3::Mul(const Vector3& r) const {
		return Vector3(x * r.x, y * r.y, z * r.z);
	}

	Vector3 Vector3::Mul(const float(&rhs)[3][3]) const {
		Vector3 r;

		for (int x = 0; x < 3; x++) {
			r.x += r.x * rhs[x][0];
			r.y += r.y * rhs[x][1];
			r.z += r.z * rhs[x][2];
		}

		return r;
	}

	Vector3 Vector3::Mul(const float r) const {
		return Vector3(x * r, y * r, z * r);
	}

	Vector3 Vector3::Div(const Vector3& r) const {
		return Vector3(x / r.x, y / r.y, z / r.z);
	}

	Vector3 Vector3::Div(const float r) const {
		return Vector3(x / r, y / r, z / r);
	}

	Vector3 Vector3::Rotate(float angle, const Vector3& axis) const {
		Vector3 result;
		float fSinHalfAngle = sinf(ToRadians(angle / 2));
		float fCosHalfAngle = cosf(ToRadians(angle / 2));

		float rX = axis.x * fSinHalfAngle;
		float rY = axis.y * fSinHalfAngle;
		float rZ = axis.z * fSinHalfAngle;
		float rW = fCosHalfAngle;

		Quaternion qRot(rX, rY, rZ, rW);
		Quaternion qConj = qRot.Conjugate();
		Quaternion qResult = qRot.Mul(x, y, z).Mul(qConj);

		result.x = qResult.x;
		result.y = qResult.y;
		result.z = qResult.z;

		return result;
	}

	std::string Vector3::ToString() {
		return "{" + std::to_string(x) + "," + std::to_string(y) + "," + std::to_string(z) + "}";
	}

	const Vector3& Vector3::operator=(const Vector3& rhs) {
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;

		return *this;
	}

	void Vector3::operator-=(const Vector3& rhs) {
		x -= rhs.x;
		y -= rhs.y;
		z -= rhs.z;
	}

	void Vector3::operator-=(const float rhs) {
		x -= rhs;
		y -= rhs;
		z -= rhs;
	}

	Vector3 Vector3::operator*(const float(&rhs)[3][3]) const
	{
		return Mul(rhs);
	}

	Vector3 Vector3::operator*(const float rhs) const
	{
		return Mul(rhs);
	}

	Vector3 Vector3::operator-(const float rhs) const
	{
		return Sub(rhs);
	}

	Vector3 Vector3::operator+(const Vector3 & rhs) const
	{
		return Add(rhs);
	}

	Vector3 Vector3::operator-(const Vector3 & rhs) const
	{
		return Sub(rhs);
	}

	Vector3 Vector3::operator*(const Vector3 & rhs) const
	{
		return Mul(rhs);
	}

	Vector3 Vector3::operator/(const Vector3 & rhs) const
	{
		return Div(rhs);
	}

	void Vector3::operator+=(const Vector3& rhs) {
		x += rhs.x;
		y += rhs.y;
		z += rhs.z;
	}

	void Vector3::operator*=(const Vector3& rhs) {
		x *= rhs.x;
		y *= rhs.y;
		z *= rhs.z;
	}

	void Vector3::operator/=(const Vector3& rhs) {
		x /= rhs.x;
		y /= rhs.y;
		z /= rhs.z;
	}
}