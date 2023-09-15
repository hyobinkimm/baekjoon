#include <iostream>
#include <vector>
using namespace std;

int N, K;
vector<pair<int, int >> A;
// first : �����̾Ʈ ��ȣ(�Һ�)
// second : �����̾Ʈ ��ȣ�� ������
// A�� index : �ǽð����� ������Ʈ �Ǵ� ��ġ
// A[0] : �ø��� ��ġ
// A[N-1] : ������ ��ġ
int Robot[101]; // �κ��� ���� ��ġ

void print() {
	cout << "--" << endl;
	for (int i = 0; i < 2 * N; i++) {
		cout << A[i].first << " ";
	}
	cout << endl;
	for (int i = 0; i < 2 * N; i++) {
		cout << A[i].second << " ";
	}
	cout << endl;
	for (int i = 0; i < N; i++) {
		cout << Robot[i] << " ";
	}
	cout << "\n--" << endl;

}

bool checkBelt() {
	int cnt = 0;
	for (auto a : A) {
		if (a.second == 0) cnt++;
		if (cnt >= K) return false; // ������ ���Ѱ� K�� �̻��̸� false
	}

	return true;
}

void minusDurability(int index) {
	// index�� �����̾Ʈ�� ������ 1 ���
	A[index].second--;
}

void rotate() {
	// ��Ʈ ȸ��
	pair<int, int> temp, before;
	pair<int, int> index_0 = A[A.size() - 1];
	before = A[0];
	for (int i = 0; i < A.size() - 1; i++) {
		// 1 ~ ������ �ε������� ����
		temp = A[i + 1]; // �̸� ���
		A[i + 1] = before; // A[i+1] ������Ʈ�ϰ�
		before = temp; // before�� �Ʊ� ����� temp �ֱ�
	}
	A[0] = index_0; // �� ������ �� �̸� �����ߴ��� A[0]�� �ֱ�

	// �κ� ȸ��
	int temp_,before_;
	before_ = Robot[0];
	Robot[0] = 0; // �׳� �̴� ���̹Ƿ� 0
	for (int i = 0; i < N - 1; i++) {
		temp_ = Robot[i + 1];
		Robot[i + 1] = before_;
		before_ = temp_;

		if (Robot[i + 1] == 1 && i + 1 == N - 1) {
			// i+1�� �κ��� �ְ� i+1�� ������ ��ġ(N-1)���
			Robot[i + 1] = 0; // ����
		}
	}
}

bool isRobot(int index) {
	// �ش� �ε����� �κ� �ִ���
	if (Robot[index] != 0) return true; // �κ� �ִ�
	return false;
}

bool getDurability(int index) {
	// �ش� �ε����� �������� 1�̻�����
	if (A[index].second >= 1) return true; 
	return false;
}

void move() {
	// �κ� �̵�
	for (int i = N - 2; i > 0; i--) {
		// ���� ���� ��Ʈ�� �ö� �ͺ��� Ž���ؾߵǹǷ� ���� Ž��
		if (Robot[i] != 0) {
			// �ش� �ε����� �κ��� �ִٸ�
			if (!isRobot(i + 1) && getDurability(i + 1)) {
				// ���� �ε����� �κ� ���� ������ 1 �̻��̸�
				Robot[i + 1] = 1;
				Robot[i] = 0;
				minusDurability(i + 1);
				if (i + 1 == N - 1) {
					// �̵��ؼ� ������ �Ǹ�
					Robot[i + 1] = 0;
				}
			}
		}
	}
}


int main() {
	cin >> N >> K;

	for (int i = 1; i <= 2 * N; i++) {
		int input;
		cin >> input;
		A.push_back(make_pair(i, input));
	}

	int order = 0; // �ܰ� ����
	while (1) {
		order++; 
		rotate(); // 1�ܰ�
		move(); // 2�ܰ�

		// 3�ܰ�
		if (A[0].second != 0) {
			Robot[0] = 1; // �ø��� ��ġ�� �κ� �ø�
			minusDurability(0);
		}

		// 4�ܰ�
		if (!checkBelt()) {
			// K�� �̻� �������� �������ٸ� ����
			cout << order;
			break;
		}
	}
}