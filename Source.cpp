#include <iostream>
#include <fstream>
#include <string>
using namespace std;
void CreateBIN(char* fname) // створення файлу символів з введених рядків
{
	ofstream fout(fname, ios::binary); // відкрили файл для запису
	char ch; // відповідь користувача – чи продовжувати введення
	string s; // введений користувачем рядок
	do
	{
		cin.get(); // очищуємо буфер клавіатури – щоб не було символу
		cin.sync(); // "кінець рядка", який залишився після вводу числа
		cout << "enter line: "; getline(cin, s); // ввели рядок
		for (unsigned i = 0; i < s.length(); i++) // скануємо введений рядок
			fout.write((char*)&s[i], sizeof(s[i])); // записали символ у файл
		cout << "continue? (y/n): "; cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	cout << endl;
	fout.close();
}
void PrintBIN(char* fname) // виведення файлу на екран
{
	ifstream fin(fname, ios::binary); // відкрили файл для зчитування
	char c; // прочитаний символ
	while (fin.read((char*)&c, sizeof(c))) // поки можна прочитати символ
	{
		cout << c << endl; // виводимо його на екран
	}
	cout << endl;
	fin.close();
}
int ProcessBIN1(char* fname, char* gname) // переписати із файлу f
{ // у файл g символи-цифри
	ifstream f(fname, ios::binary); // відкрили файл для зчитування
	ofstream g(gname, ios::binary); // відкрили файл для запису
	char c; // прочитаний символ
	int b=0;
	while (f.read((char*)&c, sizeof(c))) // поки можна прочитати символ
	{
		if (c != -93 && c != -91 && c != -83 && c != -84 && c != -30 && c != -32 && c != 63 && c != -17 && c!= -82) // якщо символ не входить до слова геометрія
		{
			b++;
			g.write((char*)&c, sizeof(c)); // записуємо його у файл g
		}

	}
	f.close();
	g.close();
	return b;
}

int main()
{
	// binary files
	char fname[100]; // ім'я першого файлу
	cout << "enter file name 1: "; cin >> fname;
	CreateBIN(fname); // ввели рядки файлу з клавіатури
	char gname[100]; // ім'я другого файлу
	cout << "enter file name 2: "; cin >> gname;
	ProcessBIN1(fname, gname);
	PrintBIN(gname); // вивели вміст першого файлу на екран
	return 0;
}
