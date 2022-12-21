#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void CreateBIN(char* fname) // ��������� ����� ������� � �������� �����
{
	ofstream fout(fname, ios::binary); // ������� ���� ��� ������
	char ch; // ������� ����������� � �� ������������ ��������
	string s; // �������� ������������ �����
	do
	{
		cin.get(); // ������� ����� ��������� � ��� �� ���� �������
		cin.sync(); // "����� �����", ���� ��������� ���� ����� �����
		cout << "enter line: "; getline(cin, s); // ����� �����
		for (unsigned i = 0; i < s.length(); i++) // ������� �������� �����
			fout.write((char*)&s[i], sizeof(s[i])); // �������� ������ � ����
		cout << "continue? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
	fout.close();
}
void PrintBIN(char* fname) // ��������� ����� �� �����
{
	ifstream fin(fname, ios::binary); // ������� ���� ��� ����������
	char c; // ���������� ������
	while (fin.read((char*)&c, sizeof(c))) // ���� ����� ��������� ������
	{
		cout << c << endl; // �������� ���� �� �����
	}
	cout << endl;
	fin.close();
}
int ProcessBIN1(char* fname, char* gname) // ���������� �� ����� f
{ // � ���� g �������-�����
	ifstream f(fname, ios::binary); // ������� ���� ��� ����������
	ofstream g(gname, ios::binary); // ������� ���� ��� ������
	char c; // ���������� ������
	int b=0;
	while (f.read((char*)&c, sizeof(c))) // ���� ����� ��������� ������
	{
		if (c != -93 && c != -91 && c != -83 && c != -84 && c != -30 && c != -32 && c != 63 && c != -17 && c!= -82) // ���� ������ �� ������� �� ����� ��������
		{
			b++;
			g.write((char*)&c, sizeof(c)); // �������� ���� � ���� g
		}

	}
	f.close();
	g.close();
	return b;
}

int main()
{
	// binary files
	char fname[100]; // ��'� ������� �����
	cout << "enter file name 1: "; cin >> fname;
	CreateBIN(fname); // ����� ����� ����� � ���������
	char gname[100]; // ��'� ������� �����
	cout << "enter file name 2: "; cin >> gname;
	ProcessBIN1(fname, gname);
	PrintBIN(gname); // ������ ���� ������� ����� �� �����
	return 0;
}
