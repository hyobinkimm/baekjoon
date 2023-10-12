#include <iostream>
#include <cmath>
using namespace std;

int N;
int A[500][500]; // 500 500 error .. 

bool safe(int r, int c) {
	return 1 <= r && r <= N && 1 <= c && c <= N;
}

void spreadLeft(int r, int c, int y) {
	if (safe(r - 1, c)) {
		A[r - 1][c] += floor(y * 0.07);
	}
	if (safe(r - 2, c)) {
		A[r - 2][c] += floor(y * 0.02);
	}
	if (safe(r - 1, c - 1)) {
		A[r - 1][c - 1] += floor(y * 0.1);
	}
	if (safe(r - 1, c + 1)) {
		A[r - 1][c + 1] += floor(y * 0.01);
	}
	if (safe(r, c - 2)) {
		A[r][c - 2] += floor(y * 0.05);
	}
	if (safe(r + 1, c - 1)) {
		A[r + 1][c - 1] += floor(y * 0.1);
	}
	if (safe(r + 1, c)) {
		A[r + 1][c] += floor(y * 0.07);
	}
	if (safe(r + 1, c + 1)) {
		A[r + 1][c + 1] += floor(y * 0.01);
	}
	if (safe(r + 2, c)) {
		A[r + 2][c] += floor(y * 0.02);
	}
}

void spreadRight(int r, int c, int y) {
	if (safe(r - 1, c)) {
		A[r - 1][c] += floor(y * 0.07);
	}
	if (safe(r - 2, c)) {
		A[r - 2][c] += floor(y * 0.02);
	}	
	if (safe(r - 1, c - 1)) {
		A[r - 1][c - 1] += floor(y * 0.01);
	}	
	if (safe(r - 1, c + 1)) {
		A[r - 1][c + 1] += floor(y * 0.1);
	}
	if (safe(r, c + 2)) {
		A[r][c + 2] += floor(y * 0.05);
	}
	if (safe(r + 1, c - 1)) {
		A[r + 1][c - 1] += floor(y * 0.01);
	}	
	if (safe(r + 1, c)) {
		A[r + 1][c] += floor(y * 0.07);
	}
	if (safe(r + 1, c + 1)) {
		A[r + 1][c + 1] += floor(y * 0.1);
	}
	if (safe(r + 2, c)) {
		A[r + 2][c] += floor(y * 0.02);
	}
}

void spreadDown(int r, int c, int y) {
	if (safe(r - 1, c-1)) {
		A[r - 1][c-1] += floor(y * 0.01);
	}
	if (safe(r - 1, c+1)) {
		A[r - 1][c+1] += floor(y * 0.01);
	}
	if (safe(r, c - 2)) {
		A[r][c - 2] += floor(y * 0.02);
	}
	if (safe(r, c + 2)) {
		A[r ][c + 2] += floor(y * 0.02);
	}
	if (safe(r, c - 1)) {
		A[r][c - 1] += floor(y * 0.07);
	}
	if (safe(r, c + 1)) {
		A[r ][c + 1] += floor(y * 0.07);
	}
	if (safe(r + 1, c-1)) {
		A[r + 1][c-1] += floor(y * 0.1);
	}
	if (safe(r + 1, c + 1)) {
		A[r + 1][c + 1] += floor(y * 0.1);
	}
	if (safe(r + 2, c)) {
		A[r + 2][c] += floor(y * 0.05);
	}
}

void spreadUp(int r, int c, int y) {
	if (safe(r - 1, c - 1)) {
		A[r - 1][c - 1] += floor(y * 0.1);
	}

	if (safe(r - 1, c + 1)) {
		A[r - 1][c + 1] += floor(y * 0.1);
	}

	if (safe(r, c - 2)) {
		A[r][c - 2] += floor(y * 0.02);
	}

	if (safe(r, c + 2)) {
		A[r][c + 2] += floor(y * 0.02);
	}

	if (safe(r, c - 1)) {
		A[r][c - 1] += floor(y * 0.07);
	}

	if (safe(r, c + 1)) {
		A[r][c + 1] += floor(y * 0.07);
	}

	if (safe(r + 1, c - 1)) {
		A[r + 1][c - 1] += floor(y * 0.01);
	}

	if (safe(r + 1, c + 1)) {
		A[r + 1][c + 1] += floor(y * 0.01);
	}

	if (safe(r - 2, c)) {
		A[r - 2][c] += floor(y * 0.05);
	}
}

void print() {
	cout << "--\n";
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}

int leftover(int total) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			total -= A[i][j];
		}
	}

	return total;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int total = 0;
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int input;
			cin >> input;
			A[i][j] = input;
			total += input;
		}
	}

	int r = N / 2 + 1; int c = N / 2 + 1; int num = 1; int dir = 2; // ��=1, ��=2, ��=3, ��=4
	while (1) {
		// num�� �ݺ�
		for (int k = 0; k < num; k++) {
			if (r == 1 && c == 1) break; // 1, 1 �����ϸ� �Ҹ�

			// x -> y �� �̵�
			int x, y;
			if (dir == 1) { // ����
				c++;
				x = A[r][c - 1]; y = A[r][c];
			}
			else if (dir == 2) { // ����
				c--; // ����
				x = A[r][c + 1]; y = A[r][c];
			}
			else if (dir == 3) { // ����
				r++;
				x = A[r - 1][c]; y = A[r][c];
			}
			else {
				r--;
				x = A[r + 1][c]; y = A[r][c];
			}

			A[r][c] = 0; // �� �������Ƿ�

			// �ֺ� �� �𳯸��� �� ���
			int sum = floor(y * 0.01) * 2 + floor(y * 0.02) * 2 + floor(y * 0.07) * 2 
				+ floor(y * 0.1) * 2 + floor(y * 0.05);

			int a = y - sum;

			if (dir == 1) {
				spreadRight(r, c, y);
				if(safe(r, c+1)) A[r][c + 1] += a;
			}
			else if (dir == 2) {
				spreadLeft(r, c, y); // �̵����� ���� ���� ���� ��
				if(safe(r,c-1)) A[r][c - 1] += a;
			}
			else if (dir == 3) {
				spreadDown(r, c, y);
				if(safe(r+1,c)) A[r + 1][c] += a;
			}
			else {
				spreadUp(r, c, y);
				if(safe(r-1, c)) A[r - 1][c] += a;
			}
		}

		//print();

		if (r == 1 && c <= 1) break;

		// ȸ��
		// ���� 1��, �Ʒ��� 1��, ������ 2��, ���� 2��,
		// ���� 3��, �Ʒ��� 3��, ������ 4��, ���� 4��,,
		if (num % 2 == 1) {
			// Ȧ��
			if (dir == 2) { // ����
				dir = 3; // ����
			}
			else if (dir == 3) { // ����
				num++;
				dir = 1; // ������
			}
		}
		else {
			// ¦��
			if (dir == 1) {
				dir = 4;
			}
			else if (dir == 4) {
				num++;
				dir = 2;
			}
		}

	}
	
	cout << leftover(total);
}