#include <iostream>
#include <vector>
#include <memory.h>
using namespace std;

int N, M;
vector<int> A[2001]; // �迭�� �ϸ� �� �� ���� ��嵵 ���ľ� �ؼ� �ð� �ʰ�
bool visited[2001];
bool answer;

void backtracking(int r, int cnt) {
	if (answer)return;

	if (cnt == 4) { // ��� 5��, ���� 4��
		answer = true; 
		return;
	}

	visited[r] = true;
	for (auto j : A[r]) {
		if (!visited[j]) {
			// �ѹ��� �湮 x
			if (!visited[j]) backtracking(j, cnt + 1); // ���� ���̾�� ��
		}
	}
	visited[r] = false;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		A[a].push_back(b);
		A[b].push_back(a);
	}

	for (int i = 0; i < N; i++) {
		backtracking(i, 0);
		if (answer)break;
		memset(visited, false, sizeof(bool));
	}
	
	if (answer)cout << 1;
	else cout << 0;
}