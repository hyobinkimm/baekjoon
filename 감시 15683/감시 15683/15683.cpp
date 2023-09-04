#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

int N, M;
int A[9][9];
vector<pair<int, int>> cctv;
int dr[4] = { 0,1,0,-1 }; int dc[4] = { 1,0,-1,0 }; // �� �� �� �� 
int answer = 64;

// default ���� ���س���
// 1�� CCTV : �� (4)
// 2�� CCTV : ���� (2)
// 3�� CCTV : �ϵ� (4)
// 4�� CCTV : ���ϵ� (4)
// 5�� CCTV : �������� (1)

// 0 : ��, 1 : ��, 2 : ��, 3 : ��

int blind_spot() {
    int cnt = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (A[i][j] == 0)cnt++;
        }
    }

    return cnt;
}

bool safe(int r, int c) {
    return (1 <= r && r <= N) && (1 <= c && c <= M);
}

void check(int r, int c, int dir) {
    dir %= 4; // 0<=dir<=3
    int new_r = r; int new_c = c;
    while (1) { 
        new_r += dr[dir];
        new_c += dc[dir];
        if (!safe(new_r, new_c) || A[new_r][new_c] == 6) return; // ���� ���̰ų� ���̸� �н�
        if (safe(new_r, new_c) && A[new_r][new_c] == 0)A[new_r][new_c] = 10; // ���ñ����̸� 10���� update
    }
}

void dfs(int index) {
    if (index == cctv.size()) {
        int temp_res = blind_spot();
        answer = (answer < temp_res) ? answer : temp_res;
        return;
    }
    int r = cctv[index].first;
    int c = cctv[index].second;

    // ���� �迭 ����
    int backup[9][9];
    
    for (int dir = 0; dir < 4; dir++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                backup[i][j] = A[i][j]; // backup�� ���� A ����
            }
        }

        if (A[r][c] == 1) {
            check(r, c, dir);
        }
        if (A[r][c] == 2) {
            check(r, c, dir);
            check(r, c, dir + 2);
        }
        if (A[r][c] == 3) {
            check(r, c, dir);
            check(r, c, dir + 3);
        }
        if (A[r][c] == 4) {
            // 0 2 3 (���ϵ�), 1 3 4 (�� �� ��)
            check(r, c, dir);
            check(r, c, dir + 3);
            check(r, c, dir + 2);
        }
        if (A[r][c] == 5) {
            check(r, c, dir);
            check(r, c, dir + 1);
            check(r, c, dir + 2);
            check(r, c, dir + 3);
        }

        dfs(index + 1); // index �ٲٰ�
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= M; j++) {
                A[i][j] = backup[i][j]; // ������ A�� ������ν� ���ο� dir Ž�� �غ� �Ϸ�
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
        for (int j = 1; j <= M; j++) {
            int input;
            cin >> input;
            A[i][j] = input;
            if (1 <= input && input <= 5) {
                // CCTV���
                cctv.push_back(make_pair(i, j));
            }
        }
    }    
    dfs(0);

    cout << answer;
    return 0;
}