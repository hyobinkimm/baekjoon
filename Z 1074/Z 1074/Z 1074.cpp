#include <iostream>
#include <cmath>
using namespace std;

int N;
int r, c;
int order;

// ū ���� �۰� �ɰ�
// ���� ���̰� 2�� ���̻� �ɰ� �� ����

void cut(int x, int y, int n) { 
	// x, y : ���� ��и��� ���� �� ��ǥ
	// �� �� ��������?
	if (x == c && y == r) {
		cout << order;
		return;
	}
	if ((y <= r && r < y + n) && (x <= c && c < x + n)) { // ���� ���� �ȿ� r,c�� �ִٸ�
		cut(x, y, n / 2); // 1����
		cut(x + n / 2, y, n / 2); // 2����
		cut(x, y + n / 2, n / 2); // 3����
		cut(x + n / 2, y + n / 2, n / 2); // 4����
	}
	else { // ������ �� �� ��ͷ� ���ư��ٵ� �� ����
		order += n * n; // �ȿ� �ִ� ������ ����
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> r >> c;

	cut(0, 0, 1 << N); // 1<<N = pow(2,N)
}