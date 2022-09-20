#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;

int N;
int A[21][21];
int minimum = 2147483647;
bool checked[21];

void f(int count, int present) {	// count : N/2�� �Ǹ� �����ų ��, pressent : 
	if (count == N / 2) { // start���� link���� �ϼ��ƴٸ�
		int sum1 = 0; int sum2 = 0; // sum1 : start ���� �ɷ�ġ, sum2 : link ���� �ɷ�ġ
		for (int i = 1; i <= N; i++) { // �ɷ�ġ ���
			for (int j = i+1; j <= N; j++) {
				if (checked[i] && checked[j]) sum1 += A[i][j] + A[j][i]; // start��
				else if ((!checked[i]) && (!checked[j])) sum2 += A[i][j] + A[j][i]; // link��
			}
		}		
		minimum = min(minimum, abs(sum1 - sum2)); // �ּڰ� ���
		return;
	}

	for (int i = present; i < N; i++) {
		checked[i] = true; // backtracking
		f(count + 1, i + 1);
		checked[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}

	f(0, 1);
	printf("%d", minimum);
}