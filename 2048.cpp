#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>

using namespace std;
int main()
{
	srand(time(0));
	int B = 0, b, g[25] = {0};
	char m;
	system("pause");
	system("cls");
	b = rand() % 16;
	g[b] = 2;
	while (1)
	{
		do
		{
			b = rand() % 16;
			if (g[0] != 0 && g[1] != 0 && g[2] != 0 && g[3] != 0 && g[4] != 0 && g[5] != 0 && g[6] != 0 && g[7] != 0 && g[8] != 0 && g[9] != 0 && g[10] != 0 && g[11] != 0 && g[12] != 0 && g[13] != 0 && g[14] != 0 && g[15] != 0)
			{
				cout << " \n\n\n\n\n\n\n\n              Game over";
				break;
			}
		} while (g[b] != 0);
		g[b] = 2;
		cout << "\n\n\n\n\n"
			 << "        -------------------------\n";
		for (int j = 0; j <= 12; j += 4)
		{
			cout << "        |";
			for (int k = j; k <= (j + 3); k++)
			{
				if (g[k] == 0)
				{
					cout << "     |";
				}
				if (g[k] < 10 && g[k] > 0)
				{
					cout << "  " << g[k] << "  |";
				}
				if (g[k] > 10 && g[k] < 100)
				{
					cout << "  " << g[k] << " |";
				}
				if (g[k] > 100 && g[k] < 1000)
				{
					cout << " " << g[k] << " |";
				}
				if (g[k] > 1000 && g[k] < 10000)
				{
					cout << " " << g[k] << "|";
				}
				if (g[k] > 10000 && g[k] < 100000)
				{
					cout << "" << g[k] << "|";
				}
			}
			cout << "\n        -------------------------\n";
		}
		char a = getch();

		switch (a)
		{
		case 'w':
			system("cls");
			for (int o = 1; o <= 3; o++)
			{
				for (int p = 15; p >= 4; p--)
				{
					if (g[p - 4] == g[p])
					{
						g[p - 4] += g[p];
						g[p] = 0;
					}
					if (g[p - 4] == 0)
					{
						g[p - 4] = g[p];
						g[p] = 0;
					}
				}
			}
			break;
		case 's':
			system("cls");
			for (int o = 1; o <= 3; o++)
			{
				for (int p = 0; p < 12; p++)
				{
					if (g[p] == g[p + 4])
					{
						g[p + 4] += g[p];
						g[p] = 0;
					}
					if (g[p + 4] == 0)
					{
						g[p + 4] = g[p];
						g[p] = 0;
					}
				}
			}
			break;
		case 'a':
			system("cls");
			for (int o = 1; o <= 3; o++)
			{
				for (int p = 15; p > 0; p--)
				{
					if (p % 4 != 0)
					{
						if (g[p] == g[p - 1])
						{
							g[p - 1] += g[p];
							g[p] = 0;
						}
						if (g[p - 1] == 0)
						{
							g[p - 1] = g[p];
							g[p] = 0;
						}
					}
				}
			}
			break;
		case 'd':
			system("cls");
			for (int o = 1; o <= 3; o++)
			{
				for (int p = 0; p < 16; p++)
				{
					if (p % 4 != 3)
					{
						if (g[p] == g[p + 1])
						{
							g[p + 1] += g[p];
							g[p] = 0;
						}
						if (g[p + 1] == 0)
						{
							g[p + 1] = g[p];
							g[p] = 0;
						}
					}
				}
			}
			break;
		}
	}
	return 0;
}
