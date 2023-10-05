#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

int R, C, T;
vector<vector<int>> A(51, vector<int>(51));
int dr[4] = { 1, 0, -1, 0 };
int dc[4] = { 0, 1, 0, -1 };

int answer() {
	int sum = 0; 
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if(A[i][j]>0) sum += A[i][j];
		}
	}
	return sum;
}

bool safe(int r, int c) {
	return (1 <= r && r <= R) && (1 <= c && c <= C);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> R >> C >> T;

	vector<pair<int, int>> v; // �̼�����
	vector<pair<int, int>> a; // ���� û����

	fill(A.begin(), A.end(), vector<int>(51, 0)); // �ʱ�ȭ ���ϸ� A[i][j] ���� ����

	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			int input;
			cin >> input;
			A[i][j] = input;
			if (input > 0) v.push_back(make_pair(i, j));
			if (input < 0) a.push_back(make_pair(i, j));
		}
	}

	int to_r = a[0].first; int to_c = a[0].second;
	int bo_r = a[1].first; int bo_c = a[1].second;

	vector<vector<int>> temp_A; // ���ÿ� ��� �̼������� Ȯ��ǹǷ� �ǽð� ������Ʈ X
	 
	while (T > 0) {
		T--;

		temp_A = A;

		// 1. �̼����� Ȯ��
		for (int i = 0; i < v.size(); i++) {
			int r = v[i].first; int c = v[i].second;
			int cur = A[r][c] / 5; // ���� �̼�����/5

			int cnt = 0; // Ȯ��� ������ ����
			for (int dir = 0; dir < 4; dir++) {
				if (safe(r + dr[dir], c + dc[dir])
					&& (A[r + dr[dir]][c + dc[dir]] != -1)) {
					cnt++;
					temp_A[r + dr[dir]][c + dc[dir]] += cur; // update
					temp_A[r][c] -= cur; // ���� ��ġ ���
				}
			}
		}

		// 2. ����û���� �۵�
		int r = to_r, c = to_c + 1;
		int num = 1; int temp = temp_A[r][c]; int cur;

		// ���� ����û����
		while (1) {
			if (r == to_r && c == to_c) break;
			cur = temp_A[r][c];
			temp_A[r][c] = temp;
			if (r == to_r && c == to_c + 1) {
				// ���� �Ʒ�
				num = 1;
				temp_A[r][c] = 0;
			}
			if (r == to_r && c == C) {
				// ������ �Ʒ�
				num = 2;
			}
			if (r == 1 && c == C) {
				// ������ ��
				num = 3;
			}
			if (r == 1 && c == 1) {
				num = 4;
			}
			temp = cur;
			if (num == 1) {
				c++;
			}
			else if (num == 2) {
				r--;
			}
			else if (num == 3) {
				c--;
			}
			else {
				r++;
			}
		};

		r = bo_r; c = bo_c + 1;
		num = 1; temp = temp_A[r][c]; 

		// �Ʒ��� ����û����
		while (1) {
			if (r == bo_r && c == bo_c) break;
			cur = temp_A[r][c];
			temp_A[r][c] = temp;
			if (r == bo_r && c == bo_c + 1) {
				// ���� ��
				num = 1;
				temp_A[r][c] = 0;
			}
			if (r == bo_r && c == C) {
				// ������ ��
				num = 2;
			}
			if (r == R && c == C) {
				// ������ �Ʒ�
				num = 3;
			}
			if (r == R && c == 1) {
				// ���� �Ʒ�
				num = 4;
			}
			temp = cur;
			if (num == 1) {
				c++;
			}
			else if (num == 2) {
				r++;
			}
			else if (num == 3) {
				c--;
			}
			else {
				r--;
			}
		}

		v.clear();
		for (int i = 1; i <= R; i++) {
			for (int j = 1; j <= C; j++) {
				if(temp_A[i][j]>0) v.push_back(make_pair(i, j)); // ���� �̼����� ��ġ ����
			}
		}

		A = temp_A;
	}

	cout << answer();

}