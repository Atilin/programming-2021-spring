#include <iostream>
#include <clocale>
using namespace std;

void printBits(int a)
{
	int bitlength = sizeof(a) * 8;
	for (int i = 0; i < bitlength; ++i)
	{                                      //  ����� ��������� ��� i=1:
		unsigned int bit = a;              //  100000011111  ��������� �
		bit = bit << i;					   // 100000011111� (������ �������� ���������� �.�. �� ������ � ���) � - �����-�� ����� ������� ��� �� �����
		bit = bit >> (bitlength - 1);	   //  000000000001  ����� �� 31 ��� ������ (��� ����� � ������� ������ = 1)
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
	void* ptr; //������� ���������
	ptr = &f;  //����������� ��������� ����� �������� f
	printBits(*((int*)ptr)); //�������� ������� p � ���� ��������� �� int (�.�. ������� void � int ���������) � ����������� - 
							 //�������� ������� ���� int �� ��������� ������ ����� f. ��������� ��� ����� � ��������� ������
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
	long long* ptr2 = ((long long*)ptr);//������� ��������� ptr � ���� ��������� �� ll � ���������� ��� � ptr2
	printBits(*ptr2); //�������� ������ 8 ������;
	ptr2++;//�������� ��������� �� ��������� 8 ����
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

	cout << "������� ����� ���� int: ";
	int a = 0;
	cin >> a;
	cout << "����� � ��������� �������������: ";
	printBits(a);
	cout << endl << endl;

	cout << "������� ����� ���� long: ";
	long l = 0;
	cin >> l;
	cout << "����� � ��������� �������������: ";
	printBits(l);
	cout << endl << endl;

	cout << "������� ����� ���� long long: ";
	long long ll = 0;
	cin >> ll;
	cout << "����� � ��������� �������������: ";
	printBits(ll);
	cout << endl << endl;

	cout << "������� ����� ���� float: ";
	float f = 0;
	cin >> f;
	cout << "����� � ��������� �������������: ";
	printBits(f);
	cout << endl << endl;

	cout << "������� ����� ���� double: ";
	double d = 0;
	cin >> d;
	cout << "����� � ��������� �������������: ";
	printBits(d);
	cout << endl << endl;

	cout << "������� ����� ���� long double: ";
	long double ld = 0;
	cin >> ld;
	cout << "����� � ��������� �������������: ";
	printBits(ld);
	cout << endl << endl;

	return 0;
}