#include <iostream>
#include <string>
using namespace std;

int N;
int A[65][65];

void f(int r, int c, int n) {
	int flag = A[r][c]; bool isCorrect = true;	
	for (int i = r; i <= r + n - 1; i++) {
		for (int j = c; j <= c + n - 1; j++) {
			if (A[i][j] != flag) { // ������ ��� ���� ���ڰ� �ƴ϶��
				isCorrect = false;
				break;
			}
		}
		if (!isCorrect) break;
	}

	if (isCorrect) {
		// �־��� ������ ��ȣ�� �� ��ġ�ϴ� ���
		cout << flag;
	}
	else {
		// �ɰ��ߵǴ� ���
		n /= 2;
		cout << "("; // ���� �κп� "(" ����
		f(r, c, n); // 1����
		f(r, c + n, n); // 2����
		f(r + n, c, n); // 3����
		f(r + n, c + n, n); // 4����
		cout << ")"; // �� �κп� ")" ����
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		string x;
		cin >> x;
		// ���ڿ� �ڸ���
		for (int k = 1; k <= N; k++) {
			A[i][k] = x[k - 1] - '0'; // ���ڷ� ��ȯ
		}
	}

	f(1, 1, N);
}