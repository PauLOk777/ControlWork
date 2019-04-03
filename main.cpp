#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string ParseInfo(string, string);

int main() {
	setlocale(LC_ALL, "rus");
	string buff_1, buff_2;
	ifstream fin("input.txt");
	if (!fin.is_open()) {
		cout << "Error" << endl;
		cin.get();
		exit(1);
	}
	getline(fin, buff_1);
	getline(fin, buff_2);

	string temp = "";
	temp += ParseInfo(buff_1, buff_2);
	cout << temp << endl;
	
	ofstream fout("output.txt");
	fout << temp;

	fin.close();
	fout.close();

	system("pause");
	return 0;
}

string ParseInfo(string buff_1, string buff_2) {
	string temp = "";
	int count_1 = 0;
	int count_2 = 0;
	int index = 0;
	bool flag = false;
	for (int i = 0; i < buff_2.length(); i+=2) {
		for (int j = 0; j < buff_1.length(); j++) {
			if (buff_2[i] == buff_1[j]) {
				count_1++;
			}
			if (buff_2[i + 1] == buff_1[j]) {
				count_2++;
			}
		}
		if (count_1 == count_2) {
			flag = true;
		}
		else {
			flag = false;
			break;
		}
		count_1 = 0;
		count_2 = 0;
	}
	if (flag) {
		temp += "Дужки збалансованi";
	}
	else {
		temp += "Дужки не збалансованi";
	}
	
	return temp;
}