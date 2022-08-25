#include <iostream>
using  namespace std;

int N;
int F, Nx;

int gcd(int a, int b) { // ��Ŭ���� ȣ����
	int c;
	while (b != 0) {
		c = a % b;
		a = b; b = c;
	}

	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	cin >> F;
	for (int i = 0; i < N-1; i++)
	{
		cin >> Nx;
		// (���� ù��° �� / �ִ� �����) / (�ش��ϴ� �� / �ִ� �����)
		int d = gcd(Nx, F); // ���� �ͺ��� �־���
		printf("%d/%d\n", F / d, Nx / d);
	}
}