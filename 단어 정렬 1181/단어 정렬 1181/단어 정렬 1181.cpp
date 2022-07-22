#include <iostream>
#include <algorithm>
using namespace std;

int N;
string A[20000];

bool cmp(string a, string b) {
	if (a.length() == b.length()) { // ���̰� ������
		return a < b; // ���������� ����
	}
	return a.length() < b.length(); // ���̼����� ����
}


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int k = 0;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		bool isit = false;
		string input;
		cin >> input;
		for (int j = 0; j < k; j++) {
			if (input == A[j]) {
				isit = true;
				break;
			}
		}
		if (isit == true) {} // �̹� �ԷµǾ������� pass
		else { // ���� �Էµ��� Ȯ�εǸ� A�� ����
			A[k] = input; k++;
		}
	}
	
	sort(A, A + k, cmp);

	for (int i = 0; i < k; i++) {
		printf("%s\n", A[i].c_str());
	}

}