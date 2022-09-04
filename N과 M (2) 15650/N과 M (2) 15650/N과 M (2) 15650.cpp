#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int A[8];
bool visited[9];

void f(int x, int cnt) { // x : A�迭�� ���� ����, cnt : A�迭�� ũ��
	if (cnt == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", A[i]);
		}
		printf("\n");
		return;
	}
	for (int i = x; i <= N; i++) {
		if (!visited[i]) { // �湮���� �ʾҴٸ�
			visited[i] = true;
			A[cnt] = i;
			f(i + 1, cnt + 1); // �� ���� ���� ������ �׻� ũ�� ����
			visited[i] = false; // �ٽ� �ٲ㼭 �ٸ� ������
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	f(1,0);
}