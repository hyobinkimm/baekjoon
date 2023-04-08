#include <iostream>
#include <deque>
#include <cmath>
using namespace std;

struct tobni {
	deque<int> wheel;
};

struct tobni tobni[5];
int K;

// ���������� ȸ�����Ѷ�

void turn(struct tobni& tobni, int dir) {
	if (dir == 1) {
		// �ð� �����̶��
		int tmp = tobni.wheel.back();
		tobni.wheel.push_front(tmp);
		tobni.wheel.pop_back();
	}
	else if (dir == -1) {
		// �ݽð� �����̸�
		int tmp = tobni.wheel.front();
		tobni.wheel.push_back(tmp);
		tobni.wheel.pop_front();
	}
	// dir = 0 : ȸ�� X
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	for (int i = 1; i <= 4; i++)
	{
		string x;
		cin >> x;
		for (int j = 0; j < 8; j++) {
			tobni[i].wheel.push_back(x[j] - '0'); // ascii �ڵ� ����
		}
	}

	cin >> K;
	int dirr[5];
	for (int i = 0; i < K; i++)
	{
		int num, dir;
		cin >> num >> dir; // ��ȣ, ���� �Է¹���

		for (int i = 0; i < 5; i++) { dirr[i] = 0; } // ���� �ʱ�ȭ
		dirr[num] = dir; // �������� ��Ϲ��� �̸� ����

		if (num == 1) { // 1��		
			for (int j = 1; j <= 3; j++) { // 3�� -> 2�� -> 1�� ��Ϲ��� ������ �˻�
				if (tobni[j].wheel.at(2) != tobni[j + 1].wheel.at(6))
					dirr[j + 1] = (dirr[j] == 1) ? -1 : 1;
				else break;
			}			
		}
		else if (num == 2) { // 2��
			// ����
			if (tobni[num - 1].wheel.at(2) != tobni[num].wheel.at(6)) { 
				// 1�� ��Ϲ��� �˻�
				dirr[num - 1] = (dirr[num] == 1) ? -1 : 1;
			}
			// ������
			for (int j = 2; j <= 3; j++) { // 3�� -> 4�� ��Ϲ��� ������ �˻�
				if (tobni[j].wheel.at(2) != tobni[j + 1].wheel.at(6))
					dirr[j + 1] = (dirr[j] == 1) ? -1 : 1;
				else break;
			}
		}
		else if (num == 3) { // 3��
			// ������
			if (tobni[num].wheel.at(2) != tobni[num + 1].wheel.at(6)) {
				// 4�� ��Ϲ��� �˻�
				dirr[num + 1] = (dirr[num] == 1) ? -1 : 1;
			}
			// ����
			for (int j = 3; j >= 2; j--) { // 2�� -> 1�� ��Ϲ��� ������ �˻�
				if (tobni[j - 1].wheel.at(2) != tobni[j].wheel.at(6))
					dirr[j - 1] = (dirr[j] == 1) ? -1 : 1;
				else break;
			}

		}
		else { // 4��
			for (int j = 4; j >= 2; j--) { // 3�� -> 2�� -> 1�� ��Ϲ��� ������ �˻�
				if (tobni[j-1].wheel.at(2) != tobni[j].wheel.at(6))
					dirr[j - 1] = (dirr[j] == 1) ? -1 : 1;
				else break;
			}
		}
		for (int j = 1; j <= 4; j++) turn(tobni[j], dirr[j]); // �ϰ� ȸ��
	}

	int sum = 0;
	for (int i = 1; i <= 4; i++) {
		sum += tobni[i].wheel.at(0) * pow(2, i - 1);
	}

	cout << sum;
}