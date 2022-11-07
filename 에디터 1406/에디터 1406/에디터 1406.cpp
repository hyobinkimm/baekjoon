#include <iostream>
#include <stack>
#include <string>
using namespace std;

// L : Ŀ�� �� ������
// D : Ŀ�� ����������
// B : Ŀ�� ���ʿ� �ִ� ���� ����
// P $ : $�� Ŀ�� ���ʿ� �߰�

stack<char> l;
stack<char> r;

string input;
int M;
string C;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// �Է�
	cin >> input;
	for (int i = 0; i < input.length(); i++)
	{
		l.push(input[i]);
	}

	// ��ɾ� ����
	cin >> M;
	cin.ignore(); // cin���� �Է¹��� ���� getline�� ����ϸ� '\n'������ ���õǴ� ��� �߻�
	for (int i = 0; i < M; i++)
	{
		getline(cin, C);
		if (C[0] == 'P') { // Ŀ�� ���ʿ� ���� ����

			l.push(C[2]);
		}
		else if (C[0] == 'L') { // Ŀ�� �������� �̵�
			if (l.empty()) {}
			else {
				r.push(l.top());
				l.pop();
			}
		}
		else if (C[0] == 'D') { // Ŀ�� ���������� �̵�
			if (r.empty()) {}
			else {
				l.push(r.top());
				r.pop();
			}
		}
		else { // Ŀ�� ���ʿ� �ִ� ���� ����
			if (l.empty()) {}
			else { l.pop(); }
		}
	}

	while (!l.empty()) { // Ŀ�� ���ʿ� �ִ� ���ڵ� ���������� �ű�
		r.push(l.top());
		l.pop();
	}

	while (!r.empty()) { // �� ���
		printf("%c", r.top());
		r.pop();
	}
}