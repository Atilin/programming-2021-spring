#include <iostream>
#include <vector>
using namespace std;

void extremum(vector <int> a, int n, int& max, int& min)
{
	for (int i = 1; i < n; ++i)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}
}

void counting_sort(vector <int>& a, int n)
{
	int max = a[0];
	int min = a[0];
	extremum(a, n, max, min);

	int* b = new int[max - min + 1]{ 0 };

	for (int i = 0; i < n; ++i)
	{
		b[a[i] - min]++;
	}

	int k = 0;
	for (int i = 0; i < max - min + 1; i++)
	{
		while (b[i] > 0)
		{
			a[k] = i + min;
			k++;
			b[i]--;
		}
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

	counting_sort(a, n);

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << ' ';
	}
	return 0;
}