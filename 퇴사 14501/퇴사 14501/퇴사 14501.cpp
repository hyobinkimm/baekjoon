#include <iostream>
#include <cmath>
using namespace std;

int N;
int T[17]; int P[17];
int A[17];
/*
	A[i] = i�ϱ��� ��� ����
*/
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> T[i] >> P[i];
	}

	// �� �������� ���� ���´ٰ� ����
	for (int i = 1; i <= N ; i++) {
		// i��° ���� �� ���� ���
		if (i + T[i] <= N + 1) {
			// ��� �� �������� ���ؾ� ��
			A[i + T[i]] = max(A[i + T[i]], A[i] + P[i]);
		}
				// i��° ���� ���� ���� �ʾ��� ���
		A[i + 1] = max(A[i + 1], A[i]);
	}

	cout << A[N + 1];
}