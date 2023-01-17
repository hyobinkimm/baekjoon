#include <iostream>
#include <stack>
#include <string.h>
using namespace std;

int T;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		// �迭 50���� �ϸ� ����
		char input[51]; cin >> input;
		bool isWrong = false; stack<int> mystack;
		for (int j = 0; j < strlen(input); j++) {
			if (input[j] == '(') {
				// ������ ��ȣ
				mystack.push(1);
			}
			else {
				// ������ ��ȣ
				if (mystack.empty()) {
					// �̹� ����ִٸ� ¦�� �ȸ´� ����
					cout << "NO\n";
					isWrong = true;
					break;
				}
				else {
					// ���� �Ⱥ���ִٸ�
					mystack.pop();
				}
			}
		}
		if (!isWrong) {
			// for���� �� ������ ���
			if (!mystack.empty()) {
				// �� ������־�� �ϴµ� �ƴ϶��
				cout << "NO\n";
			}
			else {
				cout << "YES\n";
			}
		}

	}
}