constexpr int m = 3;
constexpr int n = 3;

int A[m][n] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
int B[m][n] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };

int main()
{
	int C[m][n]; //result

	for (size_t i = 0; i < m; i++)
	{
		for (size_t j = 0; j < n; j++)
		{
			C[i][j] = A[i][j] + B[i][j];
		}
	}

	return 0;
}
	