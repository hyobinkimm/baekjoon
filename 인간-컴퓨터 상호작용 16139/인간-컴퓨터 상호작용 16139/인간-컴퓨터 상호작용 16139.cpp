#include <iostream>
#include <string>
using namespace std;

string A;
int S[200001][26];
// S[i][j] : 0~i���� ���ĺ� j�� ������
int q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> A;

	for (int i = 0; i < A.length(); i++) {
		int j = A[i] - 97; 
		if (i != 0) {
			for (int k = 0; k < 26; k++) {
				S[i][k] = S[i - 1][k]; 
			}
		}
		S[i][j]++;
	}

	cin >> q;
	for (int i = 0; i < q; i++) {
		char input; int r, l;
		cin >> input;
		cin >> l >> r;
		int index = input - 97;

		int large = S[r][index];
		int small = (l > 0) ? S[l - 1][index] : 0; // 0���� �����ϸ� ù �κк��� Ž���ϴ� ����

		printf("%d\n", large - small);
	}
}