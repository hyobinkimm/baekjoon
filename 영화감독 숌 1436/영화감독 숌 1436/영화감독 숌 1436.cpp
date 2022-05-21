#include <iostream>
#include <string>
#include <cstring>
using namespace std;

// ������ ���� : � ���� 6�� ��� 3�� �̻� ���� ���� ��
// N��° ��ȭ�� ���� = ������ ���� (N��°�� ���� ������ ����)
// 666, 1666, 2666, 3666, 4666, 5666, 6661, 6662, 6663, 6664, 6665,,

int N;
int i;
int cnt;

bool is_666(string::size_type n, string const& s) {
	if (n == string::npos) { // ��ã������ 
		return false;
	}
	else { // ã������
		return true;
	}
}

int main() {
	cin >> N;

	
	while (1) {
		string temp = to_string(i); // int->string���� ��ȯ
	
		int n = temp.find("666");
		
		if (is_666(n,temp)) { // 666�� ���ٸ�
			cnt++; // cnt��° ��ȭ ����
		}
		if (cnt == N) { // N��° ��ȭ������� �����ߴٸ�
			cout << i;
			break;
		}
		i++;
	}

	return 0;
}