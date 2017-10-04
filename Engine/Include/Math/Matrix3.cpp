#include "Matrix3.h"

namespace Engine {

	Matrix3::Matrix3() {

	}

	Matrix3::Matrix3(const float(&rhs)[3][3]) {
		for (int x = 0; x < iCount; x++) {
			for (int y = 0; y < iCount; y++) {
				m[x][y] = rhs[x][y];
			}
		}
	}

	Matrix3::Matrix3(Matrix4& value) {
		for (int x = 0; x < iCount; x++) {
			for (int y = 0; y < iCount; y++) {
				m[x][y] = value.m[x][y];
			}
		}
	}

	Matrix3 Matrix3::Mul(const float(&rhs)[3][3]) {
		Matrix3 r;

		for (int x = 0; x < iCount; x++) {
			for (int y = 0; y < iCount; y++) {
				r.m[x][y] =
					(
						r.m[x][0] * rhs[0][y] +
						r.m[x][1] * rhs[1][y] +
						r.m[x][2] * rhs[2][y]);
			}
		}
		return r;
	}

	Matrix3 Matrix3::Mul(const Matrix3& rhs) {
		return Mul(rhs.m);
	}

	Vector3 Matrix3::Mul(const Vector3& rhs) {
		Vector3 r;

		r.x = (rhs.x*m[0][0]) + (rhs.x*m[0][1]) + (rhs.x*m[0][2]);
		r.y = (rhs.y*m[1][0]) + (rhs.y*m[1][1]) + (rhs.y*m[1][2]);
		r.z = (rhs.z*m[2][0]) + (rhs.z*m[2][1]) + (rhs.z*m[2][2]);

		return r;
	}


	Matrix3 Matrix3::operator* (const Matrix3& rhs) {
		return Mul(rhs);
	}

	Matrix3 Matrix3::operator*= (const Matrix3& rhs) {
		return Mul(rhs) * m;
	}

	Vector3 Matrix3::operator* (const Vector3& rhs) {
		return Mul(rhs);
	}
	

}