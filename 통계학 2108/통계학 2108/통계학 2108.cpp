#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

typedef struct memo {
	int num;
	int cnt;
}memo;

memo m[500001];

int A[500001];
double result;
int N;

bool cmp1(memo a, memo b) {
	return a.num < b.num;
}

bool cmp2(memo a, memo b) {
	if (a.cnt == b.cnt) {
		a.num < b.num;
	}
	return a.cnt > b.cnt;
}
// �ݿø� �ϴ� �� floor(X+0.5)

// ������ : N���� ������ �� / N
// �߾Ӱ� : N���� ������ �����ϴ� ������ �������� ��� �� �߾ӿ� ��ġ�ϴ� ��
// �ֺ� : N���� ���� �� ���� ���� ��Ÿ���� ��
// ���� : �ִ� - �ּڰ�

int main() {
	cin >> N;

	int k = 0;

	for (int i = 0; i < N; i++)
	{
		int x;
		bool isit = false;
		cin >> x;
		result += x; // ������
		for (int j = 0; j < k; j++) {
			if (x == m[j].num) { // �̹� �Էµƾ��� �����
				printf("%d�� �̹� �Էµ� ����� ī��Ʈ�� �߽��ϴ�.\n", x);

				m[j].cnt++;
				isit = true;
				break;
			}
		}
		if (isit == true) {} // �̹� �Էµƾ��� ����� pass
		else { // ���� �Էµ� �����
			printf("%d�� �����ԷµǾ����ϴ�.\n", x);
			m[k].num = x;
			m[k].cnt++;
			k++;
		}
		A[i] = x;

	}
	for (int i = 0; i < k; i++) {
		printf("num: %d, cnt: %d | ", m[i].num, m[i].cnt);
	}
	printf("\n");
	// 1. ������
	cout << int(floor(result / double(N) + 0.5)) << endl;


	// 2. �߾Ӱ�
	sort(m, m + k, cmp1);
	sort(A, A + N);
	for (int i = 0; i < k; i++) {
		printf("num: %d, cnt: %d | ", m[i].num, m[i].cnt);
	}
	printf("\n");
	int maximum = m[k - 1].num;
	int minimum = m[0].num;
	cout << A[N / 2] << endl;

	// 3. �ֺ�
	sort(m, m + k, cmp2);
	for (int i = 0; i < k; i++) {
		printf("num: %d, cnt: %d | ", m[i].num, m[i].cnt);
	}
	printf("\n");
	if (m[0].cnt == m[1].cnt) { // �ֺ��� �� �� �̻��̸�
		cout << m[1].num << endl; // �� ��°�� ���� ��
	}
	else {
		cout << m[0].num << endl;
	}

	// 4. ����
	cout << maximum - minimum << endl;


}