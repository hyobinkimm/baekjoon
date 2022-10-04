#include <iostream>
using namespace std;

int N, M; // N���� ���� M�� ������ �������� ����
int X[5000];
int minimum = 50000000;

// ����
// ������ ���ӵ� ���� �ǰ� ������ ��
// �� ������ ������ �ִ��� ���ϴµ�, �̰͵��� ������ �ּڰ��� ����
// ������ ���� : ������ ���� ���� �ִ� - �ּڰ�
// ������ ������ ���� : 0 ~ 10,000

// ����ȭ ���� : ������ ������ �ִ��� �ּڰ�
// ���� ���� : ������ ������ �ִ��� X�� ° 
void BinarySearch(int start, int end) {
	if (start > end) {
		return;
	}
	
	int key = (start + end) / 2;
	int cnt = 1;
	
	int mini = 50000000; int maxi = -1;
	// �������� �ִ��� ���ϰ�
	for (int i = 0; i < N; i++) {
		mini = min(mini, X[i]);
		maxi = max(maxi, X[i]);

		if (maxi - mini > key) {
			cnt++;
			maxi = X[i]; 
			mini = X[i];
		}
	}

	if (cnt <= M) {
		minimum = (key < minimum) ? key : minimum;
		BinarySearch(start, key - 1);
	}
	else {		
		BinarySearch(key + 1, end);
	}
		
	
}


int main() {
	cin >> N >> M;
	
	int sum = 0;
	int mini = 10000; int maxi = -1;
	for (int i = 0; i < N; i++)
	{
		cin >> X[i];
		mini = (X[i] < mini) ? X[i] : mini;
		maxi= (X[i] > maxi) ? X[i] : maxi;
	}

	// �� ������ ������ ���� : x2-x1 ~ xn-x1
	BinarySearch(0, maxi);

	cout << minimum;
}