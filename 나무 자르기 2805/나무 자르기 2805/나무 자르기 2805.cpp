#include <iostream>
using namespace std;

int N, M; 
int A[1000000];
int maximum = -1;
// ���ܱ� ���� ���� 0 ~ �ִ� max(A)

void BinarySearch(int start, int end) {
	if (start > end)return;

	int key = (start + end) / 2; // ���ܱ⿡�� ������ �� �ִ� ������ �ִ�

	long long int sum = 0; // ������ ���̰� 2,000,000,000�� �� �ֱ� ������ ū �ڷ���
	for (int i = 0; i < N; i++)
	{
		if (A[i] - key >= 0) { // �ڸ��� �� ���� �ִ� �͵� ������ �� ����
			sum += A[i] - key; // ������ �� �ִ� ������ ����

		}
	}
	
	if (sum >= M) { // ��� M������ ������ ���ߴٸ�
		maximum = (key > maximum) ? key : maximum; // �� key�� �ִ�����
		BinarySearch(key + 1, end); // �� ū ���� ���� ������ �κ� Ž��
	}
	else {
		BinarySearch(start, key - 1); // �� ���ߴٸ� �� ���� �߶�� ��. �׷����� ���ܱ� ���� ���̰� �� ���ƾ���
	}
	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	int maxi = -1;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
		maxi = (A[i] > maxi) ? A[i] : maxi;
	}


	BinarySearch(0, maxi);

	cout << maximum;

}