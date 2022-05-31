#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>
#include <stack>
#include <locale>
using namespace std;

int D[1001][1001];
int ins, del, rep;

int EditDistance(string source, string target) {
	int s_len = source.length();
	int t_len = target.length();

	// �ʱ�ȭ
	for (int i = 1; i <= t_len; i++) {
		D[i][0] = D[i - 1][0] + ins;
	}
	for (int j = 1; j <= s_len; j++) {
		D[0][j] = D[0][j - 1] + del;
	}

	for (int i = 1; i <= t_len; i++) {
		for (int j = 1; j <= s_len; j++) {
			if (source[j - 1] == target[i - 1]) { // ���ڰ� ������
				D[i][j] = D[i - 1][j - 1]; // ���̻� ���� ���ʿ��ϹǷ� �״�� ����
			}
			else { // ���ڰ� �ٸ��� �ּڰ� ����
				D[i][j] = min(min(D[i - 1][j] + ins, D[i][j - 1] + del), D[i - 1][j - 1] + rep);
			}
		}
	}

	return D[t_len][s_len]; // �� ������ �迭�� �ּ������Ÿ�
}

int main() {

	string source, target;
	cin >> source >> target;
	ins = 1; del = 1; rep = 1;
	cout << EditDistance(source, target);
	return 0;

}