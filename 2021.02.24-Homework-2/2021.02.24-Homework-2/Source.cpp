#include <iostream>

using namespace std;

bool checkInput(int argc, char* argv[], int& ind_op1, int& ind_op2, int& ind_op)
{
	if (argc != 7) // проверка на кол-во параметров
	{
		cout << "Wrong input1!" << endl;
		return false;
	}

	bool op1 = 0, op2 = 0, op = 0; //индикатор присутствия параметра operand1,2 и operator

	for (int i = 1; i < argc; ++i)
	{
		if (strcmp(argv[i], "--operand1") == 0) //проверка на присутствие параметр
		{
			if (op1 == 1) //если такой параметр уже был
			{
				cout << "Wrong input2!" << endl;
				return false;
			}
			op1 = 1;
			ind_op1 = i;
			//cout << "check: op1 = 1\n";
		}
		if (strcmp(argv[i], "--operand2") == 0)  //проверка на присутствие параметра
		{
			if (op2 == 1) //если такой параметр уже был
			{
				cout << "Wrong input3!" << endl;
				return false;
			}
			op2 = 1;
			ind_op2 = i;
			//cout << "check: op2 = 1\n";
		}
		if (strcmp(argv[i], "--operator") == 0)  //проверка на присутствие оператора
		{
			if (op == 1) //если такой оператор уже был
			{
				cout << "Wrong input4!" << endl;
				return false;
			}
			op = 1;
			ind_op = i;
			//cout << "check: op = 1\n";
		}
	}
	if (op1 == 0 || op2 == 0 || op == 0)  //все ли из параметров присутствуют
	{
		cout << op1 << ' ' << op2 << ' ' << op << endl;
		cout << "Wrong input5!" << endl;
		return false;
	}
	if ((ind_op1 + ind_op2 + ind_op) != (1 + 3 + 5)) //контрольные суммы: проверка, что op1,op2,op занимают 1-ую, 3-ю и 5-ую позиции
	{
		cout << "Wrong input6!" << endl;
		return false;
	}
	return true;
}

bool isDouble(char* argv[], int ind_operand)
{
	for (int i = 0; i < strlen(argv[ind_operand]); ++i)
	{
		if (argv[ind_operand][i] == '.')
		{
			return true;
		}
	}
	return false;
}

double toDouble(char* argv[], int j)
{
	double number = 0;
	bool flag = false;
	int degree = 0;

	for (int i = 0; i < strlen(argv[j]); ++i)
	{
		if (flag == true)
		{
			degree++;
		}
		if (argv[j][i] == '.')
		{
			flag = true;
		}
		else
		{
			number *= 10;
			number += argv[j][i] - 48;
		}
	}
	number = number / (double)pow(10, degree);
	return number;
}

int toInt(char* argv[], int j)
{
	int number = 0;

	for (int i = 0; i < strlen(argv[j]); ++i)
	{
		number *= 10;
		number += argv[j][i] - 48;
	}
	return number;
}

template<typename T1, typename T2>
T1 sum(T1 a, T2 b)
{
	return a + b;
}

template<typename T1, typename T2>
T1 diff(T1 a, T2 b)
{
	return a - b;
}

template<typename T1, typename T2>
T1 mult(T1 a, T2 b)
{
	return a * b;
}

template<typename T1, typename T2>
T1 div(T1 a, T2 b)
{
	return a / b;
}

template<typename T1, typename T2>
T1 mod(T1 a, T2 b)
{
	if (a < b)
		return a;
	else
	{
		while (a > b)
			a -= b;
		return a;
	}
}

template<typename T1, typename T2>
T1 calculate(T1 a, T2 b, char operation)
{
	switch (operation)
	{
	case '+':
	{
		return sum(a, b);
		break;
	}
	case '-':
	{
		return diff(a, b);
		break;
	}
	case '/':
	{
		return div(a, b);
		break;
	}
	case '*':
	{
		return mult(a, b);
		break;
	}
	case '%':
	{
		return mod(a, b);
		break;
	}
	return 0;
	}
}

int main(int argc, char* argv[])
{
	int ind_op1 = 0, ind_op2 = 0, ind_op = 0; //индексы параметров operand1,2 и operator
	if (checkInput(argc, argv, ind_op1, ind_op2, ind_op) == false)
	{
		return 0;
	}

	double number1 = isDouble(argv, ind_op1 + 1) ? toDouble(argv, ind_op1 + 1) : toInt(argv, ind_op1 + 1);
	double number2 = isDouble(argv, ind_op2 + 1) ? toDouble(argv, ind_op2 + 1) : toInt(argv, ind_op2 + 1);
	char operation = argv[ind_op + 1][0];

	cout << number1 << ' ' << operation << ' ' << number2 << " = " << calculate(number1, number2, operation) << endl;
	
	return 0;
}