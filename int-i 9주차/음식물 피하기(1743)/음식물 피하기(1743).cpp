#include <iostream>
#include <queue>
using namespace std;

int n, m, k; // �Է�
int A[100][100]; int maximum = -1; // �Է� ũ�Ⱑ 100��ŭ�̹Ƿ� ���������� 101����, maximum �ʱ� ������ ���� �۰�
int dc[4] = { 1,0,-1,0 }, dr[4] = { 0,1,0,-1 }; // �밢������ �̵��� �� ����, ��/��
// �Ʒ� / ������ / �� / ����
// ��ǻ�Ϳ����� �迭
// ----------------------> ��
// |
// |
// |
// |
// |
// |
// | ��
int sum, before; // sum : ���Ĺ� ũ��, before : Ž�� �� / �ĸ� ������

struct VERTEX { int a, b; }; // x��, y��

void input() {
	cin >> n >> m >> k;

	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		A[x-1][y-1] = 1; // �迭�� 0���� �����ϹǷ� 1�� �ٿ��� ����
	}
}

void output() { // ���
	cout << maximum;
}

bool safe(int a, int b) { // �迭�� ũ�⸦ �Ѿ�� �� check
	return (0 <= a && a < 100) && (0 <= b && b < 100);
}

void bfs(int a, int b, int c) { // �ʺ� �켱 Ž��
	queue<VERTEX> Q; // x ��ǥ, y ��ǥ�� ��� queue ���� (LIFO)
	Q.push({ a,b });
	A[a][b] = c; // �̹� �������� ���� �����ϱ� ���ؼ� c�� ����
	while (!Q.empty()) { // ����ֱ� ������ �ݺ�
		VERTEX cur = Q.front(); // front�� cur�� �޾ƿ�
		Q.pop(); // �׸��� �װ��� �̾Ƴ�
		for (int i = 0; i < 4; i++) // �Ʒ� , ������ , ���� , ���� ������� Ž����
		{
			if (safe(cur.a + dc[i], cur.b + dr[i]) && // Ž���� ��ǥ�� �迭 ũ�� ���� �ְ�
				A[cur.a + dc[i]][cur.b + dr[i]] == before) { // ���� Ž�� ���̰�, �ű⿡ ���Ĺ� �����Ⱑ �ִٸ�
				sum++; // ���Ĺ� ũ�� 1 ����
				A[cur.a + dc[i]][cur.b + dr[i]] = c; // Ž���ߴٴ� ���� �˸��� ���� ���� c�� �ٲ���
				Q.push({ cur.a + dc[i], cur.b + dr[i] }); // 
			}
		}
	}
}

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			before = A[i][j];
			if (A[i][j] == 1) { // ���Ĺ� �����Ⱑ �ִٸ�
				sum = 1; // �ּ� ũ�� 1
				bfs(i, j, before + 1); // Ž���ߴ� ��ǥ�� ����ϱ� ���� before+1
				// bfs ������
				if (sum > maximum) { // �ִ� ���Ĺ� ũ�⸦ ���ؾ� �ϹǷ�
					maximum = sum; }
			}
		}
	}
}

int main() {
	input();
	solve();
	output();
}