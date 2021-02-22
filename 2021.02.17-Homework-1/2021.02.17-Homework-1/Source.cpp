#include <iostream>
#include <clocale>
using namespace std;

void printBits(int a)
{
	int bitlength = sizeof(a) * 8;
	for (int i = 0; i < bitlength; ++i)
	{                                      //  часть алгоритма при i=1:
		unsigned int bit = a;              //  100000011111  переходит в
		bit = bit << i;					   // 100000011111х (перва€ единичка отрезаетс€ т.к. не входит в инт) х - кака€-то цифра котора€ нам не важна
		bit = bit >> (bitlength - 1);	   //  000000000001  сдвиг на 31 бит вправо (это число в дес€тич записи = 1)
		cout << bit;
	}
}

void printBits(long l)
{
	int bitlength = sizeof(l) * 8;
	for (int i = 0; i < bitlength; ++i)
	{
		unsigned long bit = l;
		bit = bit << i;
		bit = bit >> (bitlength - 1);
		cout << bit;
	}
}

void printBits(long long ll)
{
	int bitlength = sizeof(ll) * 8;
	for (int i = 0; i < bitlength; ++i)
	{
		unsigned long long bit = ll;
		bit = bit << i;
		bit = bit >> (bitlength - 1);
		cout << bit;
	}
}

void printBits(float f)
{
	void* ptr; //создаем указатель
	ptr = &f;  //присваиваем указателю адрес элемента f
	printBits(*((int*)ptr)); //приводим элемент p к типу указател€ на int (т.к. размеры void и int одинаковы) и разадресуем - 
							 //получаем элемент типа int из побитовой записи числа f. ѕереводим это число в побитовую запись
}

void printBits(double d)
{
	void* ptr;
	ptr = &d;
	printBits(*((long long*)ptr));
}

void printBits(long double ld)
{
	void* ptr;
	ptr = &ld;
	long long* ptr2 = ((long long*)ptr);//привели указатель ptr к типу указател€ на ll и приравн€ли его к ptr2
	printBits(*ptr2); //написали первые 8 байтов;
	ptr2++;//сдвигаем указатель на следующие 8 байт
	if (sizeof(ld) == 12)
	{
		int* ptr3 = (int*)ptr2;
		printBits(*ptr2);
	}
	else if (sizeof(ld) == 16)
	{
		printBits(*ptr2);
	}
	
}

int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "¬ведите число типа int: ";
	int a = 0;
	cin >> a;
	cout << "„исло в побитовом представлении: ";
	printBits(a);
	cout << endl << endl;

	cout << "¬ведите число типа long: ";
	long l = 0;
	cin >> l;
	cout << "„исло в побитовом представлении: ";
	printBits(l);
	cout << endl << endl;

	cout << "¬ведите число типа long long: ";
	long long ll = 0;
	cin >> ll;
	cout << "„исло в побитовом представлении: ";
	printBits(ll);
	cout << endl << endl;

	cout << "¬ведите число типа float: ";
	float f = 0;
	cin >> f;
	cout << "„исло в побитовом представлении: ";
	printBits(f);
	cout << endl << endl;

	cout << "¬ведите число типа double: ";
	double d = 0;
	cin >> d;
	cout << "„исло в побитовом представлении: ";
	printBits(d);
	cout << endl << endl;

	cout << "¬ведите число типа long double: ";
	long double ld = 0;
	cin >> ld;
	cout << "„исло в побитовом представлении: ";
	printBits(ld);
	cout << endl << endl;

	return 0;
}