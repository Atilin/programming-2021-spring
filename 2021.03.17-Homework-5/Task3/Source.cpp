#include <iostream>
#include <vector>
#include <clocale>
#include <algorithm>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	cout << "������� �������� � ������ �������? ";
	int n;
	cin >> n;
	cout << "������� �������� ������� ������� ";
	vector <int> a;
	for (int i = 0; i < n; ++i)
	{
		int x;
		cin >> x;
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	cout << endl;

	cout << "������� �������� �� ������ �������? ";
	int m;
	cin >> m;
	cout << "������� �������� ������� ������� ";
	vector <int> b;
	for (int i = 0; i < m; ++i)
	{
		int x;
		cin >> x;
		b.push_back(x);
	}
	sort(b.begin(), b.end());

	vector <int> c;
	int ind1 = 0;
	int ind2 = 0;
	while (ind1 < n && ind2 < m)
	{
		if (a[ind1] < b[ind2])
		{
			c.push_back(a[ind1]);
			ind1++;

		}
		if (a[ind1] > b[ind2])
		{
			c.push_back(b[ind2]);
			ind2++;
		}
		if (a[ind1] == b[ind2])
		{

			c.push_back(a[ind1]);
			c.push_back(b[ind2]);
			ind1++;
			ind2++;
		}
	}
	while (ind1 < n)
	{
		c.push_back(a[ind1]);
		ind1++;
	}
	while (ind2 < m)
	{
		c.push_back(b[ind2]);
		ind2++;
	}

	for (int i = 0; i < n + m; ++i)
	{
		cout << c[i] << ' ';
	}

	return 0;
}