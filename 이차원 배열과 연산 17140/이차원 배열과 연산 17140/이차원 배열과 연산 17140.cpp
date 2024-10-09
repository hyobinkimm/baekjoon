#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int R, C, k;
int A[101][101];
int B[101][101];

// R ���� : �迭 A�� ��� �࿡ ���� ���� (���ǰ��� >= ���ǰ���)
// C ���� : �迭 A�� ��� ���� ���� ���� (���ǰ��� < ���ǰ���)

bool cmp(pair<int, int>& a, pair<int, int>& b) {
	if (a.second == b.second)	return a.first < b.first;	
	return a.second < b.second;
}

void print(int index, int R, int C) {
	cout << "i = " << index << endl;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}

	cout << "--------------------\n";

}

int main() {

	cin >> R >> C >> k;
	
	for (int i = 1; i <= 3; i++) {
		cin >> A[i][1] >> A[i][2] >> A[i][3];
	}

	char order = 'R'; // ��ó���� R ����
	bool isInfinite = true; // 100�ʰ� ������ �ȳ��� ���
	int r_cnt = 3, c_cnt = 3; // ���� ����, ���� ����

	for (int i = 1; i <= 101; i++) {
		if (A[R][C] == k) {
			cout << i - 1;
			isInfinite = false;
			break;
		}

		if (r_cnt >= c_cnt) order = 'R';
		else order = 'C';

		int r_max = -1, c_max = -1; // �ִ� ��, �ִ� �� �����ϱ�

		
		if (order == 'R') {
			// �� ����, ���� ������	
			for (int r = 1; r <= r_cnt; r++) {
				// ����� �迭�����
				map<int, int> m;

				for (int c = 1; c <= c_cnt; c++) {
					if (A[r][c] == 0)continue; // 0�� ���� �ʴ´�
					m[A[r][c]] ++;
				}

				// map ���� (�� ����)
				vector<pair<int, int>> v(m.begin(), m.end());

				sort(v.begin(), v.end(), cmp);

				int c = 1;
				for (auto iter = v.begin(); iter != v.end(); iter++) {
					B[r][c] = iter->first;
					c++;
					B[r][c] = iter->second;
					c++;
				}
				c--;
				c_max = (c_max > c) ? c_max: c;
			}		
		}
		else {
			// �� ����, ���� ������	
			for (int c = 1; c <= c_cnt; c++) {
				// ���� �迭�����
				map<int, int> m;

				for (int r = 1; r <= r_cnt; r++) {
					if (A[r][c] == 0)continue; // 0�� ���� �ʴ´�
					m[A[r][c]] ++;
				}
				vector<pair<int, int>> v(m.begin(), m.end());

				sort(v.begin(), v.end(), cmp);

				int r = 1;
				for (auto iter = v.begin(); iter != v.end(); iter++) {
					B[r][c] = iter->first;
					r++;
					B[r][c] = iter->second;
					r++;
				}
				r--;
				r_max = (r_max > r) ? r_max : r;
			}
		}

		r_cnt = (r_cnt > r_max) ? r_cnt : r_max;
		c_cnt = (c_cnt > c_max) ? c_cnt : c_max;

		copy(&B[0][0], &B[0][0] + 101 * 101, &A[0][0]); // B�� A�� ����
		fill(B[0], B[0] + 101 * 101, 0); // B �ʱ�ȭ
	}

	if (isInfinite) cout << -1;
	
}