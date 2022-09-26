#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct xy {
	double x;
	double y;
};

struct xy xy[3];

bool cmp1(struct xy A, struct xy B) {
	if (A.x == B.x) {
		return A.y < B.y;
	}
	return A.x < B.x; // x �������� ����
}

double PITA(int x1, int y1, int x2, int y2) { // �� �� ������ ����
	return sqrt((y2 - y1) * (y2 - y1) + (x2 - x1) * (x2 - x1));
}

int main() {
	for (int i = 0; i < 3; i++)
	{
		cin >> xy[i].x >> xy[i].y;
	}

	sort(xy, xy + 3, cmp1);
	
	if ((xy[0].y - xy[1].y) * (xy[1].x - xy[2].x) == (xy[1].y - xy[2].y) * (xy[0].x - xy[1].x)) {
		// �� ������ 3���� ���� ������(���Ⱑ ������) �簢���� ����� �� �� ����
		// ������ ������(/)�� ���ٸ� division by zero�� �߻��� �� �����Ƿ� ������� ����
		cout << "-1.0";
	}
	else
	{
		double AB = PITA(xy[0].x, xy[0].y, xy[1].x, xy[1].y);
		double AC = PITA(xy[0].x, xy[0].y, xy[2].x, xy[2].y);
		double BC = PITA(xy[1].x, xy[1].y, xy[2].x, xy[2].y);
		double sum1 = 2 * (AB + AC);
		double sum2 = 2 * (AB + BC);
		double sum3 = 2 * (BC + AC);


		double maximum = max(sum3, max(sum1, sum2));
		double minimum = min(sum3, min(sum1, sum2));

		printf("%.16lf", (maximum - minimum));
	}
}