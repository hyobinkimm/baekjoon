#include <iostream>
using namespace std;

int N; int sum;
int minimum = 1000001;
bool isit = false;

int main() {
	cin >> N;

	// ������ + �� �ڸ� �� = N
	for (int i = 1; i <= N; i++) {
		sum += i; // ������
		sum += (i / 1000000) + 
			((i % 1000000) / 100000) + 
			((i % 100000) / 10000) + 
			((i % 10000) / 1000) + 
			((i % 1000) / 100) + 
			((i % 100) / 10) + 
			(i % 10); // �� �ڸ� ���� ��
		// ���� �����հ� ���� ���� ���� �����ڸ� ���ؾ��ϹǷ�
		if ((sum == N) && (i < minimum)) { isit = true; minimum = i; }
		sum = 0;
	}
	if (isit == true)	cout << minimum;
	else cout << 0; // �����ڰ� ���� ���
}