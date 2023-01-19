#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int N; 
vector<char> myvector; // �迭�� ũ�⸦ �����ص� ���� �ʾƼ� ���ϳ׿�
stack<int> mystack;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int before = 0; // ������ push �ߴ��� ����ϱ� ���� ����
	bool isWrong = false; // for�� Ż���� ���� ����
	for (int i = 0; i < N; i++) {
		int temp; cin >> temp;
		if (before < temp) { // temp���� push�� �ؾߵǴ� ��Ȳ
			for (int j = before + 1; j <= temp; j++) { 
				myvector.push_back('+');
				mystack.push(j); // push
			}
			before = temp; // ������ push�ߴ��� ����
		}
		if (mystack.top() == temp) { // �Էµ� ���� top()�� ������ 
			myvector.push_back('-');
			mystack.pop(); // pop
		}
		else { // pop�� �� ���ϴ� ���Ұ� Ƣ����°� �ƴ϶��
			cout << "NO";
			isWrong = true;
			break; // ����
		}
	}
	if (!isWrong) {
		// ������ ���� �� �ִ� ���
		for (int i = 0; i < myvector.size(); i++) {
			cout << myvector.at(i) << "\n"; // push, pop ���
		}
	}
}