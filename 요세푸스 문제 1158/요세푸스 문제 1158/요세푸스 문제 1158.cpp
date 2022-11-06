#include <iostream>
#include <queue>
using namespace std;

int N, K;
queue<int> myqueue;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		myqueue.push(i + 1);
	}

	printf("<");
	while (!myqueue.empty()) {
		for (int i = 0; i < K - 1; i++) { // �ڿ� push�Ѹ�ŭ �տ��� pop
			myqueue.push(myqueue.front());
			myqueue.pop();
		}
		// ���� for�� ������ ��ġ�� ���� K��° ���� ����
		if (myqueue.size() == 1) { // �� ������ �������� ��� ������ ��¦ �ٸ�
			printf("%d>", myqueue.front());
		}
		else {
			printf("%d, ", myqueue.front()); // ��� ��
		}
		myqueue.pop(); // ������
	}
}