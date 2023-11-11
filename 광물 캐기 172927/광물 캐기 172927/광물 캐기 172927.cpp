#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// ��� �����ϴ� ���� : diamond, iron, stone ��

// minerals : 8�� => 2�� �ʿ�
// minerals : 11�� => 3�� �ʿ�
// n�� �ʿ��� �� dia, iron, stone ������ ����
// ������ 5���� ����

// v[0][0] = 0��° �׷��� ���̾Ƹ��� ������ ���� �Ƿε�
// v[0][1] = 0��° �׷��� ö�� ������ ���� �Ƿε�
// v[0][2] = 0��° �׷��� ���� ������ ���� �Ƿε�
// 1<=�׷��� ��<=10

bool cmp(vector<int> a, vector<int>b) {
    if (a[2] == b[2]) {
        if (a[1] == b[1]) return a[0] > b[0];
        else return a[1] > b[1];
    }
    return a[2] > b[2];
}


int solution(vector<int> picks, vector<string> minerals) {
    int answer = 0;
    int dia = picks[0]; int iron = picks[1]; int stone = picks[2];
    int k = 0;
    int num = picks[0] + picks[1] + picks[2];

    vector<vector<int>> v(minerals.size() / 5 + (minerals.size() % 5 == 0 ? 0 : 1), vector<int>(3, 0));

    for (int i = 0; i < minerals.size(); i += 5) {
        int dia_sum = 0; int iron_sum = 0; int stone_sum = 0;
        for (int j = i; j < i + 5; j++) {
            if (j >= minerals.size() || j >= num * 5) break; // ���� �� Ž���߰ų�, ���Ǵ� ���� ���� �ѱ�� ���
            if (minerals[j] == "diamond") {
                dia_sum += 1; iron_sum += 5; stone_sum += 25;
            }
            else if (minerals[j] == "iron") {
                dia_sum += 1; iron_sum += 1; stone_sum += 5;
            }
            else {
                dia_sum += 1; iron_sum += 1; stone_sum += 1;
            }
        }
        v[k][0] = (dia_sum);
        v[k][1] = (iron_sum);
        v[k][2] = (stone_sum);
        k++;
    }

    sort(v.begin(), v.end(), cmp); // �Ƿε� ���� ������ �������� ����

    // �Ƿε��� ���� �ͺ��� ���̾� ��� �����    
    int i = 0;
    while (1) {
        if (i >= k) break; // ���� �̹� �� ĺ���� ����
        if (dia > 0) {
            answer += v[i][0];
            dia--;
        }
        else if (iron > 0) {
            answer += v[i][1];
            iron--;
        }
        else if (stone > 0) {
            answer += v[i][2];
            stone--;
        }
        else break; // ��� �� ������ ����
        i++;
    }

    return answer;
}

int main() {
    vector<int> picks = { 1,3,2 };
    vector<string> minerals = { "diamond", "diamond", "diamond", "iron", "iron", "diamond", "iron", "stone" };
    cout << solution(picks, minerals);
}