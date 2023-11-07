#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

map<string, vector<pair<int, int>>> m;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) {
        return a.first < b.first; // ���� ��ȣ ���� ��
    }
    return a.second > b.second;
}

bool cmp2(pair<string, vector<pair<int, int>>> a, pair<string, vector<pair<int, int>>> b) {
    // �帣�� ���Ƚ��
    int sum_a = 0; int sum_b = 0;
    for (int i = 0; i < a.second.size(); i++) {
        sum_a += a.second[i].second;
    }
    for (int i = 0; i < b.second.size(); i++) {
        sum_b += b.second[i].second;
    }

    return sum_a > sum_b;
}

// m["classic"] = (0, 500), (2, 150), (3, 800)
// 1. ���� �뷡�� ���� ����� �帣
// 2. �帣 ������ ���� ����� �뷡 ����
// 3. ���Ƚ�� ������ ������ȣ ���� �뷡 ����

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    for (int i = 0; i < genres.size(); i++) {
        m[genres[i]].push_back(make_pair(i, plays[i]));
    }
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        sort(iter->second.begin(), iter->second.end(), cmp); // vector ���� �������� ����
    }

    vector<pair<string, vector<pair<int, int>>>> v(m.begin(), m.end()); // vector�� ��ȯ

    sort(v.begin(), v.end(), cmp2); // �� ���� ����

    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].second.size(); j++) {
            if (j < 2) answer.push_back(v[i].second[j].first); // �ִ� 2��
        }
    }



    return answer;
}

int main() {
    vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
    vector<int> plays = { 500, 600, 150, 800, 2500 };

    vector<int> answer = solution(genres, plays);
    for (auto x : answer) {
        cout << x <<  " ";
    }
}