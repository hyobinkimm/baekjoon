#include <iostream>
using namespace std;
#define MAX 1000001

int N;
int A[MAX];
int B, C;

long int min_visor; // ���� ���� �ִ��� (10^6)*(10^6) = 10^12

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
	}
	cin >> B >> C;

	min_visor += N; // �Ѱ������� �����帶�� �־�� �ϹǷ�

	for (int i = 1; i <= N; i++)
	{
		A[i] -= B; // �Ѱ������� ����ϴ� �л� ����
		if (A[i] < 0) A[i] = 0; // too much�� 0���� ����(������ ���� �ʵ���)
	}

	for (int i = 1; i <= N; i++)
	{
		min_visor += A[i] / C; 
		if (A[i] % C > 0) { // �������� �ִٸ�
			min_visor++; // ���� 1�� �߰�
		}
	}

	cout << min_visor;
}