#pragma once

#include <math.h>
#include <string>

namespace Engine {

	static const double PI = 3.1415926535897932384626433832795028841971693993751058209749445923078164062;
	static double ToRadians(double x) { return (x * PI)/180; }
	static double ToDegrees(double x) { return (x * 180)/PI; }
}