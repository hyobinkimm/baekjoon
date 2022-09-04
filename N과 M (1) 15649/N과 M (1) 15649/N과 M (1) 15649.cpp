#include <iostream>
using namespace std;

int N, M;
int A[8];
bool visited[9];

void f(int x) {
	if (x == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", A[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= N; i++) {
		if (!visited[i]) { // �湮���� �ʾҴٸ�
			visited[i] = true;
			A[x] = i;
			f(x + 1);
			visited[i] = false; // �ٽ� �ٲ㼭 �ٸ� ������

		}
	}
}	

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	f(0);

}