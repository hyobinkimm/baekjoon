#include <iostream>
using namespace std;

int main() {
	int h = 0;
	int m = 0;

	// �Է��� �ð����� 45�� ���� ����� ��

	cin >> h >> m;

	if (h >= 0 && h <= 23 && m >= 0 && m <= 59) { // �Ϸ��� ���۰� ��
		if (m >= 45) { // 45�� �̻��̸� 45�и� ���� �ǹǷ�
			cout << h << " " << m - 45 << endl;
		}
		else if (h == 0) { // �� ������ ���ư��� 45�� �̸��� ��
			cout << 23 << " " << m + 60 - 45 << endl;
		}
		else // ���� ��Ȳ�̸� �ð��� 1�ð� �پ��
			cout << h - 1 << " " << m + 60 - 45 << endl;
	}
	return 0;
}