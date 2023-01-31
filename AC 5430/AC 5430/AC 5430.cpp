#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

int T;
deque<int> mydeq;

bool D(bool reverse) {
	// true : ���� �߻� O
	// false : ���� �߻� X
	if (mydeq.empty()) return true;
	else {
		// ������������ �� �ڰ� ù��° ������ ���� �̿�
		// ���� ���¸� �� �տ� ù��° ������ ���� �̿�
		if (reverse) mydeq.pop_back();
		else mydeq.pop_front();
	}

	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		string p, arr;
		cin >> p;
		int n; cin >> n; // ������ �Ⱦ�����
		cin >> arr;
		int num = 0;
		// ���ڿ� parsing �� deque�� ����ֱ� 
		for (int j = 0; j < arr.length(); j++) {
			if (arr[j] == ',' || arr[j] == ']') {
				// �ϳ��� ������ �ϼ��� ���
				if (num != 0) mydeq.push_back(num);				
				num = 0;
			} 
			if (48 <= arr[j] && arr[j] <= 57) {
				// ���� �������
				num = num * 10 + (arr[j] - 48);
			}
		}

		bool isError = false; 
		bool reverse = false; // �迭�� �������ִ��� ��Ÿ���ִ� ����
		for (int j = 0; j < p.length(); j++) {
			if (p[j] == 'R') {
				// �������ִ� ���¿��� �������� ���󺹱�
				// ���� ���¿��� �������� �������ִ� ����
				reverse = !reverse;
			}
			else {
				isError = D(reverse);
				if (isError) break;
			}
		}

		if (isError) cout << "error\n";
		else {
			cout << "[";
			if (!reverse) {
				// ������ ���� �ʴٸ� �պ��� ���
				while (1) {
					if (mydeq.empty()) { cout << "]\n"; break; }
					cout << mydeq.front();
					mydeq.pop_front();
					if (!mydeq.empty())cout << ",";
				}
			}
			else {
				// ������ �ִٸ� �ں��� ���
				while (1) {
					if (mydeq.empty()) { cout << "]\n"; break; }
					cout << mydeq.back();
					mydeq.pop_back();
					if (!mydeq.empty())cout << ",";
				}
			}
			
		}
	}
}