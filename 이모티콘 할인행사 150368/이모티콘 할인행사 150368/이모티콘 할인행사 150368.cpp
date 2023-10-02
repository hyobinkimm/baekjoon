#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<pair<int, int>> ans;
vector<vector<int>> users_;
vector<int> emoticons_;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first > b.first;
}

// dfs
// sale - �̸�Ƽ���� ������
// index - �̸�Ƽ���� index
// costs - �� ����ڵ��� �̸�Ƽ�� ���� ���
// costs�� �迭�� �ϸ� call by reference�� �Ǳ� ������ �ȵ�
// costs�� vector�� �����Ͽ� call by value�� �ǵ��� �ؾ���
void dfs(int sale, int index, vector<int> costs) {
    if (index >= emoticons_.size()) {
        int plus = 0; int cost = 0;
        for (int i = 0; i < users_.size(); i++) {
            if (costs[i] >= users_[i][1]) {
                // ���� ����� ��� ������ �Ѿ��
                plus++; // �÷��� ���� ����
            }
            else {
                cost += costs[i];
            }
        }
        ans.push_back(make_pair(plus, cost)); // ������, ����
        return;
    }

    for (int i = 0; i < users_.size(); i++) {
        if (users_[i][0] <= sale) {
            // user�� �� ������ �̻��� �� ��
            costs[i] += emoticons_[index] * (1 - sale * 0.01);
        }
    }

    dfs(40, index + 1, costs);
    dfs(30, index + 1, costs);
    dfs(20, index + 1, costs);
    dfs(10, index + 1, costs);
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    users_ = users;
    emoticons_ = emoticons;

    int n = users.size();
    vector<int> costs(n, 0);

    dfs(40, 0, costs);
    dfs(30, 0, costs);
    dfs(20, 0, costs);
    dfs(10, 0, costs);

    sort(ans.begin(), ans.end(), cmp);

    answer.push_back(ans[0].first);
    answer.push_back(ans[0].second);
    return answer;
}

int main() {
    vector<vector<int>> users = { {40, 10000}, {25, 10000} };
    vector<int> emoticons = { 7000,9000 };
    vector<int> answer = solution(users, emoticons);
    
    cout << "[" << answer[0] << ", " << answer[1] << "]";
}