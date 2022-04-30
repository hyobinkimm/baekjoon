#include <iostream>
#include <cmath>
using namespace std;

/*
1. Ʋ�ȴ� ��
- vector�� �̿��Ͽ� ��ġ�� ��� ����ϸ� �ð��ʰ�
- ���ʿ� �ð� ���⵵�� 2^n�̶� �ٷιٷ� ����ؾ���
*/

// A B C

// ���� ��������
// n���� ������ ũ�� �κκ����� ������
// 1. �� �κ� : ���� �Ʒ��� �ִ� ���� ū ���� �ϳ�
// 2. ������ �κ� : �� �κ��� ������ 2~n�� ���ݵ�

// �׷��� ������ 2���� ��ó�� �ذ���
// 1. 2~n�� ���ݵ�(from)�� C(temp)�� �̿��Ͽ� �߰� �ܰ� B(to)�� �ű��
// 2. ���� �Ʒ��� �ִ� ���� ū ����(from)�� C(to)�� �ű��
// 3. B�� �ִ� ����(from)�� A(temp)�� �̿��Ͽ� C(to)�� �ű��.

int N; int cnt; // cnt�� ���⼭ �ʿ����� ������ ���� �̵� Ƚ���� ��Ÿ��

void moveHanoi(int from, int temp, int to, int n) {
	if (n == 1) {
		cnt++;
		printf("%d %d\n", from, to);
	}
	else {
		moveHanoi(from, to, temp, n - 1); // 1�� �ܰ�
		cnt++;
		printf("%d %d\n", from, to);
		moveHanoi(temp, from, to, n - 1); // 3�� �ܰ�
	}
}


int main() {
	cin >> N;
	
	cout << int(pow(2, N) - 1) << endl;
	moveHanoi(1, 2, 3, N);
}