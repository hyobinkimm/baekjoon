#include <iostream>
using namespace std;

unsigned long int N, M; // M�� ���� ���

// two pointer :����Ʈ�� ���������� ������ �� �� ���� ���� ��ġ�� ����ϸ� ó���ϴ� �˰���
// 1. �������� ������ ù��° ������ �ε����� ����Ű����
// 2. ���� �κ��� ���� M�� ���ٸ� count
// 3. ���� �κ� �� < M -> end ++
// 4. ���� �κ� �� >= M -> start++
// 5. ��� ��츦 Ȯ���� ������ 2-4�� ���� �ݺ�

// ��� ��츦 Ȯ���� ���� : start �Ǵ� end�� index�� N�� �ʰ��� ���

unsigned long int cnt;
unsigned long int s, e;
unsigned long int sum;

int A[10001]; // index 1���� ����ϹǷ� +1��ŭ �迭�� �����

int main() {
	cin >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		cin >> A[i];
	}

	s = 1; e = 1; // index 1���� ����
	
	while (1) {
		if ((s > N) || (e > N))break; // index�� �ʰ��ϸ� break
		sum = 0;
		for (int i = s; i <= e; i++) { // A[s]~A[e]���� ����
			sum += A[i];
		}
		if (sum == M) { // ���ϴ� ���� ������ 
			cnt++; // count ����
			s++; // start ���� ��Ŵ
		}
		else if (sum < M)e++; // �� < ���ϴ� ���̸� end ������Ŵ(�� ���ؾ� �ϹǷ�)
		else s++; // �� > ���ϴ� ���̸� start ������Ŵ(�� �ٿ��� ���ϴ� ���� ��������Ƿ�)
	}
	printf("%d", cnt);
	
	return 0;
}