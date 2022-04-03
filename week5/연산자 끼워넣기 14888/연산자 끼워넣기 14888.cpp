#include <iostream>
#include <algorithm>
using namespace std;

int n;
int num[12];
int opr[4];
int maximum = -1000000000; // ��� ������ 10�� ���� -10�� �̻��̹Ƿ�
int minimum = 1000000000;

// ����ߴ� �����ڴ� ��� Ȯ���ϴ���? -> �����ڸ� �Ѱ�����
// checked �Լ��� �̿��� ��� �����ڸ� ����ߴ��� üũ��

bool checked(int p, int mi, int mu, int di) {
	if (p == opr[0] && mi == opr[1] &&
		mu == opr[2] && di == opr[3]) {
		return true;
	}
	return false;
}
void f(int a, int x, int plus, int minus, int multi, int divide) {
	if (checked(plus, minus, multi, divide) == true) { // ��� �����ڸ� ����ߴٸ�
		maximum = max(a, maximum); // �ִ�, �ּ� ����
		minimum = min(a, minimum);
		return; // �Լ� ����
	}

	if (opr[0]>plus) { // ���� �����ڸ� �� ������� �ʾҴٸ�
		f(a + num[x + 1], x+1, plus + 1, minus, multi, divide); // �����ڸ� ��������Ƿ� +1
	}
	if (opr[1]>minus) {
		f(a - num[x + 1], x+1, plus, minus + 1, multi, divide);
	}
	if (opr[2]>multi) {
		f(a * num[x + 1], x+1, plus, minus, multi + 1, divide);
	}
	if (opr[3]>divide) {
		f(a / num[x + 1], x+1, plus, minus, multi, divide + 1);
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++)
	{
		cin >> opr[i];
	}

	f(num[0], 0, 0, 0, 0, 0);

	cout << maximum << "\n" << minimum;
}