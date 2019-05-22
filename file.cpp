#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int size1 = 0, size2 = 0, m = 1;
	string name1, name2, tx;
	string temp1, temp2;
	ofstream file1;
	ofstream file2;
	ifstream file11;
	ifstream file22;
	cout << "Введите имя 1 файла\n";
	cin >> name1;
	cout << "\nВведите имя 2 файла\n";
	cin >> name2;
	
	name1 = name1+".txt";
	name2 = name2+".txt";
	file1.open(name1, ios::app);
	file1.close();
	file2.open(name2, ios::app);
	file2.close();
	file1.open(name1, ios::app);
	cout << "\nВведите содержимое 1 файла\n";
	while (m != 2) {
		std::cin.ignore();
		std::getline(std::cin, temp1);
		file1 << temp1 << '\n';
		cout << "Продолжить?\n1.Да\n2.Нет\n";
		cin >> m;
	}
	file1.close();
	m = 1;
	file2.open(name2, ios::app);
	cout << "\nВведите содержимое 2 файла\n";
	while (m != 2) {
		std::cin.ignore();
		std::getline(std::cin, temp2);
		file2 << temp2 << '\n';
		cout << "Продолжить?\n1.Да\n2.Нет\n";
		cin >> m;
	}
	file2.close();
 	file11.open(name1);
	file22.open(name2);
	while (!file11.eof()) {
		getline(file11, temp1, '\n');
		size1++;
	}
	size1--;
	while (!file22.eof())
	{
		getline(file22, temp2, '\n');
		size2++;
	}
	size2--;
	file11.close();
	file22.close();
	file11.open(name1);
	file22.open(name2);
	while (!file11.eof() && !file22.eof()) {
		getline(file11, temp1, '\n');
		getline(file22, temp2, '\n');
		if (temp1.size() != temp2.size()) {
			cout << temp1 << "||" << temp2 << '\n';
		}
		if (temp1.size() == temp2.size()) {
			for (int i = 0; i < temp1.size(); i++) {
				if (temp1[i] != temp2[i]) {
					m = 1;
				}
			}
			if (m == 1) {
				cout << temp1 << "||" << temp2 << '\n';
			}
		}
		m = 0;
	}
	file11.close();
	file22.close();
	file11.open(name1);
	file22.open(name2);
}