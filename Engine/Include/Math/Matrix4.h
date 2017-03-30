#pragma once

#include "MathHelper.h"
#include "Vector3.h"
#include <Globals.h>

namespace Engine {

	struct Matrix4
	{
		static const uint iCount = 4;
		float m[iCount][iCount];

		Matrix4()
		{
			InitIdentity();
		}

		inline void InitIdentity() {
			for (uint x = 0; x < iCount; x++) {
				for (uint y = 0; y < iCount; y++) {
					m[x][y] = (x == y) ? 1.0f : 0.0f;
				}
			}
		}

		inline void SetTranslation(Vector3& value) {
			return SetTranslation(value.x, value.y, value.z);
		}

		inline void SetTranslation(float x, float y, float z) {
			m[0][0] = 1; m[0][1] = 0; m[0][2] = 0; m[0][3] = x;
			m[1][0] = 0; m[1][1] = 1; m[1][2] = 0; m[1][3] = y;
			m[2][0] = 0; m[2][1] = 0; m[2][2] = 1; m[2][3] = z;
			m[3][0] = 0; m[3][1] = 0; m[3][2] = 0; m[3][3] = 1;
		}

		inline void SetData(const float(&value)[4][4]) {
			for (int x = 0; x < iCount; x++) {
				for (int y = 0; y < iCount; y++) {
					m[x][y] = value[x][y];
				}
			}
		}

		inline Matrix4 Mul(const Matrix4& rhs) {
			Matrix4 r;

			for (int x = 0; x < iCount; x++) {
				for (int y = 0; y < iCount; y++) {
					r.m[x][y] =
						(
							m[x][0] * rhs.m[0][y] +
							m[x][1] * rhs.m[1][y] +
							m[x][2] * rhs.m[2][y] +
							m[x][3] * rhs.m[3][y]);
				}
			}

			return r;
		}

		static Matrix4 CreateRotationMatrix(const Vector3& value) {
			return CreateRotationMatrix(value.x, value.y, value.z);
		}

		static Matrix4 CreateRotationMatrix(float x, float y, float z) {
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

			ry.m[0][0] = cosf(y);	ry.m[0][1] = 0;			ry.m[0][2] = sinf(y);	ry.m[0][3] = 0;
			ry.m[1][0] = 0;			ry.m[1][1] = 1;			ry.m[1][2] = 0;			ry.m[1][3] = 0;
			ry.m[2][0] = -sinf(y);	ry.m[2][1] = 0;			ry.m[2][2] = cosf(y);	ry.m[2][3] = 0;
			ry.m[3][0] = 0;			ry.m[3][1] = 0;			ry.m[3][2] = 0;			ry.m[3][3] = 1;

			rz.m[0][0] = cosf(z);	rz.m[0][1] = -sinf(z);	rz.m[0][2] = 0;			rz.m[0][3] = 0;
			rz.m[1][0] = sinf(z);	rz.m[1][1] = cosf(z);	rz.m[1][2] = 0;			rz.m[1][3] = 0;
			rz.m[2][0] = 0;			rz.m[2][1] = 0;			rz.m[2][2] = 1;			rz.m[2][3] = 0;
			rz.m[3][0] = 0;			rz.m[3][1] = 0;			rz.m[3][2] = 0;			rz.m[3][3] = 1;

			r = (rz * ry * rx);

			return r;
		}

		static Matrix4 CreateScaleMatrix(const Vector3& value){
			return CreateScaleMatrix(value.x, value.y, value.z);
		}

		static Matrix4 CreateScaleMatrix(float x, float y, float z) {
			Matrix4 r;

			r.m[0][0] = x; r.m[0][1] = 0; r.m[0][2] = 0; r.m[0][3] = 0;
			r.m[1][0] = 0; r.m[1][1] = y; r.m[1][2] = 0; r.m[1][3] = 0;
			r.m[2][0] = 0; r.m[2][1] = 0; r.m[2][2] = z; r.m[2][3] = 0;
			r.m[3][0] = 0; r.m[3][1] = 0; r.m[3][2] = 0; r.m[3][3] = 1;

			return r;
		}

		static Matrix4 CreateIdentityMatrix() {
			Matrix4 result;
			return result;
		}

		static Matrix4 CreateTranslationMatrix(const Vector3& value) {
			Matrix4 result;
			result.SetTranslation(value.x, value.y, value.z);
			return result;
		}

		static Matrix4 CreateTranslationMatrix(float x, float y, float z) {
			Matrix4 result;
			result.SetTranslation(x, y, z);
			return result;
		}

		inline Matrix4 operator* (const Matrix4& rhs) {
			return Mul(rhs);
		}
	};
}