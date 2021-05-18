#pragma once

#include <cmath>

namespace chymath
{
	class Vector2D
	{
	public:
		Vector2D(double x = 0.f, double y = 0.f) : X(x), Y(y) {}

		double Size() const { return sqrt(X * X + Y * Y); }
		void Normalize() { X /= Size(); Y /= Size(); }

		Vector2D& operator+=(const Vector2D& rhs)
		{
			X = rhs.X;
			Y = rhs.Y;

			return *this;
		}

		Vector2D& operator-=(const Vector2D& rhs)
		{
			X -= rhs.X;
			Y -= rhs.Y;

			return *this;
		}

		Vector2D& operator*=(double scalar)
		{
			X *= scalar;
			Y *= scalar;

			return *this;
		}

		double X;
		double Y;
	};

	Vector2D operator+(const Vector2D& lhs, const Vector2D& rhs)
	{
		return Vector2D(lhs.X + rhs.X, lhs.Y + rhs.Y);
	}

	Vector2D operator-(const Vector2D& lhs, const Vector2D& rhs)
	{
		return Vector2D(lhs.X - rhs.X, lhs.Y - rhs.Y);
	}

	Vector2D operator*(const Vector2D& lhs, double scalar)
	{
		return Vector2D(lhs.X * scalar, lhs.Y * scalar);
	}

	Vector2D operator*(double scalar, const Vector2D& rhs)
	{
		return rhs * scalar;
	}

	double operator*(const Vector2D& lhs, const Vector2D& rhs)
	{
		return lhs.X * rhs.X + lhs.Y * rhs.Y;
	}
}
