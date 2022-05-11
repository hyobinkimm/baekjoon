#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
long int A[100001];

// 1. �Է��� �ް� �̸� ������
// 2. Ž���� ���� �̺�Ž�� �̿�
// 
// ���Ŀ��� �ð� �ʰ� �߻�
// O(nlogn)�� heap_sort �̿�

void BinarySearch(int start, int end, int key) {
	if (start > end) {
		printf("0\n"); // cout���� �ϸ� �ð��ʰ�
		return;
	}

	int mid = (start + end) / 2; // �ݰ�

	if (A[mid] == key) { // ã������
		printf("1\n");
		return;
	}
	else if (A[mid] > key) {
		return BinarySearch(start, mid-1, key);
	}
	else {
		return BinarySearch(mid+1, end, key);
	}
}

void max_heapify(int h, int m) { // root / ũ��
	// parent node�� child node���� Ŀ�� �ϴ� maxheap
	int v = A[h]; // �ϴ� keep
	int j = 0;
	for (j = 2 * h; j <= m; j *= 2) {
		if (j < m && A[j] < A[j + 1]) {
			j = j + 1;
		}
		// j�� ���� ū �ڽ� ���
		if (v >= A[j]) break; // arr[j]�� v�� �ش��ϴ� ������ �� ŭ
		else A[j / 2] = A[j]; // a[j]�� �θ� ���� �̵�(�� ũ�Ƿ�)
	}
	A[j / 2] = v; // �ٲ���
}

void max_heap_sort(int size) {
	int n = size - 1;
	// A[0]�� ������� �ʱ� ������ ��� i�� 1���� ���ư�

	for (int i = n / 2; i >= 1; i--) {
		max_heapify(i, n); // maxheap ������ �°� �����͸� �ٲ��� (�θ�>�ڽ�)
	}
	for (int i = n - 1; i >= 1; i--) { // �������� ����
		int temp = A[1];
		A[1] = A[i + 1];
		A[i + 1] = temp;
		max_heapify(1, i);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
	}
	max_heap_sort(N+1);

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		long int value;
		cin >> value;
		BinarySearch(1, N, value);
	}
}