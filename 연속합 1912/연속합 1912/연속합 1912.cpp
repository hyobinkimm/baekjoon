#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

int N; int A[100001];
int R[100001]; // R[i] = i��°������ �������� �ִ�
int ans;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
		R[i] = A[i];
	}
	ans = R[1];

	for (int i = 2; i <= N; i++) {
		R[i] = max(R[i - 1] + A[i], A[i]); // ���� �ִ�+���ο� �� vs ���ο� ��
		ans = R[i] > ans ? R[i] : ans;
	}
	printf("%d", ans);

	return 0;
}