#include <iostream>
using namespace std;

int X;
// 64 32 16 8 4 2 1
// 23 = 16 + 4 + 2 + 1 => 4��
// 48 : 32 + 16 => 2��
int cnt;

int main(){
	cin >> X;

	int cur = 64; // 64���� �ɰ��� ����
	while (1) {		
		if (cur > X) { // ���ϴ� ������ ���� ũ��
			cur /= 2; // ������ �ɰ���
		}
		else {
			if (X - cur >= 0) { // cur(cm)�� ������ X�� ������ �� �ִٸ�
				X = X - cur; // cur(cm) ���ְ�
				cnt++; // Ƚ�� ����
			}
		}
		if (X == 0) break; // ������ �Ϸ������ while�� Ż��
	}
	cout << cnt; // Ƚ�� ���
}