#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

void random(unsigned long long r[], int n, unsigned long long m,
	 			unsigned long long seed, unsigned long long a,
				unsigned long long b)
{
	r[0] = seed;
	for (int i = 1; i <= n; i++)
		r[i] = (a * r[i-1] + b) % m;
}

void selectionSort(unsigned long long array[], int n)
{
	int min;
	unsigned long long temp;
	
	for (int i = 0; i < n - 1; i++)
	{
		min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		temp = array[i];
		array[i] = array[min];
		array[min] = temp;
	}
	return;
}

bool checkSorted(unsigned long long array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (array[i] > array[i+1] && i != n - 1)
			return false;
	}
	return true;
}

void displayArray(unsigned long long array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << i << " " << array[i] << endl;
	}
}

void findMisfits(unsigned long long array[], int n)
{
	for (int i = 0; i < n; i++)
	{
		if (array[i] <= array[i+1] || i == n - 1)
			cout << i << " " << array[i] << endl;
		else
			cout << i << " " << array[i] << " MISFIT" << endl;
	}
}

int main()
{
	const unsigned long long n = 10000;
	unsigned long long array[n];
	unsigned long long m = pow(2, 32);
	unsigned long long seed = time(0);
	unsigned long long a = 0.33 * m;
	unsigned long long b = 1;
	random(array, n, m, seed, a, b);
	
	selectionSort(array, n);
	
	if (checkSorted(array, n))
		cout << "Sort successful." << endl;
	else
	{
		cout << "ERROR: Sort failed." << endl;
		findMisfits(array, n);
	}
	
	return 0;
}