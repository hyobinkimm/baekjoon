#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

string input;

// -�� ������ �� �ڿ� ���� �͵� ���� ����� �ּڰ��� ���´�

int main() {
	cin >> input;

	int sum = 0;
	string temp = ""; // ���ڵ��� ����� �迭
	bool minus = false; // '-' ��ȣ�� �տ� �־����� ��� ����� �޶����� ������

	for (int i = 0; i < input.length() + 1; i++) {
		// �� �������� ���� ���ڵ� ó������ߵǱ� ������ ���� + 1 ��ŭ �ݺ�
		if (input[i] == '-' || input[i] == '+') { // ��ȣ�� ���
			if (minus == true) sum -= stoi(temp); // �տ� '-'�� �� ���� �ִٸ� ��ȣ�� �����ִٰ� �����ϰ� ���ش�
			else sum += stoi(temp); // �տ� '-'�� �� ���� �����Ƿ� �����ش�
			if (input[i] == '-') minus = true; // '-'�̸� minus�� true�� ������
			temp = ""; // �����ְų� ���־����Ƿ� temp �ʱ�ȭ
		}
		else if (input[i] == NULL) { // �� ������ ���ڸ� �ٷ��ִ� else if��
			if (minus == true) {
				sum -= stoi(temp);
			}
			else sum += stoi(temp);
		}
		else { // ������ ��
			temp += input[i];
		}
	}

	cout << sum;
}