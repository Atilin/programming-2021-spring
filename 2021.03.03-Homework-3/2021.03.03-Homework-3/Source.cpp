#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{
	ifstream fin("in.txt");
	while (!fin.eof()) // �� ��� ���, ���� ���� �� ����������
	{
		string s;
		fin >> s;
		cout << s;
		system("pause");
	}
	fin.close();




	return 0;
}