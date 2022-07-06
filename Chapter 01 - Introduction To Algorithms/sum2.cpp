int a[n];

int sum(void)
{
	int s = 0;
	for (size_t i = 0; i < n; i++)
	{
		s += a[i];
	}
		
	return s;
}
