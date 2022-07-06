constexpr size_t m = 3;
constexpr size_t n = 3;
constexpr size_t p = 3;

int C[m][n];
int A[m][n] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
int B[m][n] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

int main()
{
	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < p; j++)
		{
			C[i][j] = 0;
			for (size_t k = 0; k < n; k++)
			{
				C[i][j] += A[i][k] * B[k][j];
			}
		}
	}
	return 0;
}