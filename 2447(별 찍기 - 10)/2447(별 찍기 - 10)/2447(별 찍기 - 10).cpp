#include <iostream>
using namespace std;

int n;

void star(int i, int j, int n) {
	if ((i/n) % 3 == 1 && (j/n) % 3 == 1)printf(" "); // ����� ���������
	else if (n/3==0) printf("*"); // n�� 1�̰� if���� �ش� �ȵǸ� *
	else {
		star(i, j, n / 3);
	}
}

int main() {
	// for���� 1���� �������� ������ ������ �ʹ� �޶����� ������ 0���� �ٲ�
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			star(i, j, n);
		}
		printf("\n");
	}
}