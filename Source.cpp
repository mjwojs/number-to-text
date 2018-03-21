#include <iostream>
#include <string>
#include <cstring>
#include <map>
#include <cstdlib>

using namespace std;

int main()
{
	map<unsigned long long int, string> num;

	num[0] = "";
	num[1] = "jeden";
	num[2] = "dwa";
	num[3] = "trzy";
	num[4] = "cztery";
	num[5] = "piec";
	num[6] = "szesc";
	num[7] = "siedem";
	num[8] = "osiem";
	num[9] = "dziewiec";
	num[10] = "dziesiec";
	num[11] = "jedenascie";
	num[12] = "dwanascie";
	num[13] = "trzynascie";
	num[14] = "czternascie";
	num[15] = "pietnascie";
	num[16] = "szesnascie";
	num[17] = "siedemnascie";
	num[18] = "osiemnascie";
	num[19] = "dziewietnascie";
	num[20] = "dwadziescia";
	num[30] = "trzydziesci";
	num[40] = "czterdziesci";
	num[50] = "piecdziesiat";
	num[60] = "szescdziesiat";
	num[70] = "siedemdziesiat";
	num[80] = "osiemdziesiat";
	num[90] = "dziewiecdziesiat";
	num[100] = "sto";
	num[200] = "dwiescie";
	num[300] = "trzysta";
	num[400] = "czterysta";
	num[500] = "piecset";
	num[600] = "szescset";
	num[700] = "siedemset";
	num[800] = "osiemset";
	num[900] = "dziewiecset";

	int tt;
	unsigned long long int a, x, t1, it, s;
	char arr[20];

	cin >> tt;

	while (tt--)
	{
		cin >> arr;
		x = strlen(arr);
		a = atoi(arr);

		if (x == 13)
		{
			cout << num[1] << " " << "bln." << endl;
			continue;
		}

		if (x == 1 && arr[0] == '0')
		{
			cout << "zero\n";
			continue;
		}

		t1 = x;

		if (x % 3 == 1)
		{
			while (true)
			{
				arr[t1 + 1] = arr[t1 - 1];
				--t1;

				if (t1 == 0)
				{
					break;
				}
			}

			arr[0] = '0';
			arr[1] = '0';
			x += 2;
		}
		else if (x % 3 == 2)
		{
			while (true)
			{
				arr[t1] = arr[t1 - 1];
				--t1;

				if (t1 == 0)
				{
					break;
				}
			}

			arr[0] = '0';
			++x;
		}
		//cout << arr << endl << endl;

		it = 0;
		t1 = x;
		s = 0;

		if (x % 3 == 0)
		{
			while (true)
			{
				s = 0;

				cout << num[(arr[it] - 48) * 100];
				if ((arr[it] - 48) * 100 != 0)
				{
					cout << " ";
				}


				s += (arr[it] - 48) * 100;

				if (arr[it + 1] == '1')
				{
					cout << num[(arr[it + 2] - 38)];
					s += (arr[it + 2] - 38);
					if ((arr[it + 2] - 38) != 0)
					{
						cout << " ";
					}

				}
				else
				{
					cout << num[(arr[it + 1] - 48) * 10];
					if ((arr[it + 1] - 48) * 10 != 0)
					{
						cout << " ";
					}
					cout << num[(arr[it + 2] - 48)];
					s += (arr[it + 1] - 48) * 10;
					s += (arr[it + 2] - 48);
					if ((arr[it + 2] - 48) != 0)
					{
						cout << " ";
					}
				}


				if (t1 == 12 && s != 0)
				{
					cout << "mld. ";
				}
				else if (t1 == 9 && s != 0)
				{
					cout << "mln. ";
				}
				else if (t1 == 6 && s != 0)
				{
					cout << "tys. ";
				}

				it += 3;
				t1 -= 3;

				if (it >= x)
				{
					break;
				}
			}
		}


		cout << endl;
		memset(arr, 0, 15 * sizeof(char));

	}

	num.clear();

	return 0;
}