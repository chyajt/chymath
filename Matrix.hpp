#pragma once

#include <vector>

namespace chymath
{
	class Matrix
	{
	public:
		Matrix(int row, int column) : Row(row), Column(column), Mtrx(row, std::vector<int>(column)) {}
		Matrix(const std::vector<std::vector<int>>& mtrx) : Row(mtrx.size()), Column(mtrx[0].size()), Mtrx(mtrx) {}

		Matrix& operator=(const Matrix& rhs)
		{
			Row = rhs.Row;
			Column = rhs.Column;
			Mtrx = rhs.Mtrx;

			return *this;
		}

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

		Matrix& operator/=(double scalar)
		{
			for (int i = 0; i < Row; ++i)
			{
				for (int j = 0; j < Column; ++j)
				{
					Mtrx[i][j] /= scalar;
				}
			}

			return *this;
		}

		static const Matrix& Transposed(const Matrix& matrix)
		{
			Matrix transposed(matrix.Column, matrix.Row);

			for (int i = 0; i < transposed.Column; ++i)
			{
				for (int j = 0; j < transposed.Row; ++j)
				{
					transposed.Mtrx[i][j] = matrix.Mtrx[j][i];
				}
			}

			return transposed;
		}

		int Row;
		int Column;
		std::vector<std::vector<int>> Mtrx;
	};

	class SquareMatrix : public Matrix
	{
	public:
		SquareMatrix(int size) : Matrix(size, size) {}
		SquareMatrix(std::vector<std::vector<int>> matrix) : Matrix(matrix) {}

		static const SquareMatrix& Inverse(const SquareMatrix& matrix)
		{
			SquareMatrix inverse(matrix.Row);

			for (int i = 0; i < inverse.Row; ++i)
			{
				for (int j = 0; j < inverse.Column; ++j)
				{
					inverse.Mtrx[i][j] = (i == j ? 1 / matrix.Mtrx[i][j] : 0);
				}
			}

			return inverse;
		}

		static const SquareMatrix& IdentityMatrix(int size)
		{
			SquareMatrix matrix(size);

			for (int i = 0; i < size; ++i)
			{
				matrix.Mtrx[i][i] = 1;
			}

			return matrix;
		}
	};

	Matrix operator+(const Matrix& lhs, const Matrix& rhs)
	{
		Matrix matrix(lhs.Row, lhs.Column);

		for (int i = 0; i < matrix.Row; ++i)
		{
			for (int j = 0; j < matrix.Column; ++j)
			{
				matrix.Mtrx[i][j] = lhs.Mtrx[i][j] + rhs.Mtrx[i][j];
			}
		}

		return matrix;
	}

	Matrix operator-(const Matrix& lhs, const Matrix& rhs)
	{
		Matrix matrix(lhs.Row, lhs.Column);

		for (int i = 0; i < matrix.Row; ++i)
		{
			for (int j = 0; j < matrix.Column; ++j)
			{
				matrix.Mtrx[i][j] = lhs.Mtrx[i][j] + rhs.Mtrx[i][j];
			}
		}

		return matrix;
	}

	Matrix operator*(const Matrix& lhs, double scalar)
	{
		Matrix matrix(lhs);

		for (int i = 0; i < matrix.Row; ++i)
		{
			for (int j = 0; j < matrix.Column; ++j)
			{
				matrix.Mtrx[i][j] *= scalar;
			}
		}

		return matrix;
	}

	Matrix operator*(double scalar, const Matrix& rhs)
	{
		return rhs * scalar;
	}

	Matrix operator*(const Matrix& lhs, const Matrix& rhs)
	{
		Matrix matrix(lhs.Mtrx.size(), rhs.Mtrx[0].size());

		for (int i = 0; i < lhs.Mtrx.size(); ++i)
		{
			for (int j = 0; j < rhs.Mtrx[0].size(); ++j)
			{
				for (int k = 0; k < lhs.Mtrx[0].size(); ++k)
				{
					matrix.Mtrx[i][j] += lhs.Mtrx[i][k] * rhs.Mtrx[k][j];
				}
			}
		}

		return matrix;
	}

	Matrix operator/(const Matrix& lhs, double scalar)
	{
		Matrix matrix(lhs);

		for (int i = 0; i < matrix.Row; ++i)
		{
			for (int j = 0; j < matrix.Column; ++j)
			{
				matrix.Mtrx[i][j] /= scalar;
			}
		}

		return matrix;
	}

	Matrix operator/(double scalar, const Matrix& rhs)
	{
		return rhs * scalar;
	}

	bool operator==(const Matrix& lhs, const Matrix& rhs)
	{
		return lhs.Mtrx == rhs.Mtrx;
	}

	bool operator!=(const Matrix& lhs, const Matrix& rhs)
	{
		return lhs.Mtrx != rhs.Mtrx;
	}
}
