#include <iostream>
using namespace std;

int N;
char A[3072][6143];

void star(int x, int y, int exponent) {
	if (exponent < 1) { // ���� ���� �ﰢ���� �Ǹ�
		A[y][x] = '*';
		A[y + 1][x - 1] = '*'; A[y + 1][x + 1] = '*';
		for (int i = x - 2; i <= x + 2; i++) A[y + 2][i] = '*';
		return;
	}
	int p = 1; exponent--; // ���� ����
	for (int i = 0; i < exponent; i++) {
		p = p << 1; // 2^exponent�� p�� ����
	}
	star(x, y, exponent); // ��
	star(x - 3 * p, y + 3 * p, exponent); // ����
	star(x + 3 * p, y + 3 * p, exponent); // ������
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	
	int a = N / 3;
	int q = 1;
	for (int i = 0;; i++) {
		if (q == a) { a = i; break; }
		q = q << 1; // 2��
	}
	star(N - 1, 0, a);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 2 * N - 1; j++) {
			if (A[i][j] == '*') printf("*");
			else printf(" ");
		}
		printf("\n");
	}
}