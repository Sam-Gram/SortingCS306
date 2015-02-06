#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

void random(int r[], int n, int m, int seed, int a, int b)
{
	r[0] = seed;
	for (int i = 1; i <= n; i++)
	{
		r[i] = (a * r[i-1] + b) % m;
		if (r[i] < 0)
			r[i] *= -1;
	}
}

void swap(int array[], int pos1, int pos2)
{
	int value1 = array[pos1];
	int value2 = array[pos2];
	array[pos1] = value2;
	array[pos2] = value1;
	return;
}

void selectionSort(int array[], int size)
{
	int min;
	
	for (int i = 0; i <= size - 2; i++)
	{
		min = i;
		for (int j = i + 1; j <= size - 1; j++)
		{
			if (array[j] < array[min])
				min = j;
			swap(array, i, min);
		}
	}
	return;
}

int main()
{
	const int n = 100;
	int array[n];
	int m = pow(2, 64);
	int seed = time(0);
	int a = 0.33 * m;
	int b = 1;
	random(array, n, m, seed, a, b);
	
	selectionSort(array, n);
	
	for (int i = 0; i < 100; i++)
		cout << i << " " << array[i] << endl;
	return 0;
}