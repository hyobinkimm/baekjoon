#include <iostream>
#include <cmath>
using namespace std;

int N;
int cnt; // Queen�� �������� ����� ��
int col[16]; // col[i] = j : i�� j��

void solve(int row) { // ���� �����̸鼭 �� ����
    if (row > N) { // ��ü ���� �� ���Ҵٴ� �� N-Queen ������ �����Ѵٴ� ��
        cnt++; // ����� �� ����
        return;
    }

    for (int i = 1; i <= N; i++) { // ����ŭ �ݺ�
        bool is_no = false; // N-Queen ��Ģ�� ����Ǵ��� �������� bool ����
        col[row] = i; // row�� i���� Queen�� ���Ҵٸ�
        for (int k = 1; k < row; k++) { // �� �� ��鿡 �ִ� Queen����� ��Ģ�� ����Ǵ���
            if (col[k] == col[row] || abs(col[k] - col[row]) == abs(k - row)) {
                // ���� ���̰ų� �밢���� �ִٸ�
                is_no = true; // N-Queen ��Ģ ����
                break;
            }
        }
        if (is_no == true) { // ���� ���� �� ��Ģ�� ����ǹǷ�
            col[row] = 0; // �Ҵ����־��� �� �� ������
        }
        else { // ��Ģ�� ������ ����ߴٸ�
            solve(row + 1); // ���� �࿡�� ���캸��
            col[row] = 0; // �ٸ� ������ backtracking
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    solve(1);
    printf("%d", cnt);

}
