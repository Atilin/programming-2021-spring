#include <iostream>

using namespace std;

int checkInput(int argc, char* argv[])
{
	if (argc != 7)
	{
		cout << "Wrong input1!" << endl;
		//return 0;
	}

	bool op1 = 0, op2 = 0, op = 0;
	unsigned int ind_op1 = 0, ind_op2 = 0, ind_op = 0;

	for (int i = 1; i <= argc; ++i)
	{
		if (argv[i] == "--operand1")
		{
			if (op1 == 1)
			{
				cout << "Wrong input2!" << endl;
				//return 0;
			}
			op1 = 1;
			ind_op1 = i;
			cout << "op1 = 1\n";
		}
		if (argv[i] == "--operand2")
		{
			if (op2 == 1)
			{
				cout << "Wrong input3!" << endl;
				//return 0;
			}
			op2 = 1;
			ind_op2 = i;
			cout << "op2 = 1\n";
		}
		if (argv[i] == "--operator")
		{
			if (op == 1)
			{
				cout << "Wrong input4!" << endl;
				//return 0;
			}
			op = 1;
			ind_op = i;
			cout << "op = 1\n";
		}
	}
	if (op1 == 0 || op2 == 0 || op == 0)
	{
		cout << op1 << ' ' << op2 << ' ' << op << endl;
		cout << "Wrong input5!" << endl;
		//return 0;
	}
	if ((ind_op1 + ind_op2 + ind_op) != (1 + 3 + 5))
	{
		cout << "Wrong input6!" << endl;
		//return 0;
	}
	return 0;
}

int main(int argc, char* argv[])
{
	checkInput(argc, argv);



	/*for (int j = 1; j <= argc; ++j)
	{
		int number1 = 0;
		bool flag = 0;
		int degree = 0;
		int i = 0;
		for (int i = 0; i <= strlen(argv[1]); ++i);
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