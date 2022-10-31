#include <iostream>
#include <cmath>
using namespace std;

int N;
int A[10000]; int DP[10000];

// DP[i] : i��°������ ������ �ִ�
// ���� �����ָ� �������� �ʴ� ���ǵ� �����ؾ���

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	DP[0] = A[0];
	DP[1] = A[0] + A[1];
	DP[2] = max(DP[1], max(A[0] + A[2], A[1] + A[2])); // 2��°�� �������� �ʴ� ����(DP[1])�� ����

	for (int i = 3; i < N; i++) {
		int d1, d2,d3;
		// i��°�� �ִ� �� ���� o
		d1 = A[i] + A[i - 1] + DP[i - 3];
		d2 = A[i] + DP[i - 2];

		// i��°�� �ִ� �� ���� x
		d3 = DP[i - 1];
		DP[i] = max(d3, max(d1, d2));
	}

	cout << DP[N - 1];
}