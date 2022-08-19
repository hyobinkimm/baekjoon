#include <iostream>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;

int N;
int A[100];
int B[99];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}
	sort(A, A + N); // A �迭 �������� ����


	for (int i = 0; i < N-1; i++) { // A�迭 ���� B �迭�� �ֱ�
		B[i] = A[i + 1] - A[i];
	}
	sort(B, B + N - 1); // B �迭 �������� ����


	int R = B[0];
	for (int i = 0; i < N - 2; i++) {
		int big = B[i+1]; int small = R;
		while (1) {
			R = big % small;
			if (R == 0) {
				R = small;
				break;
			}
			big = small; small = R;
		}
	} 
	// R�� ����� ���ϸ� ��(1 ����)

	// ��� ���ϱ�
	set<int> myset;
	for (int i = 1; i * i <= R; i++) {
		if (R % i == 0) {
			myset.insert(i);
			myset.insert(R / i);
		}
	}
	myset.erase(1); // M�� 1���� ũ�Ƿ� ����

	set<int> ::iterator iter;
	for (iter = myset.begin(); iter != myset.end(); iter++)
	{
		printf("%d ", *iter);
	}
}