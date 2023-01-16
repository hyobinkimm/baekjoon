#include <iostream>
using namespace std;

int N, M;
long long S[1000001]; 
long long L[1001] = { 1, };
long long sum;
long long R[1000001];

void f() {
	// 0~i���� ������ ���
	// ex) R[3] = 1 + 2 + 3 = 6
	for (int i = 1; i <= N; i++) {
		if (i == 1)R[i] = 1;
		else R[i] = i + R[i - 1];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	f(); // �ִ� N������ �������� ����ϸ� ��

	for (int i = 1; i <= N; i++)
	{
		long long temp; cin >> temp;
		S[i] = S[i - 1] + temp; // �Է°��� ������
	}

	for (int i = 1; i <= N; i++) {
		// �Է°����� M���� ���� ������ ���� L�迭�� ����
		// L[1] = �Էµ� ���� M���� ���� �������� 1�� �Է°����� ����
		L[S[i] % M]++;
	}

	for (int i = 0; i < M; i++) {
		if (L[i] - 1 >= 0) { // ���� �̷�� ��
			sum += R[L[i]-1];
		}
	}

	printf("%lld", sum);
}