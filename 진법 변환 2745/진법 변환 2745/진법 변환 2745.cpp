#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int B;
string N;

int main() {
	cin >> N >> B;

	int sum = 0;
	for (int i = N.length() - 1; i >= 0; i--) {
		if (N[i] >= 65) {
			// ���ĺ��ΰ��
			// A�� �ƽ�Ű�ڵ� : 65, A�� 10���� : 10
			sum += (N[i] - 55) * pow(B, (N.length() - 1) - i);
		}
		else {
			// ������ ���
			sum += (N[i] - '0') * pow(B, (N.length() - 1) - i);
		}
	}

	cout << sum;
}