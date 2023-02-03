#include <iostream>
using namespace std;

int N; int A[2188][2188];
int C[3]; // 0 : -1�� ����, 1 : 0�� ����, 2 : 1�� ����

void f(int r, int c, int order) {	
	bool isCorrect = true; 
	int flag = A[r][c];
	for (int i = r; i <= r + order - 1; i++) {
		for (int j = c; j <= c + order - 1; j++) {
			if (A[i][j] != flag) {
				// ���̰� ��� ���� ���� �ƴ϶��
				isCorrect = false;
				break;
			}
		}
		if (!isCorrect) break;
	}

	if (isCorrect) {
		C[flag + 1]++;
	}
	else {
		if (order == 1) return; // �� �̻� �ɰ� �� �����Ƿ� ��
		order = order / 3; // 3���� ������ �Ȱ��� ũ���� ���簢�� 9���� �ڸ� �� ����

		f(r, c, order);
		f(r, c + order, order);
		f(r, c + 2 * order, order);

		f(r + order, c, order);
		f(r + order, c + order, order);
		f(r + order, c + 2 * order, order);

		f(r + 2 * order, c, order);
		f(r + 2 * order, c + order, order);
		f(r + 2 * order, c + 2 * order, order);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}

	f(1, 1, N);

	for (int i = 0; i < 3; i++) {
		cout << C[i] << "\n";
	}
}