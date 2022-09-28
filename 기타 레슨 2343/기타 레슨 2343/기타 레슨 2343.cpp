#include <iostream>
using namespace std;

int N, M;
int X[100000];
int minimum = 1000000000;

// 9 3
// 1 2 3 4 5 6 7 8 9
// 9���� ���Ǹ� 3���� ��緹�̿� ���� ��ƾ���
// 1 2 3 4 5 / 6 7 / 8 9 �ϸ�
// 1 2 3 4 5 = 15byte
// 6 7 = 13byte
// 8 9 = 17byte
// ��緹���� ũ��� �ּ� 17byte���� ��.
// �ٸ� ����� ���� ������� �� 17���� �� ���� ���� ����

// ���� ������ �ٸ� �� : ���� �� ���� Ǯ ���� ����. ������ �ڹٲ�� �ȵǱ� ����

// ��緹���� ũ��� �ּ� 1���� �ִ� sum(X)

void BinarySearch(int start, int end) {
	if (start > end) { // Ž�� �������� ����
		return;
	}
	int key = (start + end) / 2; // ��緹�� �ּڰ����� ����

	int s = 0;
	int cnt = M;
	bool isover = false;
	for (int i = 0; i < N; i++) {
		if (s + X[i] > key) { // i��° ���Ǹ� �־��� �� ��緹���� ũ�⺸�� ���� ���� ũ�Ⱑ ū ���
			cnt--;
			if (cnt == 0) { // �̰� ���ϸ� �ð� �ʰ�. ��緹�� �� ���� �ٷ� for�� ������
				isover = true;
				break;
			}
			i--;
			s = 0; // ���� �� ��ȭ�� �ʱ�ȭ
		}
		else {
			s += X[i]; // ��Ŀ���� ���� ������ �ִ� ��
		}
	}

	if (isover) { // ��緹�� ������ �ʰ��ؼ� ����ߴٸ� ��緹���� ũ�Ⱑ ���ڶ��� ��
		BinarySearch(key + 1, end);
	}
	else {
		if (key < minimum) {
			minimum = key;
		}
		BinarySearch(start, key - 1); // ��緹�� �� �۰� �� �� �ֳ� ã�ƺ���
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;

	int sum = 0;

	for (int i = 0; i < N; i++)
	{
		cin >> X[i];
		sum += X[i];
	}

	BinarySearch(1, sum); // ��緹�� ũ��� �ּ� 1���� �ִ� X ���ҵ��� �ձ���
	cout << minimum; // �ּ� ��緹�� ���
}