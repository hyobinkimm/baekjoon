#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <cmath>
using namespace std;

int N, M, K;

int A[52][52][5]; // ����, ����, �ӷ�, ����, ��� ���� ������
int dr[8] = { -1,-1,0,1,1,1,0,-1 };
int dc[8] = { 0,1,1,1,0,-1,-1,-1 };

typedef struct Fireball {
	int r, c;
	int m, s, d;
}Fb;

vector<Fb> fb;

void move(int i, int d) {
	int ss = fb[i].s % N; // ���� ������ (N�� �����̸� ���ڸ���)

	fb[i].r += dr[d]*ss; fb[i].c += dc[d]*ss; // ������

	if (fb[i].r < 1) fb[i].r += N;
	if (fb[i].r > N)fb[i].r -= N;	
	if (fb[i].c < 1) fb[i].c += N;
	if (fb[i].c > N)fb[i].c -= N;	

	int rr = fb[i].r; int cc = fb[i].c;

	A[rr][cc][0]++; // ����
	A[rr][cc][1] += fb[i].m; // ����
	A[rr][cc][2] += fb[i].s; // �ӷ�
	A[rr][cc][3] = fb[i].d; // ���� (������ 2�� �̻� �ߺ��Ǹ� ������� ��)
	

	if (fb[i].d % 2 == 0) { // ¦����
		A[rr][cc][4]++;
	}
	else {
		A[rr][cc][4]--;
	}

}


int main() {
	cin >> N >> M >> K;

	for (int i = 0; i < M; i++) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;

		Fb f = { r,c,m,s,d };

		fb.push_back(f);
	}

	while (K > 0) {
		// 1. ��� ���̾�� ���� ���� di�� �ӷ� si��ŭ �̵��Ѵ�
		for (int i = 0; i < fb.size(); i++) {
			move(i, fb[i].d);
		}

		fb.clear();

		// 2. 2�� �̻� ���̾�� �ִ� ĭ���� ���� ��������
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (A[i][j][0] >= 2) {
					int avg_m = A[i][j][1] / 5; // ���� ����� ���̾�� ����
					int avg_s = A[i][j][2] / A[i][j][0]; // ���� ����� ���̾�� �ӷ�

					if (avg_m == 0) continue; // ������ 0�̸� pass

					if (abs(A[i][j][4])==A[i][j][0]) { // ������ Ȧ/¦�� ������ �����ϸ�
						// ���� 0, 2, 4, 6
						fb.push_back({ i,j,avg_m,avg_s,0 });
						fb.push_back({ i,j,avg_m,avg_s,2 });
						fb.push_back({ i,j,avg_m,avg_s,4 });
						fb.push_back({ i,j,avg_m,avg_s,6 });
					}
					else {
						// ���� 1, 3, 5, 7
						fb.push_back({ i,j,avg_m,avg_s,1 });
						fb.push_back({ i,j,avg_m,avg_s,3 });
						fb.push_back({ i,j,avg_m,avg_s,5 });
						fb.push_back({ i,j,avg_m,avg_s,7 });
					}
				}
				if (A[i][j][0] == 1)
					fb.push_back({i,j,A[i][j][1], A[i][j][2], A[i][j][3]});
			}
		}

		// �迭 �ʱ�ȭ
		fill(A[0][0], A[0][0] + 52 * 52 * 5, 0);	

		K--;
	}

	int answer = 0;

	for (int i = 0; i < fb.size(); i++) {
		answer += fb[i].m;
	}

	cout << answer;
}