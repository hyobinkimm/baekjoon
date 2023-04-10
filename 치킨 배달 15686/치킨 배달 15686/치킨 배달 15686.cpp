#include <iostream>
#include <algorithm>
#include <vector>
#define MAX_INT 2147483647
using namespace std;

int N, M;

struct Point {
	int x; int y;
};

struct C {
	int x; int y; bool isvisited = false;
};

vector<Point> house;
vector<C> chicken;
int min_sum = MAX_INT; // ������ ġŲ �Ÿ�

/*
���� ����
�ִ� M�� ���� -> ����

�������� M���� ġŲ���� �̴´�
�� ������ M���� ġŲ�������� �Ÿ� �� �ּڰ����� ���Ͽ� ���Ѵ�
���� �ּҰŸ� ���� ������ ������ �Ÿ� ���� ���Ѵ�
*/

void distance() {	
	// �� ���� ���� ġŲ���� �ּҰŸ� ����
	int sum = 0;
	for (int i = 0; i < house.size(); i++) {
		int minimum = MAX_INT;
		for (int j = 0; j < chicken.size(); j++) {
			if (chicken[j].isvisited == true) {
				// ���õ� ġŲ���̶�� �Ÿ��� ����
				int dist= abs(chicken[j].x - house[i].x) + abs(chicken[j].y - house[i].y);
				minimum = (dist < minimum) ? dist : minimum;				
			}
		}
		sum += minimum; // �ش� ������ ���� �ּ� �Ÿ��� ġŲ�� ����
	}

	min_sum = (sum < min_sum) ? sum : min_sum;
}

void selectChicken(int index, int count) {
	if (count == M) {
		distance(); // ������ ��� �������� �Ÿ��� ����
	}
	else {
		// ���� �� �����ٸ�
		for (int i = index; i < chicken.size(); i++) {
			if (chicken[i].isvisited == false) {
				chicken[i].isvisited = true; // ���õ� ������ true��
				selectChicken(i + 1, count + 1); // ���� index���� �����Ͽ� ������ ����ؼ� ����
				chicken[i].isvisited = false;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int input;
			cin >> input;
			// ��ǥ�� ����
			if (input == 1) {
				// ���̸�
				house.push_back({ i,j });
			}
			else if (input == 2) {
				// ġŲ���̸�
				chicken.push_back({ i,j,false });
			}
		}
	}

	selectChicken(0, 0); // ġŲ�� ����

	cout << min_sum;	
}