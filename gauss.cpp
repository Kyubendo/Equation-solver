#include<iostream>
#include<ctime>

using namespace std;

int main()
{
	int size;
	cout << "Enter the number of equations: ";
	cin >> size;
	cout << endl;
	double **arr = new double*[size + 1];
	for (int i = 0; i < size + 1; i++)
	{
		arr[i] = new double[size];
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size + 1; j++)
		{
			if (j == size)
			{
				cout << "Enter an absolute term: ";
				cin >> arr[i][j];
			}
			else
			{
				cout << "Enter a coefficient of the x" << j + 1 << ": ";
				cin >> arr[i][j];
			}
		}
		cout << endl;
	}
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size + 1; j++)
		{
			cout << arr[i][j] << "  ";
		}
		cout << endl;
	}

	int t = clock();
	cout << (float)t / CLOCKS_PER_SEC << endl;

	for (int z = 0; z < size + 1; z++)
	{
		for (int i = z + 1; i < size; i++)
		{
			double temp = arr[i][z] / arr[z][z];

			for (int k = 0; k < size + 1; k++)
			{
				arr[i][k] -= arr[z][k] * temp;
			}
		}
	}


	double *Xs = new double[size];
	for (int i = 0; i < size; i++)
	{
		Xs[i] = 0;
	}

	Xs[size - 1] = arr[size - 1][size] / arr[size - 1][size - 1];

	for (int i = size - 2; i >= 0; i--)
	{
		double temp = 0;
		for (int j = i + 1; j < size; j++)
		{
			temp -= Xs[j] * arr[i][j];
			Xs[i] = (arr[i][size] + temp) / arr[i][i];
		}
	}
	t = clock();
	cout << (float)t / CLOCKS_PER_SEC << endl;
	for (int i = 0; i < size; i++)
	{
		cout << Xs[i] << endl;
	}

	system("pause");
}
