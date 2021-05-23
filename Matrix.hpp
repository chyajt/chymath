#pragma once

#include <vector>

namespace chymath
{
	class Matrix
	{
	public:
		Matrix(int row, int column) : Row(row), Column(column) {}

		int Row;
		int Column;
		std::vector<std::vector<int>> Mtrx;
	};
}
