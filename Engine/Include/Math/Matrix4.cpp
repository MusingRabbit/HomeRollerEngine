#include "Matrix4.h"

namespace Engine {

	Matrix4::Matrix4() {
		InitIdentity();
	}

	Matrix4::Matrix4(const float(&value)[4][4]) {
		for (uint x = 0; x < iCount; x++) {
			for (uint y = 0; y < iCount; y++) {
				m[x][y] = value[x][y];
			}
		}
	}

	void Matrix4::InitIdentity() {
		for (uint x = 0; x < iCount; x++) {
			for (uint y = 0; y < iCount; y++) {
				m[x][y] = (x == y) ? 1.0f : 0.0f;
			}
		}
	}

	void Matrix4::SetTranslation(Vector3& value) {
		return SetTranslation(value.x, value.y, value.z);
	}

	void Matrix4::SetTranslation(float x, float y, float z) {
		m[0][0] = 1; m[0][1] = 0; m[0][2] = 0; m[0][3] = x;
		m[1][0] = 0; m[1][1] = 1; m[1][2] = 0; m[1][3] = y;
		m[2][0] = 0; m[2][1] = 0; m[2][2] = 1; m[2][3] = z;
		m[3][0] = 0; m[3][1] = 0; m[3][2] = 0; m[3][3] = 1;
	}

	void Matrix4::SetData(const float(&value)[4][4]) {
		for (int x = 0; x < iCount; x++) {
			for (int y = 0; y < iCount; y++) {
				m[x][y] = value[x][y];
			}
		}
	}

	Matrix4 Matrix4::Mul(const Matrix4& rhs) {
		return Mul(rhs.m);
	}

	Matrix4 Matrix4::Mul(const float(&rhs)[4][4]) {
		Matrix4 r;
		for (int x = 0; x < iCount; x++) {
			for (int y = 0; y < iCount; y++) {
				r.m[x][y] =
					(
						m[x][0] * rhs[0][y] +
						m[x][1] * rhs[1][y] +
						m[x][2] * rhs[2][y] +
						m[x][3] * rhs[3][y]);
			}
		}
		return r;
	}

	Matrix4 Matrix4::CreateRotationMatrix(const Vector3& value) {
		return CreateRotationMatrix(value.x, value.y, value.z);
	}

	Matrix4 Matrix4::CreateRotationMatrix(const float amt, Vector3& dir) {
		float x = dir.x * amt;
		float y = dir.y * amt;
		float z = dir.z * amt;
		return CreateRotationMatrix(x, y, z);
	}

	Matrix4 Matrix4::CreateRotationMatrix(float x, float y, float z) {
		Matrix4	rx;
		Matrix4	ry;
		Matrix4	rz;
		Matrix4 r;

		x = (float)ToRadians(x);
		y = (float)ToRadians(y);
		z = (float)ToRadians(z);

		rx.m[0][0] = 1;			rx.m[0][1] = 0;			rx.m[0][2] = 0;			rx.m[0][3] = 0;
		rx.m[1][0] = 0;			rx.m[1][1] = cosf(x);	rx.m[1][2] = -sinf(x);	rx.m[1][3] = 0;
		rx.m[2][0] = 0;			rx.m[2][1] = sinf(x);	rx.m[2][2] = cosf(x);	rx.m[2][3] = 0;
		rx.m[3][0] = 0;			rx.m[3][1] = 0;			rx.m[3][2] = 0;			rx.m[3][3] = 1;

		ry.m[0][0] = cosf(y);	ry.m[0][1] = 0;			ry.m[0][2] = -sinf(y);	ry.m[0][3] = 0;
		ry.m[1][0] = 0;			ry.m[1][1] = 1;			ry.m[1][2] = 0;			ry.m[1][3] = 0;
		ry.m[2][0] = sinf(y);	ry.m[2][1] = 0;			ry.m[2][2] = cosf(y);	ry.m[2][3] = 0;
		ry.m[3][0] = 0;			ry.m[3][1] = 0;			ry.m[3][2] = 0;			ry.m[3][3] = 1;

		rz.m[0][0] = cosf(z);	rz.m[0][1] = -sinf(z);	rz.m[0][2] = 0;			rz.m[0][3] = 0;
		rz.m[1][0] = sinf(z);	rz.m[1][1] = cosf(z);	rz.m[1][2] = 0;			rz.m[1][3] = 0;
		rz.m[2][0] = 0;			rz.m[2][1] = 0;			rz.m[2][2] = 1;			rz.m[2][3] = 0;
		rz.m[3][0] = 0;			rz.m[3][1] = 0;			rz.m[3][2] = 0;			rz.m[3][3] = 1;

		r = (rz * ry * rx);

		return r;
	}

	Matrix4 Matrix4::LookAtMatrix(Vector3& fwd, Vector3& pos, Vector3& up) {
		Matrix4 r;

		Matrix4 trans;
		trans.SetTranslation(pos);

		Vector3 z = fwd.Normalise();
		Vector3 x = up.Normalise().Cross(z);
		Vector3 y = z.Cross(x);

		r.m[0][0] = x.x;	r.m[0][1] = x.y;		r.m[0][2] = x.z;		r.m[0][3] = 0;
		r.m[1][0] = y.x;	r.m[1][1] = y.y;		r.m[1][2] = y.z;		r.m[1][3] = 0;
		r.m[2][0] = z.x;	r.m[2][1] = z.y;		r.m[2][2] = z.z;		r.m[2][3] = 0;
		r.m[3][0] = 0;		r.m[3][1] = 0;			r.m[3][2] = 0;			r.m[3][3] = 1;

		return r * trans;
	}

	Matrix4 Matrix4::CreatePerspectiveMatrix(float fov, float aspect, float zNear, float zFar) {
		Matrix4 r;

		float tanThetaOver2 = (float)tanf(ToRadians(fov / 2));
		float zRange = zNear - zFar;
		float zTotal = zNear + zFar;

		r.m[0][0] = 1.0f / (tanThetaOver2 * aspect);		r.m[0][1] = 0;						r.m[0][2] = 0;					r.m[0][3] = 0;
		r.m[1][0] = 0;										r.m[1][1] = 1.0f / tanThetaOver2;	r.m[1][2] = 0;					r.m[1][3] = 0;
		r.m[2][0] = 0;										r.m[2][1] = 0;						r.m[2][2] = -zTotal / zRange;	    r.m[2][3] = 2 * zFar * zNear / zRange;
		r.m[3][0] = 0;										r.m[3][1] = 0;						r.m[3][2] = 1;					r.m[3][3] = 0;

		return r;
	}

	Matrix4 Matrix4::CreateScaleMatrix(const Vector3& value) {
		return CreateScaleMatrix(value.x, value.y, value.z);
	}

	Matrix4 Matrix4::CreateScaleMatrix(float x, float y, float z) {
		Matrix4 r;

		r.m[0][0] = x; r.m[0][1] = 0; r.m[0][2] = 0; r.m[0][3] = 0;
		r.m[1][0] = 0; r.m[1][1] = y; r.m[1][2] = 0; r.m[1][3] = 0;
		r.m[2][0] = 0; r.m[2][1] = 0; r.m[2][2] = z; r.m[2][3] = 0;
		r.m[3][0] = 0; r.m[3][1] = 0; r.m[3][2] = 0; r.m[3][3] = 1;

		return r;
	}

	Matrix4 Matrix4::CreateIdentityMatrix() {
		Matrix4 result;
		return result;
	}

	Matrix4 Matrix4::CreateTranslationMatrix(const Vector3& value) {
		Matrix4 result;
		result.SetTranslation(value.x, value.y, value.z);
		return result;
	}

	Matrix4 Matrix4::CreateTranslationMatrix(float x, float y, float z) {
		Matrix4 result;
		result.SetTranslation(x, y, z);
		return result;
	}

	Matrix4 Matrix4::operator* (const Matrix4& rhs) {
		return Mul(rhs);
	}

	Matrix4 Matrix4::operator* (const float(&rhs)[4][4]) {
		return Mul(rhs);
	}

	Matrix4 Matrix4::operator *= (const Matrix4& rhs) {
		return Mul(rhs) * m;
	}

	Matrix4 Matrix4::operator *= (const float(&rhs)[4][4]) {
		return Mul(rhs) * m;
	}
}