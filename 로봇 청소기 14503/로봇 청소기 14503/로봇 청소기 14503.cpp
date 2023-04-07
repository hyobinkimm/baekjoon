#include <iostream>
using namespace std;
#define MAX 51

int N, M, r, c, d;

int A[MAX][MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	cin >> r >> c >> d;
	// d=0 : ����, d=1 : ����, d=2 : ����, d=3 : ����
	// �κ� û�ұⰡ �ִ� ���� �׻� �� ĭ
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> A[i][j];
			// 0�̸� û�� �� �Ǿ�����
			// 1�̸� ������
		}
	}

	int sum = 0;
	// �۵��� ���ߴ� ���� �� �� ���� : ���� ĭ�� ���̶� ������ �� ���� ��

	int i = r; int j = c;
	while (1) {
		if (A[i][j] == 0) { // ���� ĭ�� û�ҵ��� ���� ���
			A[i][j] = 2; // û���� ���� 2�� ����
			sum++;
		}

		// ���� �ֺ� 4ĭ�� ����
		if (A[i - 1][j] == 0 || A[i + 1][j] == 0 || A[i][j - 1] == 0 || A[i][j + 1] == 0) {
			// û�ҵ��� ���� �� ĭ�� �ִ� ���
			
			// �ݽð� �������� 90�� ȸ��
			d = (d == 0) ? 3 : d - 1;

			if (d == 0) {
				// ������ ���
				if (A[i - 1][j] == 0) i--;				
			}
			else if (d == 1) {
				// ������ ���
				if (A[i][j + 1] == 0) j++;
			}
			else if (d == 2) {
				// ������ ���
				if (A[i + 1][j] == 0) i++;
			}
			else {
				// ������ ���
				if (A[i][j - 1] == 0) j--;
			}
		}	
		else {
			// ��� û�ҵǾ� �ִٸ� ����
			if (d == 0) { // ����
				if (A[i + 1][j] != 1) i++;
				else break;
			}
			else if (d == 1) { // ����
				if (A[i][j - 1] != 1) j--;
				else break;
			}
			else if (d == 2) { // ����
				if (A[i - 1][j] != 1) i--;				
				else break;
			}
			else { // ����
				if (A[i][j + 1] != 1) j++;
				else break;
			}
		}
		
	}


	cout << sum;
}