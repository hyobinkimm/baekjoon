#include <iostream>
#include <cmath>
using namespace std;
// 1. ����� �� ���� 1, 2ĭ��
// 2. ������ �����ϰ� �����ؼ� 3��� ���� ����
// 3. ������ ���� ����� ��ƶ�

int N;
int A[301]; int DP[301]; // i��° ��ܿ����� �ִ�

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
	}

	// �ʱⰪ ����
	DP[1] = A[1];
	DP[2] = max(A[1] + A[2], A[2]); // ����->1->2��° ��� or ����->2��° ���
	DP[3] = max(A[1] + A[3], A[2] + A[3]); // ����->1->3��° ��� or ����->2->3��° ��� ��

	for (int i = 4; i <= N; i++) {
		int d1, d2;
		d1 = DP[i - 3] + A[i - 1] + A[i]; // �ٷ� ����� ����(�׷��� ����������� ��ƾ��ϹǷ� i-3)
		d2 = DP[i - 2] + A[i]; // ������� ����
		DP[i] = max(d1, d2);
	}

	cout << DP[N];
}