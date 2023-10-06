#include <iostream>
#include <cmath>
#include <algorithm>
#include <limits.h>
#include <vector>
using namespace std;

int N;
int A[100000];
int minimum = INT_MAX;
vector<int> v;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	sort(A, A + N); // �ִ��� ���� ��, ū ���� ���� 0�� �������� �������� ����

	// �� ���ܿ��� �ٰ����� two pointer
	int start = 0, end = N - 1; int temp;
	while (start<end) {
		temp = A[start] + A[end];

		if (abs(temp) < minimum) {
			v.clear();
			v.push_back(A[start]);
			v.push_back(A[end]);
			minimum = abs(temp);
		}

		if (temp < 0) {
			// 0���� ������ �� Ŀ���� �Ѵ�..
			start++;
		}
		else if (temp > 0) {
			// 0���� ũ�� �� �۾����� �Ѵ�..
			end--;
		}
		else {
			// temp == 0 �̸� �ٷ� ����
			v.clear();
			v.push_back(A[start]);
			v.push_back(A[end]);

			break;
		}

	}

	sort(v.begin(), v.end());

	cout << v[0] << " " << v[1];
	
}