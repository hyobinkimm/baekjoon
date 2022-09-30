#include <iostream>
using namespace std;

int N, K;
int A[1000000];
int maximum = -1;
// 802 : 200 200 200 200 2
// 743 : 200 200 200 143
// 457 : 200 200 57
// 539 : 200 200 139

// 200�� �� 11 ��


// ���� ������ ������? 0 ~ 2^31 -> 0 ~ max(A)


void BinarySearch(long long int start, long long int end) { // �� �ϸ� key �κп��� �����÷ο찡 ���� ��
	if (start > end) return;

	long long int key = (start + end) / 2; // start�� end ���ؼ� int�� ������ �Ѿ �� �����Ƿ� long long

	long long int cnt = 0; 
	bool is_success = false;
	for (int i = 0; i < K; i++) {
		cnt += A[i] / key; // ������ ���̰� �ִ� 2^31-1�̹Ƿ� key�� �ּ��� �� cnt���� overflow �߻� ����. �׷��Ƿ� cnt�� long long
		if (cnt >= N) { // N�� �̻����� ���� �����
			is_success = true;
			break; // ����
		}
	}

	if (is_success) {
		maximum = (key > maximum) ? key : maximum; // �ִ� ����
		BinarySearch(key + 1, end); // �� �ִ� ���� �ִ��� key���� ū �������� ã�ƺ�
	}
	else { 
		BinarySearch(start, key - 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K >> N; // �̹� K���� �ִµ� N���� ������ �ʿ���

	int maxi = -1;
	for (int i = 0; i < K; i++)
	{
		cin >> A[i];
		maxi = (A[i] > maxi) ? A[i] : maxi;
	}

	BinarySearch(1, maxi); // 1���� maxi���� Ž��

	cout << maximum;
}