#include <iostream>
using namespace std;

int N, M;
int X[100001]; // index 0�� ������� ����
// X[i]�� �ִ� ���� : 1,000*100,000 = 100,000,000


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		int x;
		cin >>x;
		X[i] = X[i - 1] + x; // ������
	}

	for (int i = 1; i <= M; i++) {
		int x, y;
		cin >> x >> y;
		printf("%d\n", X[y] - X[x - 1]); // cout ���� �ð� �ʰ�
		// ��ġ�� ������ ����
	}

}