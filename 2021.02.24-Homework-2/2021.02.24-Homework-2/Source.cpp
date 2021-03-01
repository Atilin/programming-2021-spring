#include <iostream>

using namespace std;

//int resolveOpNumber(char op);
template<class T1, class T2> //��������� ��� ���������� ��� ������������ ��������
T1 sum(T1 a, T2 b)
{
	return a + b;
}

template<class T1, class T2>
T1 diff(T1 a, T2 b)
{
	return a - b;
}

template<class T1, class T2>
T1 div(T1 a, T2 b)
{
	return a / b;
}

template<class T1, class T2>
T1 mod(T1 a, T2 b)
{
	return a % b;
}

template<class T1, class T2>
T1 mult(T1 a, T2 b)
{
	return a * b;
}

template<class T1, class T2>
T1(*op[5])(T1, T2) = { sum,diff,div,mod,mult };

template<class T1, class T2>
T1 calc(T1 a, T2 b, T1(*op)(T1, T2)) //T1 calc - ������� �������� ���� �1 //(*op) �������� �������
{
	switch (--operation)
	{
	case '+':
	{
		cout << a << " + " << b << " = " << sum(a, b);
		break;
	}
	case '-':
	{
		cout << a << " - " << b << " = " << diff(a, b);
		break;
	}
	case '/':
	{
		cout << a << " / " << b << " = " << div(a, b);
		break;
	}
	case '%':
	{
		cout << a << " % " << b << " = " << mod(a, b);
		break;
	}
	case '*':
	{
		cout << a << " * " << b << " = " << mult(a, b);
		break;
	}
	cout << "Wrong input" << endl;
	}
}

int main(int argc, char* argv[])
{
	cout << argv[0];


	return 0;
}