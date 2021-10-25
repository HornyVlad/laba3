#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void otozhd(int size, int **a)
{
	int i, j, max, min, **g;
	g = (int**)malloc(size * sizeof(int));
	for (i = 0; i < size; i++)
	{
		g[i] = (int*)malloc(size * sizeof(int));
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			g[i][j] = 0;
		}
	}
	printf("\n");
	printf("Укажите max: ");
	scanf_s("%d", &max);
	printf("Укажите min: ");
	scanf_s("%d", &min);
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if ((i < max) && (j < max)) g[i][j] = a[i][j];
			if ((i < max) && (j == max)) g[i][min] += a[i][j];
			if ((i > max) && (j == max)) g[i - 1][min] += a[i][j];
			if ((i == max) && (j < max)) g[min][j] += a[i][j];
			if ((i == max) && (j > max)) g[min][j - 1] += a[i][j];
			if ((i < max) && (j > max)) g[i][j - 1] = a[i][j];
			if ((j < max) && (i > max)) g[i - 1][j] = a[i][j];
		}
	}
	for (i = max + 1; i < size; i++)
	{
		for (j = max + 1; j < size; j++)
		{
			g[i - 1][j - 1] = a[i][j];
		}
	}

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (g[i][j] > 1) g[i][j] = 1;
		}
	}
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			printf("%d ", g[i][j]);
		}
		printf("\n");
	}
}

void styag(int size, int** a)
{
	int razn, i, j, min, max, **g;
	g = (int**)malloc(size * sizeof(int));
	for (i = 0; i < size; i++)
	{
		g[i] = (int*)malloc(size * sizeof(int));
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			g[i][j] = 0;
		}
	}
	i = 0; j = 0;
	while (a[i][j] == 0)
	{
		printf("Укажите адрес строки: ");
		scanf_s("%d", &i);
		printf("Укажите адрес столбца: ");
		scanf_s("%d", &j);
		printf("\n");
		if (a[i][j] == 0) printf("Некоректный ввод\n");
	}
	if (i > j)
	{
		max = i;
		min = j;
	}
	else
	{
		max = j;
		min = i;
	}
	razn = max - min;
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if ((i < max) && (j < max)) g[i][j] = a[i][j];
			if ((i < min) && (j == max)) g[i][min] += a[i][j];
			if (((i > max) && (j == max)) && (i != min)) g[i - 1][min] += a[i][j];
			if ((i == max) && (j < min)) g[min][j] += a[i][j];
			if (((i == max) && (j > max)) && (j != min)) g[min][j - 1] += a[i][j];
			if ((i < max) && (j > max)) g[i][j - 1] = a[i][j];
			if ((j < max) && (i > max)) g[i - 1][j] = a[i][j];
		}
	}
	for (i = max + 1; i < size; i++)
	{
		for (j = max + 1; j < size; j++)
		{
			g[i - 1][j - 1] = a[i][j];
		}
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if (g[i][j] > 1) g[i][j] = 1;
		}
	}
	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - 1; j++)
		{
			printf("%d ", g[i][j]);
		}
		printf("\n");
	}
}

void raschep(int size, int** a)
{
	int razn, i, j, num, **g, sizeg;
	sizeg = size + 1;
	g = (int**)malloc(sizeg * sizeof(int));
	for (i = 0; i < sizeg; i++)
	{
		g[i] = (int*)malloc(sizeg * sizeof(int));
	}
	for (i = 0; i < sizeg; i++)
	{
		for (j = 0; j < sizeg; j++)
		{
			g[i][j] = 0;
		}
	}
	printf("\n");
	printf("Укажите столбец, который хотите расщепить: ");
	scanf_s("%d", &num);
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			if ((i <= num) && (j <= num)) g[i][j] = a[i][j];
			if ((i >= num) && (j <= num)) g[i + 1][j] = a[i][j];
			if ((j >= num) && (i <= num)) g[i][j + 1] = a[i][j];
			if (((i >= num) && (j <= num)) && ((i != num) && (j != num))) g[i + 1][j] = a[i][j];
			if (((j >= num) && (i <= num)) && ((i != num) && (j != num))) g[i][j + 1] = a[i][j];
			if (((i == num + 1) && (j == num)) || ((i == num) && (j == num + 1)))  g[i][j] = 1;
		}
	}
	for (i = num; i < size; i++)
	{
		for (j = num; j < size; j++)
		{
			g[i + 1][j + 1] = a[i][j];
		}
	}
	for (i = 0; i < sizeg; i++)
	{
		for (j = 0; j < sizeg; j++)
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
	int i, j, **a, max, **g, size, min, type;
	printf("Укажите размер матрицы: ");
	scanf_s("%d", &size);
	a = (int**)malloc(size * sizeof(int));
	//srand(time(NULL));
	for (i = 0; i < size; i++)
	{
		a[i] = (int*)malloc(size * sizeof(int));
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			a[i][j] = 0;
		}
	}
	for (i = 0; i < size; i++)
	{
		for (j = 1 + i; j < size; j++)
		{
			a[i][j] = rand() % 2;
		}
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			a[j][i] = a[i][j];
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
	printf("Выберите тип унарной операции \n1 - отождествление \n2 - стягивание \n3 - расщепление\n");
	scanf_s("%d", &type);
	printf("\n");
	switch (type)
	{
	case 1: otozhd(size, a);
		break;
	case 2: styag(size, a);
		break;
	case 3: raschep(size, a);
		break;
	}
}