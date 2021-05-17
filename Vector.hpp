#pragma once

#include <cmath>

namespace chymath
{
	class Vector2D
	{
		Vector2D(double x = 0.f, double y = 0.f) : X(x), Y(y) {}

		double size() const { return sqrt(X * X + Y * Y); }
		void normalize() { X /= size(); Y /= size(); }

		double X;
		double Y;
	};
}
