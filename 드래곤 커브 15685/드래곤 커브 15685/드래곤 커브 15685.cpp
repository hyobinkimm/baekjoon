#include <iostream>
#include <vector>
using namespace std;

int A[101][101];
int N;

int check() {
	int answer = 0;
	for (int i = 0; i <= 99; i++) {
		for (int j = 0; j <= 99; j++) {
			if (A[i][j] > 0 && A[i][j + 1] > 0
				&& A[i + 1][j] > 0 && A[i + 1][j + 1] > 0)
				answer++;
		}
	}
	return answer;
}

// ���� 90�� �ð�������� ȸ���ϴ� �Լ�
pair<int, int> rotatePoint(int x, int y, int center_x, int center_y) {
	int angle = 90; // 90���� �������� ǥ��
	int s = 1; // sin 90 = 0
	int c = 0; // cos 90 = 0

	// �߽��� �������� ��ǥ�� �̵�
	x -= center_x; y -= center_y;

	// ȸ�� ����� ���� (�� �̷��� �Ȱ��� �𸣰���)
	int rotated_x = x * c - y * s;
	int rotated_y = x * s + y * c;

	// �߽��� �ٽ� ������
	rotated_x += center_x; rotated_y += center_y;

	return make_pair(rotated_x, rotated_y);
}

bool safe(int x, int y) {
	return 0 <= x && x <= 100 && 0 <= y && y <= 100;
}

void print() {
	cout << "--A\n";
	for (int i = 0; i <= 6; i++) {
		for (int j = 0; j <= 6; j++) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		// x : ��, y : ��
		// A[y][x] ����

		// �巡�� Ŀ�� �����
		vector<pair<int, int>> v;
		v.push_back(make_pair(x, y)); // ������ �ֱ�
		A[y][x] = 1;

		// 0���� ó��
		if (d == 0) {
			// ������
			v.push_back(make_pair(x + 1, y));
			A[y][x+1] = 1;
		}
		else if (d == 1) {
			// ����
			v.push_back(make_pair(x, y - 1));
			A[y - 1][x] = 1;
		}
		else if (d == 2) {
			// ����
			v.push_back(make_pair(x - 1, y));
			A[y][x-1] = 1;
		}
		else {
			// �Ʒ���
			v.push_back(make_pair(x, y + 1));
			A[y+1][x] = 1;
		}

		for (int k = 1; k <= g; k++) {
			// �ش� ���븸ŭ �ݺ�
			vector<pair<int, int>> new_v; // �ش� ���뿡 ���Ӱ� �߰��Ǵ� ������ ��� ����
			pair<int, int> center = v[v.size() - 1]; // ���� �޾ƿ�
			for (int j = v.size() - 2; j >= 0; j--) {
				// ������ ȸ��
				// v.size()-2���� �����ϴ� ���� : ������ �ʿ����
				pair<int, int> rotate_p = rotatePoint(v[j].first, v[j].second, center.first, center.second);
				new_v.push_back(make_pair(rotate_p.first, rotate_p.second));
			}
			// ��� ȸ����Ų ������ ���Ϳ� ��Ҵٸ�
			// ��ǥ 1�� ������Ʈ
			for (auto p : new_v) {
				if (safe(p.first, p.second)) {
					// ���� ���� �ִ� ��쿡�� �迭�� ������Ʈ
					A[p.second][p.first] = 1; // y = p.second, x = p.first�� �� ����
				}
			}

			// ���� ���Ϳ� ���̱�
			vector<pair<int, int>>::iterator it = v.end();
			v.insert(it, new_v.begin(), new_v.end()); // ���� vector�� ����
		}
	}

	cout << check();
}