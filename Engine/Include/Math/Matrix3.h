#pragma once
#include "MathHelper.h"

namespace Engine {

	struct Matrix3
	{
		static const int iCount = 3;
		float data[iCount][iCount];

		Matrix3()
		{

		}

		static Matrix3 GetIdentity() {
			Matrix3 result;
			for (int x = 0; x < iCount; x++) {
				for (int y = 0; y < iCount; y++) {
					result.data[x][y] = (x == y) ? 1.0f : 0.0f;
				}
			}
			return result;
		}

		inline Matrix3 Mul(const Matrix3& r) {
			Matrix3 result;

			for (int x = 0; x < iCount; x++) {
				for (int y = 0; y < iCount; y++) {
					data[x][y] =
						(
							data[x][0] * r.data[0][y] +
							data[x][1] * r.data[1][y] +
							data[x][2] * r.data[2][y]);
				}
			}

			return result;
		}
	};
}