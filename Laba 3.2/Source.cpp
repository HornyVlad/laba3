#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void objed(int size1, int size2, int size, int** g, int** a, int** b)
{
	int i, j;
	for (i = 0; i < size1; i++)
	{
		for (j = 0; j < size1; j++)
		{
			g[i][j] = g[i][j] + a[i][j];
		}
	}for (i = 0; i < size2; i++)
	{
		for (j = 0; j < size2; j++)
		{
			g[i][j] = g[i][j] + b[i][j];
		}
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (g[i][j] > 1) g[i][j] = 1;
		}
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			printf("%d ", g[i][j]);
		}
		printf("\n");
	}
}

void peres(int minsize, int size, int** g, int** a, int** b)
{
	int i, j;
	for (i = 0; i < minsize; i++)
	{
		for (j = 0; j < minsize; j++)
		{
			g[i][j] = a[i][j] * b[i][j];
		}
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			printf("%d ", g[i][j]);
		}
		printf("\n");
	}
}

void sum(int minsize, int size, int size1, int size2, int** g, int** a, int** b)
{
	int i, j;
	for (i = 0; i < minsize; i++)
	{
		for (j = 0; j < minsize; j++)
		{
			if ((a[i][j] == 1) && (b[i][j] == 1)) g[i][j] = 0;
			if ((a[i][j] == 1) && (b[i][j] == 0)) g[i][j] = 1;
			if ((a[i][j] == 0) && (b[i][j] == 1)) g[i][j] = 1;
		}
	}
	if (size1 > size2)
	{
		for (i = 0; i < size1; i++)
		{
			for (j = 0; j < size1; j++)
			{
				if (j >= size2) if ((a[i][j] == 1)) g[i][j] = 1;
				if (i >= size2) if ((a[i][j] == 1)) g[i][j] = 1;
			}
		}
	}
	else
	{
		for (i = 0; i < size2; i++)
		{
			for (j = 0; j < size2; j++)
			{
				if (j >= size1) if ((b[i][j] == 1)) g[i][j] = 1;
				if (i >= size1) if ((b[i][j] == 1)) g[i][j] = 1;
			}
		}
	}
	
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			printf("%d ", g[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setvbuf(stdin, NULL, _IONBF, 0);
	setvbuf(stdout, NULL, _IONBF, 0);
	int i, j, ** a, **b, max, ** g, size1, size2, size, minsize, min, razn, type;
	printf("Укажите размер 1-ой матрицы: ");
	scanf_s("%d", &size1);
	printf("Укажите размер 2-ой матрицы: ");
	scanf_s("%d", &size2);
	a = (int**)malloc(size1 * sizeof(int));
	b = (int**)malloc(size2 * sizeof(int));
	if (size1 > size2)
	{
		size = size1;
		minsize = size2;
	}
	else
	{
		size = size2;
		minsize = size1;
	}
	g = (int**)malloc(size * sizeof(int));
	//srand(time(NULL));
	for (i = 0; i < size1; i++)
	{
		a[i] = (int*)malloc(size1 * sizeof(int));
	}
	for (i = 0; i < size; i++)
	{
		g[i] = (int*)malloc(size * sizeof(int));
	}
	for (i = 0; i < size1; i++)
	{
		for (j = 0; j < size1; j++)
		{
			a[i][j] = 0;
		}
	}
	for (i = 0; i < size1; i++)
	{
		for (j = 1 + i; j < size1; j++)
		{
			a[i][j] = rand() % 2;
		}
	}
	for (i = 0; i < size1; i++)
	{
		for (j = 0; j < size1; j++)
		{
			a[j][i] = a[i][j];
		}
	}
	for (i = 0; i < size1; i++)
	{
		for (j = 0; j < size1; j++)
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
			g[i][j] = 0;
		}
	}


	//srand(time(NULL));
	for (i = 0; i < size2; i++)
	{
		b[i] = (int*)malloc(size2 * sizeof(int));
	}
	for (i = 0; i < size2; i++)
	{
		for (j = 0; j < size2; j++)
		{
			b[i][j] = 0;
		}
	}
	for (i = 0; i < size2; i++)
	{
		for (j = 1 + i; j < size2; j++)
		{
			b[i][j] = rand() % 2;
		}
	}
	for (i = 0; i < size2; i++)
	{
		for (j = 0; j < size2; j++)
		{
			b[j][i] = b[i][j];
		}
	}
	for (i = 0; i < size2; i++)
	{
		for (j = 0; j < size2; j++)
		{
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	printf("Выберите тип бинарной операции \n1 - объединение \n2 - пересечение \n3 - кольцевая сумма\n");
	scanf_s("%d", &type);
	printf("\n");
	switch (type)
	{
	case 1: objed(size1, size2, size, g, a, b);
		break;
	case 2: peres(minsize, size, g, a, b);
		break;
	case 3: sum(minsize, size, size1, size2, g, a, b);
		break;
	}
}