#include <iostream>
#include <cmath>
#include <string>
typedef long long int ll; // 2�� 50���� ũ�Ƿ�
using namespace std;

int d;  int A[50];
ll x; ll y;
ll a; ll b;
string input;

void quadtoxy(ll min_x, ll max_x, ll min_y, ll max_y, int i) {
	// ��и��� ��ǥ��
	if (i == d) { // ��и� �ڸ��� �� ��������
		x = min_x; y = min_y; // x, y�� ����
		return;
	}
	ll xmid = (min_x + max_x) / 2;
	ll ymid = (min_y + max_y) / 2;

	if (A[i] == 1) { // 1��и�
		quadtoxy(xmid, max_x, min_y, ymid, i + 1);
	}
	else if (A[i] == 2) { // 2��и�
		quadtoxy(min_x, xmid, min_y, ymid, i + 1);
	}
	else if (A[i] == 3) { // 3��и�
		quadtoxy(min_x, xmid, ymid, max_y, i + 1);
	}
	else { // 4��и�
		quadtoxy(xmid, max_x, ymid, max_y, i + 1);
	}
}

void xytoquad(ll min_x, ll max_x, ll min_y, ll max_y, int i) {
	// ��ǥ�� ��и�����
	if (i == d) { // ��и� �� á����
		return;
	}
	ll xmid = (min_x + max_x) / 2;
	ll ymid = (min_y + max_y) / 2;

	if (xmid <= x && x < max_x &&
		min_y <= y && y < ymid) { // 1��и�
		printf("1");
		xytoquad(xmid, max_x, min_y, ymid, i + 1);
	}
	else if (min_x <= x && x < xmid &&
		min_y <= y && y < ymid) { // 2��и�
		printf("2");
		xytoquad(min_x, xmid, min_y, ymid, i + 1);
	}
	else if (min_x <= x && x < xmid &&
		ymid <= y && y < max_y) { // 3��и�
		printf("3");
		xytoquad(min_x, xmid, ymid, max_y, i + 1);
	}
	else { // 4��и�
		printf("4");
		xytoquad(xmid, max_x, ymid, max_y, i + 1);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> d >> input;
	for (int i = 0; i < d; i++) {
		A[i] = input[i] - '0'; // char to int
	}

	ll n = 1;
	for (int i = 0; i < d; i++) {
		n *= 2; // ����� ��ǥ ������ 0~n-1
	}
	quadtoxy(0, n, 0, n, 0); // ��и��� ��ǥ��

	cin >> a >> b;
	b = (-b); // b�� ���� ���°�(���̳ʽ�) ��� ����� �����Ƿ� �ݴ�� ������ ��������
	x += a; y += b; 

	if (x >= n || x < 0 || y >= n || y < 0) { // ���� ���̸�
		printf("-1");
	}
	else {
		xytoquad(0, n, 0, n, 0);
	}
}