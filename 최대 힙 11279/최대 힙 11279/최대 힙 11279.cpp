#include <iostream>
#include <queue>
using namespace std;

int N; int X; int A[100001];
// 0 : ���� ū �� ��� �� �����ض�
// �ڿ��� : �� ���� �־��

priority_queue<int> myqueue; // �ִ����� ������ �� �ִ� �켱���� ť, �⺻ �������� ����

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 1; i <= N; i++)
	{
		//cout << "input : ";
		cin >> X;
		if (X == 0) { // ���� ū �� ���
			if (myqueue.empty()) // �迭�� ����ִٸ�
				printf("0\n");
			else {
				printf("%d\n", myqueue.top()); // �������� �����̹Ƿ�
				myqueue.pop();
			}
		}
		else {
			myqueue.push(X);
		}
		//cout << "-------------\n";
	}
}