#include <iostream>
using namespace std;

int N, M;
int A[7];

void f(int x) {
	if (x == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", A[i]);
		}
		printf("\n");
		return;
	}
	for (int i = 1; i <= N; i++) {
		A[x] = i;
		f(x + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	f(0);

}