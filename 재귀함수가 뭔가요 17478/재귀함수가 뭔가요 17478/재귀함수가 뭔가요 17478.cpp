#include <iostream>
using namespace std;

int N;

void f(int x) {
	if (N == x) {
		for (int i = 0; i < 4*x; i++) {
			printf("_");
		}
		printf("\"����Լ��� ������?\"\n");
		for (int i = 0; i < 4*x; i++) {
			printf("_");
		}
		printf("\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n");

	}
	else {
		for (int i = 0; i < 4*x; i++) {
			printf("_");
		}
		printf("\"����Լ��� ������?\"\n");
		for (int i = 0; i < 4*x; i++) {
			printf("_");
		}
		printf("\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n");
		for (int i = 0; i < 4 * x; i++) {
			printf("_");
		}
		printf("���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n");
		for (int i = 0; i < 4 * x; i++) {
			printf("_");
		}
		printf("���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n");
		
		f(x + 1);
	}
	for (int i = 0; i < 4*x; i++) {
		printf("_");
	}
	printf("��� �亯�Ͽ���.\n");

	return;
}

int main() {
	printf("��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n");
	cin >> N;
	f(0);
}