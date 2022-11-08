#include <iostream>
using namespace std;

// 0 : white, 1 : blue

int N; int A[129][129];
int white, blue;

void cut(int x, int y, int n) {
	int color = A[x][y]; // �� ������ color�� ����
	bool diff = false;

	// ������ �������� ��� ���� ������ �Ǻ�
	for (int i = x; i <= x + n-1; i++) {
		for (int j = y; j <= y + n-1; j++) {
			if (color != A[i][j]) { // ���� �ٸ��ٸ� 
				diff = true; // ����������
				break;
			}
		}
		if (diff) break;
	}

	if (diff) { // ���� ���� �ȿ��� �ٸ��ٸ�
		// �� �ɰ���
		cut(x, y, n / 2); // 1���� (���� ��)
		cut(x + n / 2, y, n / 2); // 2���� (������ ��)
		cut(x, y + n / 2, n / 2); // 3���� (���� �Ʒ�)
		cut(x + n / 2, y + n / 2, n / 2); // 4���� (������ �Ʒ�)
	}
	else {
		if (color == 0) white++;
		else blue++;
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> A[i][j];
		}
	}

	cut(1, 1, N);

	printf("%d\n%d", white, blue);
}