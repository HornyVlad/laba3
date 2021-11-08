#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
using namespace std;

int main()
{
	int i, j, size, ** a, ** g, **A, m, n, ran;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	printf("Введите размеры массивов ");
	scanf_s("%d", &size);
	printf("Матрица смежности:\n");
	a = (int**)malloc(size * sizeof(int));
	g = (int**)malloc(size * sizeof(int));
	A = (int**)malloc((size * size) * sizeof(int));
	srand(time(NULL));

	for (i = 0; i < size; i++)
	{
		a[i] = (int*)malloc(size * sizeof(int));
		g[i] = (int*)malloc(size * sizeof(int));
	}
	for (i = 0; i < (size * size); i++)
	{
		A[i] = (int*)malloc((size * size) * sizeof(int));
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			a[i][j] = 0;
			g[i][j] = 0;
		}
	}
	for (i = 0; i < (size * size); i++)
	{
		for (j = 0; j < (size * size); j++)
		{
			A[i][j] = 0;
		}
	}
	for (i = 0; i < size; i++)
	{
		for (j = 1 + i; j < size; j++)
		{
			ran = rand() % 101;
			if (ran > 50) a[i][j] = 1;
			else a[i][j] = 0;
		}
	}
	for (i = 0; i < size; i++)
	{
		for (j = 1 + i; j < size; j++)
		{
			ran = rand() % 101;
			if (ran > 50) g[i][j] = 1;
			else g[i][j] = 0;
		}
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			a[j][i] = a[i][j];
			g[j][i] = g[i][j];
		}
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n"); 
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			printf("%d ", g[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	for (m = 0; m < size; m++)
	{
		for (i = size*m; i < size + size*m; i++)//строка
		{
			for (n = 0; n < size; n++)
			{
				for (j = size*n; j < size + size*n; j++)//столбец
				{
					if ((m == n) && (i == j)) 
						A[i][j] = 0;
					if ((m == n) && (i != j))
						A[i][j] = g[i - size * m][j - size * n];
					if ((m != n) && (i - size * m == j - size * n))
						A[i][j] = a[m][n];
					if ((m != n) && (i - size * m != j - size * n))
						A[i][j] = 0;
				}
			}
		}
	}



	for (i = 0; i < (size * size); i++)
	{
		for (j = 0; j < (size * size); j++)
		{
			printf("%d ", A[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}