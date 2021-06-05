#pragma once

#include <cmath>

namespace chymath
{
	class Vector2D
	{
	public:
		Vector2D(double x = 0.f, double y = 0.f) : X(x), Y(y) {}

		double Size() const { return sqrt(X * X + Y * Y); }
		Vector2D& Normalize() { X /= Size(); Y /= Size(); }

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

		Vector2D& operator/=(double scalar)
		{
			X /= scalar;
			Y /= scalar;

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

	Vector2D operator/(const Vector2D& lhs, double scalar)
	{
		return Vector2D(lhs.X / scalar, lhs.Y / scalar);
	}

	Vector2D operator/(double scalar, const Vector2D& rhs)
	{
		return rhs * scalar;
	}

	bool operator==(const Vector2D& lhs, const Vector2D& rhs)
	{
		return lhs.X == rhs.X && lhs.Y == rhs.Y;
	}

	bool operator>(const Vector2D& lhs, const Vector2D& rhs)
	{
		return lhs.Size() > rhs.Size();
	}

	bool operator>=(const Vector2D& lhs, const Vector2D& rhs)
	{
		return lhs.Size() >= rhs.Size();
	}

	bool operator<(const Vector2D& lhs, const Vector2D& rhs)
	{
		return lhs.Size() < rhs.Size();
	}

	bool operator<=(const Vector2D& lhs, const Vector2D& rhs)
	{
		return lhs.Size() <= rhs.Size();
	}

	Vector2D Lerp(const Vector2D& lhs, const Vector2D& rhs, double delta)
	{
		return Vector2D(lhs + (rhs - lhs) * delta);
	}

	Vector2D Reflect(const Vector2D& v, const Vector2D& n)
	{
		return v - 2.f * v * n * n;
	}

	double RadianBetween(const Vector2D& lhs, const Vector2D& rhs)
	{
		return acos(lhs * rhs) / (lhs.Size() * rhs.Size());
	}

	class Vector3D
	{
	public:
		Vector3D(double x = 0.f, double y = 0.f, double z = 0.f) : X(x), Y(y), Z(z) {}

		double Size() const { return sqrt(X * X + Y * Y + Z * Z); }
		void Normalize() { X /= Size(); Y /= Size(); Z /= Size(); }

		Vector3D& operator+=(const Vector3D& rhs)
		{
			X += rhs.X;
			Y += rhs.Y;
			Z += rhs.Z;

			return *this;
		}

		Vector3D& operator-=(const Vector3D& rhs)
		{
			X -= rhs.X;
			Y -= rhs.Y;
			Z -= rhs.Z;

			return *this;
		}

		Vector3D& operator*=(double scalar)
		{
			X *= scalar;
			Y *= scalar;
			Z *= scalar;

			return *this;
		}

		Vector3D& operator/=(double scalar)
		{
			X /= scalar;
			Y /= scalar;
			Z /= scalar;

			return *this;
		}

		double X;
		double Y;
		double Z;
	};

	Vector3D operator+(const Vector3D& lhs, const Vector3D& rhs)
	{
		return Vector3D(lhs.X + rhs.X, lhs.Y + rhs.Y, lhs.Z + rhs.Z);
	}

	Vector3D operator-(const Vector3D& lhs, const Vector3D& rhs)
	{
		return Vector3D(lhs.X - rhs.X, lhs.Y - rhs.Y, lhs.Z - rhs.Z);
	}

	Vector3D operator*(const Vector3D& lhs, double scalar)
	{
		return Vector3D(lhs.X * scalar, lhs.Y * scalar, lhs.Z * scalar);
	}

	Vector3D operator*(double scalar, const Vector3D& rhs)
	{
		return rhs * scalar;
	}

	Vector3D operator/(const Vector3D& lhs, double scalar)
	{
		return Vector3D(lhs.X / scalar, lhs.Y / scalar, lhs.Z / scalar);
	}

	Vector3D operator/(double scalar, const Vector3D& rhs)
	{
		return rhs / scalar;
	}

	bool operator==(const Vector3D& lhs, const Vector3D& rhs)
	{
		return lhs.X == rhs.X && lhs.Y == rhs.Y && lhs.Z == rhs.Z;
	}

	bool operator>(const Vector3D& lhs, const Vector3D& rhs)
	{
		return lhs.Size() > rhs.Size();
	}

	bool operator>=(const Vector3D & lhs, const Vector3D & rhs)
	{
		return lhs.Size() >= rhs.Size();
	}

	bool operator<(const Vector3D& lhs, const Vector3D& rhs)
	{
		return lhs.Size() < rhs.Size();
	}

	bool operator<=(const Vector3D& lhs, const Vector3D& rhs)
	{
		return lhs.Size() <= rhs.Size();
	}

	Vector3D CrossProduct(const Vector3D& lhs, const Vector3D& rhs)
	{
		return Vector3D(lhs.Y * rhs.Z - lhs.Z * rhs.Y, lhs.Z * rhs.X - lhs.X * rhs.Z, lhs.X * rhs.Y - lhs.Y * rhs.X);
	}
}
