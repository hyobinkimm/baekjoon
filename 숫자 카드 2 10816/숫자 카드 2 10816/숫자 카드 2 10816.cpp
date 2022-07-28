#include <iostream>
using namespace std;

int N, M;
struct info {
	int cnt;
};

info m[20000001];

int main() {	
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	// �Էµ� ���� -10,000,000 ~ 10,000,000��
	// 0 ~ 10,000,000 : index�� �Ȱ��� 0 ~ 10,000,000
	// -10,000,000 ~ -1 : index�� 10,000,001 ~ 20,000,000

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int input;
		cin >> input;
		if (input < 0) {
			m[10000000 - input].cnt++;
		}
		else {
			m[input].cnt++;
		}
	}

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int input;
		cin >> input;
		
		if (input < 0) {
			printf("%d ", m[10000000 - input].cnt);
		}
		else {
			printf("%d ", m[input].cnt);
		}
	}
}