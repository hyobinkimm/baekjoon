#include <iostream>
using namespace std;

int N, F;
int minimum = 2147483647; // �ִ�� ����. �̰� ������ Ʋ��

int main() {
	cin >> N >> F;

	int temp = N - N % 100; // ���� �ڸ� ���ϸ� ��� 0���� ���� ���� ����
	while (1) {
		if (temp % F == 0) { // ������ ��������
			minimum = (temp < minimum) ? temp : minimum;
			if (temp >= N) break; // temp�� N���� Ŀ���� �ּڰ��� �߻����� �����Ƿ� break
		}
		temp++;
	}

	printf("%02d", minimum % 100); // %02d�� 2�ڸ��� 0���� ������
}