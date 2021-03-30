#include <iostream>
#include <vector>
using namespace std;

void quicksort(vector <int>& a, int n)
{
	int i = 0;
	int j = n - 1;
	int mid = a[n / 2];
	do
	{
		while (a[i] < mid)
		{
			i++;
		}
		while (a[j] > mid)
		{
			j--;
		}

		if (i <= j)
		{
			int tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;

			i++;
			j--;
		}
	} while (i <= j);


	if (j > 0)
	{
		quicksort(a, j + 1);
	}
	if (i < n)
	{
		quicksort(a, n - i);
	}
}

int main()
{
	int n;
	cout << "vvedite kolichestvo simvolov ";
	cin >> n;
	cout << "vvedite elementy massiva ";
	vector <int> a;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		a.push_back(x);
	}

	quicksort(a, n);

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << ' ';
	}
	return 0;
}