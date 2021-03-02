#include <iostream>

using namespace std;

bool checkInput(int argc, char* argv[], int& ind_op1, int& ind_op2, int& ind_op)
{
	if (argc != 7) // �������� �� ���-�� ����������
	{
		cout << "Wrong input1!" << endl;
		return false;
	}

	bool op1 = 0, op2 = 0, op = 0; //��������� ����������� ��������� operand1,2 � operator

	for (int i = 1; i < argc; ++i)
	{
		if (strcmp(argv[i], "--operand1") == 0) //�������� �� ����������� ��������
		{
			if (op1 == 1) //���� ����� �������� ��� ���
			{
				cout << "Wrong input2!" << endl;
				return false;
			}
			op1 = 1;
			ind_op1 = i;
			//cout << "check: op1 = 1\n";
		}
		if (strcmp(argv[i], "--operand2") == 0)  //�������� �� ����������� ���������
		{
			if (op2 == 1) //���� ����� �������� ��� ���
			{
				cout << "Wrong input3!" << endl;
				return false;
			}
			op2 = 1;
			ind_op2 = i;
			//cout << "check: op2 = 1\n";
		}
		if (strcmp(argv[i], "--operator") == 0)  //�������� �� ����������� ���������
		{
			if (op == 1) //���� ����� �������� ��� ���
			{
				cout << "Wrong input4!" << endl;
				return false;
			}
			op = 1;
			ind_op = i;
			//cout << "check: op = 1\n";
		}
	}
	if (op1 == 0 || op2 == 0 || op == 0)  //��� �� �� ���������� ������������
	{
		cout << op1 << ' ' << op2 << ' ' << op << endl;
		cout << "Wrong input5!" << endl;
		return false;
	}
	if ((ind_op1 + ind_op2 + ind_op) != (1 + 3 + 5)) //����������� �����: ��������, ��� op1,op2,op �������� 1-��, 3-� � 5-�� �������
	{
		cout << "Wrong input6!" << endl;
		return false;
	}
	return true;
}

double toDouble(char* argv[], int j)
{
	double number = 0; //��������� �����
	bool flag = false; // ��������� �����
	int degree = 0; // ������� �������, �� ������� ������� �����

	for (int i = 0; i < strlen(argv[j]); ++i)
	{
		if (flag == true) //������� ���-�� ���� ����� �������
		{
			degree++;
		}
		if (argv[j][i] == '.') //��������� �����
		{
			flag = true;
		}
		else //������� ������ � �����
		{
			number *= 10;
			number += argv[j][i] - 48;
		}

		//cout << "check: number1 = " << number << endl;

	}
	number = number / (double)pow(10, degree);
	//cout << "check: number1 = " << number << endl;
	return number;
}

int toInt(char* argv[], int j)
{
	int number = 0; //��������� �����

	for (int i = 0; i < strlen(argv[j]); ++i)
	{
		number *= 10;
		number += argv[j][i] - 48;

		//cout << "check: number1 = " << number << endl;
	}
	return number;
}

int main(int argc, char* argv[])
{
	int ind_op1 = 0, ind_op2 = 0, ind_op = 0; //������� ���������� operand1,2 � operator
	if (checkInput(argc, argv, ind_op1, ind_op2, ind_op) == false)
	{
		return 0;
	}

	for (int i = 0; i < strlen(argv[ind_op1 + 1]); ++i)
	{
		if (argv[ind_op1 + 1][i] == '.')
		{
			double number1 = toDouble(argv, ind_op1 + 1);
			break;
		}
		if (i == strlen(argv[ind_op1 + 1]) - 1)
		{
			int number1 = toInt(argv, ind_op1 + 1);
		}
	}


	//cout << number1 << ' ' << number2 << endl;

	cout << "argc: " << argc << endl;
	for (int i = 0; i < argc; ++i)
	{
		cout << i << ' ' << argv[i] << endl;
	}
	return 0;
}