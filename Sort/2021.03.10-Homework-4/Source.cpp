#include<iostream>
#include<clocale>

using namespace std;

void swap(int& a, int& b);
void fillArray(int* a, int len);
void inputArray(int* a, int len);
void printArray(int* a, int len);
void mixArray(int* a, int len);
bool isSorted(int* a, int len, bool ascending = true);
void bubbleSort(int* a, int len, int& comparisonBubble, int& permutationBubble);
void insertionSort(int* a, int len, int& comparisonInsertion, int& permutationInsertion);
void selectionSort(int* a, int len, int& comparisonSelection, int& permutationSelection);
void fillAscending(int* a, int len);
void fillDescending(int* a, int len);

int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "1 - заполнить массив по возрастанию" << endl;
	cout << "2 - заполнить массив по убыванию" << endl;
	cout << "3 - заполнение случайными цифрами" << endl;
	int flag = -1;
	cin >> flag;

	for (int len = 5; len <= 20; len += 5)
	{
		cout << "=============== len = " << len << " ===============" << endl;

		int comparisonBubble = 0;
		int permutationBubble = 0;

		int comparisonInsertion = 0;
		int permutationInsertion = 0;

		int comparisonSelection = 0;
		int permutationSelection = 0;

		int* a = new int[len];
		for (int i = 0; i < 1000; ++i)
		{
			if (flag == 1)
			{
				fillAscending(a, len);
			}
			else if (flag == 2)
			{
				fillDescending(a, len);
			}
			else
			{
				fillArray(a, len);
			}
			bubbleSort(a, len, comparisonBubble, permutationBubble);
		}
		cout << endl << "BUBBLESORT"<<endl << endl;
		cout << "Cреднее количество сравнений = " << comparisonBubble / 1000 << endl;
		cout << "среднее количество перестановок = " << permutationBubble / 1000 << endl;

		for (int i = 0; i < 1000; ++i)
		{
			if (flag == 1)
			{
				fillAscending(a, len);
			}
			else if (flag == 2)
			{
				fillDescending(a, len);
			}
			else
			{
				fillArray(a, len);
			}
			insertionSort(a, len, comparisonInsertion, permutationInsertion);
		}
		cout << endl << endl << "INSERTIONSORT" << endl << endl;
		cout << "Cреднее количество сравнений = " << comparisonInsertion / 1000 << endl;
		cout << "среднее количество перестановок = " << permutationInsertion / 1000 << endl;

		for (int i = 0; i < 1000; ++i)
		{
			if (flag == 1)
			{
				fillAscending(a, len);
			}
			else if (flag == 2)
			{
				fillDescending(a, len);
			}
			else
			{
				fillArray(a, len);
			}
			selectionSort(a, len, comparisonSelection, permutationSelection);
		}
		cout << endl << endl << "SELECTIONSORT" << endl << endl;
		cout << "Cреднее количество сравнений = " << comparisonSelection / 1000 << endl;
		cout << "среднее количество перестановок = " << permutationSelection / 1000 << endl;

		delete[] a;

		cout << endl << endl << endl;
	}
	return 0;
}

void swap(int& a, int& b)
{
	int c = a;
	a = b;
	b = c;
}

void fillArray(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		a[i] = rand() % 90 + 10;
	}
}

void inputArray(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		cin >> a[i];
	}
}

void printArray(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
}

void mixArray(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		swap(a[i], a[rand() % len]);
	}
}

bool isSorted(int* a, int len, bool ascending)
{
	for (int i = 0; i < len - 1; ++i)
	{
		// 1 2 3 4 5 3
		if (a[i] > a[i + 1] == ascending) // проверяет 1 2: один больше двух? false != true (ascending == true)
		{								  // ...
			return false;				  // проверяет 5 3: пять больше трех? true == true --> return false;
		}
	}
	return true;
}

void bubbleSort(int* a, int len, int& comparisonBubble, int& permutationBubble)
{
	//cout << endl;
	for (int i = 0; i < len - 1; ++i)
	{
		for (int j = 0; j < len - i - 1; ++j)
		{
			if (a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				//printArray(a, len);
				permutationBubble++;
			}
			comparisonBubble++;
		}
	}
	//cout << endl;
}

void insertionSort(int* a, int len, int& comparisonInsertion, int& permutationInsertion)
{
	for (int i = 1; i < len; ++i)
	{
		int t = a[i];
		int j = i;
		while (j > 0 && a[j - 1] > t)
		{
			comparisonInsertion++;
			a[j] = a[j - 1];
			permutationInsertion++;
			--j;
		}
		a[j] = t;
		permutationInsertion++;
		//printArray(a, len);
	}
}

void selectionSort(int* a, int len, int& comparisonSelection, int& permutationSelection)
{
	for (int i = 0; i < len - 1; ++i)
	{
		int index = i;
		for (int j = i + 1; j < len; ++j)
		{
			if (a[j] < a[index])
			{
				index = j;
			}
			comparisonSelection++;
		}
		swap(a[i], a[index]);
		permutationSelection++;
		//printArray(a, len);
	}
}

void fillAscending(int* a, int len)
{
	for (int i = 0; i < len; ++i)
	{
		a[i] = i;
	}
}
void fillDescending(int* a, int len)
{
	for (int i = len; i > 0; --i)
	{
		a[len - i] = i;
	}
}