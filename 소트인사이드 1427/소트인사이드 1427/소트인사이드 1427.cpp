#include <iostream>
using namespace std;

string A;
int memo[10]; // 0 ~ 9

// �ƽ�Ű �ڵ� : '0'~'9' == 48~57
// ī���� ����

int main() {
	cin >> A;

	for (int i = 0; i < A.length(); i++) {
		memo[A[i] - 48]++;
	}

	for (int i = 9; i >= 0; i--) {
		if (memo[i]) {
			for (int j = 0; j < memo[i]; j++) { printf("%d", i); }
		}
	}
}