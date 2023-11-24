#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <queue>
#include <cmath>
using namespace std;

int dr[4] = { 1,0,-1,0 }; int dc[4] = { 0,1,0,-1 };
vector<vector<int>> table_; vector<vector<int>> game_;
bool visited[51][51];
int R, C;
int result;

// �ִ��� ���� ������ �־���� 
// ����ִ� �� ����
// �� ���� table�� �ִ� �������� ä�� �� �ִ��� 

struct G {
    int cnt; // ��� ����
    vector<pair<int, int>> p; // �ش� ����� ���� �̵��� ��ǥ 
    pair<int, int> max_rc; // �ش� ����� �ִ� ��ǥ
    pair<int, int> min_rc; // �ش� ����� �ּ� ��ǥ
};

struct G gg[2500];

bool safe(int r, int c) {
    return 0 <= r && r < R && 0 <= c && c < C;
}

vector<pair<int, int>> translate_origin(vector<pair<int, int>> v) {
    // ���� �̵� (���̳ʽ� ��ǥ ���� �ʵ���)
    pair<int, int> min_rc;
    int min_r = 51, min_c = 51;
    for (int j = 0; j < v.size(); j++) {
        min_r = min(v[j].first, min_r); min_c = min(v[j].second, min_c);
    }

    min_rc = make_pair(min_r, min_c);

    // ���� �̵� 
    for (int i = 0; i < v.size(); i++) {
        v[i].first -= min_rc.first;
        v[i].second -= min_rc.second;
    }

    sort(v.begin(), v.end()); // �����ؾ� ���߿� ���� ���� �� ���� 
    return v;
}

vector<pair<int, int>> rotate(vector<pair<int, int>> v) {
    int center_r = v[0].first; int center_c = v[0].second; // ���� ù ��ǥ �������� ȸ�� (���� �ϵ� �������)

    int angle = 90; // 90���� �������� ǥ��
    int s = 1; // sin 90 = 0
    int c = 0; // cos 90 = 0

    for (int i = 0; i < v.size(); i++) {
        // �߽��� �������� ��ǥ�� �̵�
        v[i].first -= center_r;
        v[i].second -= center_c;

        // ȸ�� ����� ���� (�� �̷��� �Ȱ��� �𸣰���)
        int rotated_r = v[i].first * c - v[i].second * s;
        int rotated_c = v[i].first * s + v[i].second * c;

        // �߽��� �ٽ� ������
        rotated_r += center_r; rotated_c += center_c;
        v[i].first = rotated_r; v[i].second = rotated_c;
    }

    v = translate_origin(v); // ���̳ʽ� ��ǥ�� ���� �ʰ� ���� �̵� 

    return v;
}

void bfs_table(int r, int c, int z) {
    queue<pair<int, int>> q;

    int cnt = 0; // ����� �����ϴ� ���簢���� ����

    q.push(make_pair(r, c));
    visited[r][c] = true;
    gg[z].p.push_back(make_pair(r, c));
    cnt++;

    while (!q.empty()) {
        int rr = q.front().first; int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            if (safe(rr + dr[i], cc + dc[i]) && !visited[rr + dr[i]][cc + dc[i]]
                && table_[rr + dr[i]][cc + dc[i]] == 1) { // ��� �߰�
                visited[rr + dr[i]][cc + dc[i]] = true;
                gg[z].p.push_back(make_pair(rr + dr[i], cc + dc[i]));
                cnt++;
                q.push(make_pair(rr + dr[i], cc + dc[i]));
            }
        }
    }
    gg[z].cnt = cnt; // �ش� ����� �����ϴ� ���簢���� ���� ����
}

void bfs_game(int r, int c, int piece_cnt) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> v; // game_board�� ����ִ� �κ� ��� 

    int cnt = 0; // ����� �����ϴ� ���簢���� ����

    q.push(make_pair(r, c));
    v.push_back(make_pair(r, c));
    visited[r][c] = true;
    cnt++;

    while (!q.empty()) {
        int rr = q.front().first; int cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            if (safe(rr + dr[i], cc + dc[i]) && !visited[rr + dr[i]][cc + dc[i]]
                && game_[rr + dr[i]][cc + dc[i]] == 0) {
                visited[rr + dr[i]][cc + dc[i]] = true;
                v.push_back(make_pair(rr + dr[i], cc + dc[i]));
                cnt++;
                q.push(make_pair(rr + dr[i], cc + dc[i]));
            }
        }
    }

    // ��ĭ ���� �̵�
    v = translate_origin(v);

    // ���� �������� ��, ȸ���ϸ� ������
    bool isDone = false;
    for (int i = 0; i < piece_cnt; i++) {
        if (cnt == gg[i].cnt) { // ������ ������
            for (int j = 0; j < 4; j++) { // 4�� ȸ����Ű��
                if (v == gg[i].p) { // ���ٸ�
                    result += cnt;
                    gg[i].p = {}; // �����ϱ� �� �迭�� ���� �ٽô� ������
                    isDone = true;
                    break;
                }
                else v = rotate(v); // ���� �ʴٸ� ȸ��                 
            }
        }
        if (isDone)break; // �����̸� ����
    }
}

int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    R = game_board.size();
    C = R;
    table_ = table; game_ = game_board; // �������� ó��

    // table
    int piece_cnt = 0;
    for (int i = 0; i < table.size(); i++) {
        for (int j = 0; j < table.size(); j++) {
            if (table[i][j] == 1 && !visited[i][j]) {
                bfs_table(i, j, piece_cnt);
                piece_cnt++; // ����� ����
            }
        }
    }

    // ���� �̵� 
    for (int i = 0; i < piece_cnt; i++) gg[i].p = translate_origin(gg[i].p); // ���ϱ� ������
    

    // visited �ʱ�ȭ
    for (int i = 0; i < table.size(); i++) {
        memset(visited[i], false, sizeof(bool) * table.size());
    }

    // game_board�� ��
    for (int i = 0; i < game_board.size(); i++) {
        for (int j = 0; j < game_board.size(); j++) {
            if (game_board[i][j] == 0 && !visited[i][j]) bfs_game(i, j, piece_cnt);            
        }
    }

    return result;
}

int main() {
    vector<vector<int>> game_board = { {1, 1, 0, 0, 1, 0}, { 0,0,1,0,1,0 }, { 0,1,1,0,0,1 }, { 1,1,0,1,1,1 }, { 1,0,0,0,1,0 }, { 0,1,1,1,0,0 } };
    vector<vector<int>> table = { {1,0,0,1,1,0 }, { 1,0,1,0,1,0 }, { 0,1,1,0,1,1 }, { 0,0,1,0,0,0 }, { 1,1,0,1,1,0 }, { 0,1,0,0,0,0 } };

    cout << solution(game_board, table);
}