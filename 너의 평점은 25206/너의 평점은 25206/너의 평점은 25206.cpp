#include <iostream>
#include <string>
#include <map>
using namespace std;

map<string, float> m;

// �������� = sum(����*��������)/����

float total_b;
float sum;

int main() {
	m["A+"] = 4.5;	m["A0"] = 4.0;	m["B+"] = 3.5;	m["B0"] = 3.0;
	m["C+"] = 2.5;	m["C0"] = 2.0;	m["D+"] = 1.5;	m["D0"] = 1.0;	m["F"] = 0.0;

	while (1) {
		string line;
		getline(cin, line);
		if (line == "")break;
		int space = 0; float b = 0;
		for (int i = 0; i < line.size(); i++) {
			if (line[i] == ' ') {
				space++; // ���� ����
				if (space == 1) { // ���� ����
					b = stof(line.substr(i + 1, 3));
				}
				if (space == 2) { // ����*�������� ���
					if (line.substr(i + 1) == "P") break; // P�� ��꿡 �ݿ�X
					total_b += b;
					sum += b * m[line.substr(i + 1)];
				}
			}
		}
	}

	cout << sum / total_b;
}