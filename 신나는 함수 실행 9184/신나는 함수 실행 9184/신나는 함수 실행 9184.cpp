#include <iostream>
using namespace std;

int a, b, c, aa, bb, cc;
int w[21][21][21];

int W(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) {
		return 1; // a,b,c �� �ϳ��� 0���� ������ 1
	}
	if (a > 20 || b > 20 || c > 20) { 
		return W(20, 20, 20); // a,b,c �� �ϳ��� 20���� ũ�� W(20,20,20) ȣ��
	}

	if (w[a][b][c])return w[a][b][c]; // ���� ä�����ִٸ� �ٷ� ��ȯ. �� �ڵ� ������ �ð� �ʰ�. dp(�ߺ��� ���� ������� ����)

	if (a < b && b < c) { // a<b<c���
		w[a][b][c] = W(a, b, c - 1) + W(a, b - 1, c - 1) - W(a, b - 1, c); // ���� ��ä�����ִٸ� ��͸� �̿��Ͽ� �� �Ʒ��� ������ �ҷ���
	}
	else {
		w[a][b][c] = W(a - 1, b, c) + W(a - 1, b - 1, c) + W(a - 1, b, c - 1) - W(a - 1, b - 1, c - 1);
	}
	return w[a][b][c];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	while (1) {
		cin >> a >> b >> c;
		if (a == -1 && b == -1 && c == -1) break;

		printf("w(%d, %d, %d) = %d\n", a, b, c, W(a,b,c));
	}

}