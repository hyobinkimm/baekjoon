#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

vector<vector<string>> tickets_;
bool visited[10000];
vector<string> result;
bool isDone;

void dfs(string start, vector<string> ans, int index) {
    if (isDone) return; // ���ĺ� ���̹Ƿ� �� �� �����Ǹ� �����Ŵ
    if (ans.size() == tickets_.size()) {
        ans.push_back(tickets_[index][1]); // �� ������ ������ push_back
        result = ans;
        isDone = true;
        return;
    }
    for (int i = 0; i < tickets_.size(); i++) {
        if (tickets_[i][0] == start && !visited[i]) {
            // �湮���� �ʾҴ� �����
            visited[i] = true;
            ans.push_back(tickets_[i][0]);
            dfs(tickets_[i][1], ans, i);
            visited[i] = false;
            ans.pop_back();
        }
    }
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end()); // ���ĺ��� ����

    tickets_ = tickets;

    dfs("ICN", {}, -1);

    return result;
}

int main() {
    vector<vector<string>> tickets = { {"ICN", "JFK"} ,{"HND", "IAD"},{"JFK", "HND"} };
    vector<string> answer = solution(tickets);

    for (auto x : answer) {
        cout << x << " ";
    }
}