#include <iostream>
using namespace std;

char board[51][51];

int minimum = 51*51;
int cnt, cnt_;
int N, M;

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> board[i][j];
		}
	}

	// ���� ���� W��� ���� �� �ٲ�� �Ǵ� ���� ����
	// minimum�� �� �� ����
	// ���� ���� B��� ���� �� �ٲ�� �Ǵ� ���� ����
	// minimum�� �� �� ����
	// ü���� �ű�� �� �ݺ�

	for (int i = 1; i <= N - 7; i++) {
		for (int j = 1; j <= M - 7; j++) {
			cnt = 0; cnt_ = 0;
			
			// ���� ���� W
			for (int r = i; r <= i + 7; r++) {
				for (int c = j; c <= j + 7; c++) {
					if ((r + c) % 2 == 0) { // ���� �� + �� = ¦��
						if (board[r][c] != 'W')cnt++;
					}
					else { // ���� �� + �� = Ȧ��
						if (board[r][c] != 'B')cnt++;
					}
				}
			}
			if (cnt < minimum)
			{
				minimum = cnt;
			}

			// ���� ���� B
			for (int r = i; r <= i + 7; r++) {
				for (int c = j; c <= j + 7; c++) {
					if ((r + c) % 2 == 0/*i+j = ¦��*/) {
						if (board[r][c] != 'B')cnt_++;
					}
					else { // i+j = Ȧ��
						if (board[r][c] != 'W')cnt_++;
					}
				}
			}
			if (cnt_ < minimum) {
				minimum = cnt_;
			}
		}
	}

	cout << minimum;

}