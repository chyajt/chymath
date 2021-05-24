#pragma once

#include <vector>

namespace chymath
{
	class Matrix
	{
	public:
		Matrix(int row, int column) : Row(row), Column(column)
		{
			Mtrx.reserve(row);

			for (auto r : Mtrx)
			{
				r.reserve(column);
			}
		}

		Matrix(const std::vector<std::vector<int>>& mtrx) : Row(mtrx.size()), Column(mtrx[0].size()), Mtrx(mtrx) {}

		Matrix& operator+=(const Matrix& rhs)
		{
			for (int i = 0; i < Row; ++i)
			{
				for (int j = 0; j < Column; ++j)
				{
					Mtrx[i][j] += rhs.Mtrx[i][j];
				}
			}

			return *this;
		}

		Matrix& operator-=(const Matrix& rhs)
		{
			for (int i = 0; i < Row; ++i)
			{
				for (int j = 0; j < Column; ++j)
				{
					Mtrx[i][j] -= rhs.Mtrx[i][j];
				}
			}

			return *this;
		}

		Matrix& operator*=(double scalar)
		{
			for (int i = 0; i < Row; ++i)
			{
				for (int j = 0; j < Column; ++j)
				{
					Mtrx[i][j] *= scalar;
				}
			}

			return *this;
		}

		int Row;
		int Column;
		std::vector<std::vector<int>> Mtrx;
	};

	Matrix operator+(const Matrix& lhs, const Matrix& rhs)
	{
		return const_cast<Matrix&>(lhs) += rhs;
	}

	Matrix operator-(const Matrix& lhs, const Matrix& rhs)
	{
		return const_cast<Matrix&>(lhs) -= rhs;
	}

	Matrix operator*(const Matrix& lhs, double scalar)
	{
		return const_cast<Matrix&>(lhs) *= scalar;
	}
}
