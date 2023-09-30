#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int N, M;
int A[51][51];
vector<pair<int, int>> ds;
int dr[9] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dc[9] = { 0,-1, -1, 0, 1, 1, 1, 0, -1 };
vector<pair<int, int>> clouds;
bool visited[51][51];

int main() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}

	for (int i = 1; i <= M; i++) {
		int d, s;
		cin >> d >> s;
		ds.push_back(make_pair(d, s));
	}

	clouds.push_back(make_pair(N, 1));
	clouds.push_back(make_pair(N, 2));
	clouds.push_back(make_pair(N-1, 1));
	clouds.push_back(make_pair(N-1, 2));
	
	for (int k = 0; k < M; k++) {
		for (int j = 0; j < 51; j++) {
			memset(visited[j], false, sizeof(visited[j]));
		}

		int d = ds[k].first;
		int s = ds[k].second;

		// 1. ���� �̵�
		for (int i = 0; i < clouds.size(); i++) {
			int r = clouds[i].first; int c = clouds[i].second;
			int rr = r + dr[d] * (s % N); int cc = c + dc[d] * (s % N);
			if (rr <= 0) rr += N;
			if (cc <= 0)cc += N;
			if (rr > N) rr -= N;
			if (cc > N) cc -= N;

			clouds[i].first = rr; clouds[i].second = cc;
			visited[rr][cc] = true; // ������ �񱸸� ���
		}

		vector<pair<int, int>> before(clouds); // �� ���� ����� ..

		// 2. ���� ĭ�� �� ����
		for (int i = 0; i < clouds.size(); i++) {
			int r = clouds[i].first; int c = clouds[i].second;
			A[r][c]++;
		}

		// 3. ���� �����
		clouds.clear();

		// 4. �밢�� ���� ������ �� ��
		for (int i = 0; i < before.size(); i++) {
			int r = before[i].first; int c = before[i].second;
			// �밢�� : 2, 4, 6, 8
			int cnt = 0; // �밢�� ������ �� ����
			for (int j = 1; j <= 4; j++) {
				if (1 <= r + dr[2 * j] && r + dr[2 * j] <= N
					&& 1 <= c + dc[2 * j] && c + dc[2 * j] <= N
					&& A[r + dr[2 * j]][c + dc[2 * j]] > 0) {
					// �밢�� ���� ��� �ش� �ȵǸ�
					// ���� �ִٸ�
					cnt++;
				}
			}
			A[r][c] += cnt;
		}

		// 5. ����ĭ �־��� �� ������ ������ �� ���� �� 2�̻��� ĭ ���� ����
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (!visited[i][j] && A[i][j] >= 2) {
					// ������ �־��� ĭ ����
					// 2 �̻�
					A[i][j] -= 2;
					clouds.push_back(make_pair(i, j));
				}
			}
		}
	}

	int answer = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			answer += A[i][j];
		}
	}

	cout << answer;
}