#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct mymy {
	int idx; 
	bool isCheck = false;
};

int K; int A[100]; // �߿䵵 �������� ���Ŀ� �ʿ��� �迭

bool cmp(int a, int b) { // ��������
	return a > b;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> K;

	for (int i = 0; i < K; i++)
	{
		int N, M; queue<mymy> myqueue;
		cin >> N >> M;

		// queue ����
		for (int j = 0; j < N; j++)
		{
			int tmp; cin >> tmp;
			if (j == M) { 
				// ���� �ñ��� queue �������
				// isCheck�� true��
				myqueue.push({ tmp, true }); 
			} 
			else myqueue.push({ tmp, false });
			A[j] = tmp; // �߿䵵�� �迭���� ����
		}

		// ���� ���
		int order = 1;
		while (1) {
			sort(A, A + N, cmp); // �������� ����
			int maximum = A[0]; // ���� ���� ū �߿䵵
			mymy tmp; tmp = myqueue.front();
			if (tmp.idx < maximum) {
				// �ϳ��� �߿䵵 ū �� �ڿ� �ִٸ�
				// queue�� ���� �ڿ� ���ġ
				myqueue.pop(); myqueue.push(tmp); 				
			}
			else {
				// ���� ���� ũ��
				if (tmp.isCheck) {
					// ���� �ñ����ϴ� �������
					// ���� ��� �� �ٷ� ����
					cout << order << "\n";
					break;
		  		}
				else {
					// ���� �ñ����ϴ��� �ƴϸ�
					// �μ� (pop)
					myqueue.pop();
					N--; // �μ�� ������ ������ ������ �ϳ��� �پ��Ƿ�
					A[0] = 0; // 1-9�̹Ƿ� 0���� �����Ͽ� ���� �߿䵵 ���
					order++; // ���� ����
				}
			}
		}
	}
}