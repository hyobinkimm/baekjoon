#include <iostream>
#include <stack>
#include <string>
using namespace std;

string S;
stack<char> mystack; // ���ڿ� �ϳ��� ����

void print() { // stack ���
	int size = mystack.size(); 
	for (int i = 0; i < size; i++) {
		cout << mystack.top();
		mystack.pop();
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	getline(cin, S);

	int i = 0; bool istag = false;
	while (i<S.length()) {
		if (istag) { // tag �ȿ� �ִٸ�
			cout << S[i];
			if (S[i] == '>') { // tag ������
				istag = false; // �ٽ� false
			}
		}
		else { // tag �ȿ� ���� �ʴٸ�
			if (S[i] == '<') { // tag�� ���۵ƴٸ�
				print(); // �� ���� ��Ƴ������� �� �ܾ� ���
				cout << S[i];
				istag = true;
			}
			else {
				if (S[i] == ' ') { // tag �ȿ� ������ �ʰ� ������ ��Ÿ���ٸ� �ܾ�
					print(); // �Ųٷ� �ܾ� ���
					cout << S[i]; // ������ �ڿ� ���
				}				
				else { // �ܾ �Էµǰ� �ִٸ�
					mystack.push(S[i]); // �ܾ��̹Ƿ� stack�� push
					if (i == S.length() -1) { // �� �������� �ܾ ���� ���
						print();
					}
				}
			}
		}
		i++;
	}

}