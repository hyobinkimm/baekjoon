#include <iostream>
using namespace std;

int A[1001]; int N;
int DP[1001] = { 0,1, }; 
// DP[i] : i��° ���� ������ ���ҷ� ������ LIS�� ����
int maximum;
int ans = 1; // ������ �ּ� 1

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	for (int i = 2; i <= N; i++) {
		maximum = 0;
		for (int j = 1; j < i; j++) { // �ִ� ã��
			if (A[j] < A[i] && DP[j] > maximum) {
				// ���� A[i]������ �����鼭, LIS ���̰� ���� ū ��
				maximum = DP[j]; // maximum�� ����
			}
		}
		DP[i] = maximum + 1; // DP[i]�� maximum���κ��� ���̰� 1 �߰��� ����
		ans = (DP[i] > ans) ? DP[i] : ans; // DP[N]�� �ִ��� �ƴϹǷ� �ٷ� ���ؼ� ���信 ����
	}
	cout << ans;
}