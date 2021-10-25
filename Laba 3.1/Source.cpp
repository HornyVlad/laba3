#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//srand(time(NULL));
	int i, j, a[7][7];
	//scanf("%d %d", &i, &j);

	for (int n = 0; n < 7; n++)
	{
		for (int m = 0; m < 7; m++)
		{
			a[n][m] = rand() % 2;
			printf("%d", a[n][m]);
		}
		printf("\n");
	}

}
