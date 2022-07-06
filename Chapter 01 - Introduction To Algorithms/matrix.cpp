#include <iostream>

constexpr size_t m = 5;
constexpr size_t n = 5;

int A[m][n];

int main()
{
	/* Въвеждане по редове */
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			std::cin >> A[i][j];
		}
	}


	/* Въвеждане по стълбове */
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			std::cin >> A[j][i];
		}
	}


	/* Отпечатване на матрица по редове */
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			std::cout << A[i][j] << " ";
		}
		std::cout << std::endl;;
	}

	return 0;
}
