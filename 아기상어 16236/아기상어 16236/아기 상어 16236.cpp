#include <iostream>
#include <queue>
#include <memory.h>
using namespace std;

int N;
int A[21][21];
int dr[4] = { -1, 0, 1, 0 }; int dc[4] = { 0, -1, 0, 1 };
int answer = 987654321;

bool safe(int r, int c) {
    return (1 <= r && r <= N) && (1 <= c && c <= N);
}

bool canFeed(int size) {
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (0 < A[i][j] && A[i][j] < size) return true;
            // ������ �ϳ��� ������ true
        }
    }
    return false; // �ϳ��� ���� for�� �� ���������� false
}

void bfs(int r, int c, int size, int level, int time) {
    // size : �Ʊ� ��� ũ��, level : ���� ���� ��, time : �ð�

    int before = time; // ���� ���� ���� ���� �����Ͽ� �ð� ����(ū ����� ������ �����ٴ��� . .)

    if (!canFeed(size)) {
        // �Ʊ� ��� ũ�⿡ ���� �������� �� ���� �� ������
        answer = (answer < time) ? answer : time;
        return;
    }

    queue<pair<int, int>> q;
    q.push(make_pair(r, c));

    int dist[21][21];
    memset(dist, -1, sizeof(dist)); // �� -1�� �ʱ�ȭ
    dist[r][c] = 0;

    int min_dist = 987654321;
    while (!q.empty()) {
        int rr = q.front().first;
        int cc = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++) {
            // ����, ����, �Ʒ���, ������
            int new_r = rr + dr[i]; int new_c = cc + dc[i];
            if (safe(new_r, new_c) && A[new_r][new_c] <= size && dist[new_r][new_c] == -1) {
                // �ش� �������� �� �� �ְ� ó�� ���� ���̶��
                dist[new_r][new_c] = dist[rr][cc] + 1; // �� �������� ���� �ּڰ� ������Ʈ
                q.push(make_pair(new_r, new_c));

                if (0 < A[new_r][new_c] && A[new_r][new_c] < size) {
                    // ���� �� �ִٸ�                    
                    if (dist[new_r][new_c] < min_dist) {
                        // ������ �Ÿ��� �ּڰ��̶��
                        min_dist = dist[new_r][new_c]; // ����
                        r = new_r; c = new_c; // ������ Ž���� ��ǥ ���� (�Ծ��ݾ�)
                    }
                    else if (dist[new_r][new_c] == min_dist) {
                        // �ּڰ��� �����ϴٸ�
                        // ���� ���� �����鼭 ������ �����ؾ� ��
                        if (new_r < r || (new_r == r && new_c < c)) {
                            r = new_r; c = new_c;
                        }
                    }
                }
            }
        }
    }

    if (min_dist == 987654321) {
        // �ּڰ� ������ ���ߴ� == ���� ���� ����
        time = before; 
        answer = (answer < time) ? answer : time;
        return;
    }
    else {
        // �ּڰ� ������ �ߴٸ�
        // ����� ���� ���̹Ƿ�
        time = dist[r][c]; // ����⸦ ���� ��ġ�� �ð��̶� ������
        A[r][c] = 0; // �Ծ����ϱ� 0

        level++;
        if (level == size) {
            size++;
            level = 0;
        }
    }
    
    bfs(r, c, size, level, before + time); // ���� �ð��� ���Ӱ� �߰��� �ð� ������

}

int main() {
    int r = 0, c = 0;
    cin >> N;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int input;
            cin >> input;
            A[i][j] = input;
            if (input == 9) {
                r = i; c = j;
                A[i][j] = 0;
            }

        }
    }

    bfs(r, c, 2, 0, 0);

    cout << answer;
}