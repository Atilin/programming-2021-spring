#include <iostream>

using namespace std;

int checkInput(int argc, char* argv[])
{
	if (argc != 7) // проверка на кол-во параметров
	{
		cout << "Wrong input1!" << endl;
		//return 0;
	}

	bool op1 = 0, op2 = 0, op = 0; //индикатор присутствия параметра operand1,2 и operator
	unsigned int ind_op1 = 0, ind_op2 = 0, ind_op = 0; //индексы параметров operand1,2 и operator

	for (int i = 1; i <= argc; ++i)
	{
		if (argv[i] == "--operand1") //проверка на присутствие параметр
		{
			if (op1 == 1) //если такой параметр уже был
			{
				cout << "Wrong input2!" << endl;
				//return 0;
			}
			op1 = 1;
			ind_op1 = i;

			cout << "check: op1 = 1\n";
		}
		if (argv[i] == "--operand2") //проверка на присутствие параметра
		{
			if (op2 == 1) //если такой параметр уже был
			{
				cout << "Wrong input3!" << endl;
				//return 0;
			}
			op2 = 1;
			ind_op2 = i;

			cout << "check: op2 = 1\n";
		}
		if (argv[i] == "--operator") //проверка на присутствие оператора
		{
			if (op == 1) //если такой оператор уже был
			{
				cout << "Wrong input4!" << endl;
				//return 0;
			}
			op = 1;
			ind_op = i;

			cout << "check: op = 1\n";
		}
	}
	if (op1 == 0 || op2 == 0 || op == 0)  //все ли из параметров присутствуют
	{
		cout << op1 << ' ' << op2 << ' ' << op << endl;
		cout << "Wrong input5!" << endl;
		//return 0;
	}
	if ((ind_op1 + ind_op2 + ind_op) != (1 + 3 + 5)) //контрольные суммы: проверка, что op1,op2,op занимают 1-ую, 3-ю и 5-ую позиции
	{
		cout << "Wrong input6!" << endl;
		//return 0;
	}
	return 0;
}

void toNumber(char* argv[], int j)
{
	int number1 = 0; //финальное число
	bool flag = 0; // индикатор точки
	int degree = 0; // степень десятки, на которую поделим число

	cout << "check: strlen(argv[j]) = " << strlen(argv[j]) << endl;

	for (int i = 0; i <= strlen(argv[j]); ++i);
	{
		if (flag == 1) //счетчик кол-ва цифр после запятой
		{
			degree++;
		}
		if (argv[j][i] == '.') //индикатор точки
		{
			flag = 1;
		}
		else //перевод строки в число
		{
			number1 *= 10;
			number1 += argv[j][i] - 48;
		}

		cout << "check: number1 = " << number1 << endl;

	}
	if (flag == 1) //если число дробное, переводим в дабл и делим на 10^degree
	{
		number1 = (double)number1 / pow(10, degree);
	}
	cout << "check: number1 = " << number1 << endl;
	return number1;
}

int main(int argc, char* argv[])
{
	checkInput(argc, argv);

	toNumber(argv, 2);

	/*for (int j = 1; j <= argc; ++j)
	{
		int number1 = 0;
		bool flag = 0;
		int degree = 0;
		int i = 0;
		for (int i = 0; i < strlen(argv[1]); ++i);
		{
			if (argv[1][i] == '.')
			{
				flag = 1;
			}
			else
			{
				number1 *= 10;
				number1 += argv[1][i] - 48;
			}
			if (flag == 1)
			{
				degree++;
			}

		}
		if (flag == 1)
		{
			number1 = (double)number1 / pow(10, degree);
		}
		cout << number1 << endl;
	}*/

	cout << "argc: " << argc << endl;
	for (int i = 0; i < argc; ++i)
	{
		cout << i << ' ' << argv[i] << endl;
	}
	return 0;
}