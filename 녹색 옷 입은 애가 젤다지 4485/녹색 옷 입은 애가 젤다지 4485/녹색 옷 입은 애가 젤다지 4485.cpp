#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <limits.h>
using namespace std;

int N;
int A[126][126];
int D[126][126]; 
int dr[4] = { 1,0,-1,0 };
int dc[4] = { 0,1,0,-1 };

bool safe(int r, int c) {
	return 1 <= r && r <= N && 1 <= c && c <= N;
}

struct cmp {
	bool operator()(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b) {
		return a.second > b.second; // �׻� �������� ���� (���� ���������̹Ƿ�)
	}
};

priority_queue<pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, cmp> pq;
// pair<int, int> : ��ǥ
// int : �ִܰŸ�

int Solve() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			D[i][j] = INT_MAX; // ����Ÿ��� �ʱ�ȭ
		}
	}

	pq.push(make_pair(make_pair(1, 1), A[1][1]));	// ��ǥ�� �� ��ǥ�� ���� �� �Ҵ� ����
	D[1][1] = A[1][1];

	while (!pq.empty()) {
		pair<pair<int, int>, int> tmp = pq.top();
		pq.pop();

		int r = tmp.first.first; int c = tmp.first.second;
		int total_k = tmp.second;
		for (int i = 0; i < 4; i++) {		
			if (safe(r + dr[i], c + dc[i])) {
				// �����ϴٸ�
				int tmp_total_k = A[r + dr[i]][c + dc[i]] + total_k;

				if (tmp_total_k < D[r + dr[i]][c + dc[i]]) {
					// �ּڰ� �����ߴٸ�
					D[r + dr[i]][c + dc[i]] = tmp_total_k; // D�� ����
					pq.push(make_pair(
						make_pair(r + dr[i], c + dc[i]), tmp_total_k)
					);
				}
			}
		}
	}


	return D[N][N];
}


int main() {
	int i = 1;	
	while (1) {
		cin >> N;

		if (N == 0)break;

		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				cin >> A[i][j];		
			}
		}

		cout << "Problem " << i << ": " << Solve() << endl;
		i++;
	}
}