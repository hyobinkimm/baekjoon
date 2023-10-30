#include <string>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// [A B C D]
// [2 1 3 2] ���� Ŭ���� �켱���� ����
// A ���´ٰ� ť�� ����.. [B C D A]
// B ���´ٰ� ť�� ����.. [C D A B]
// C ���� [D A B]

queue<pair<int, int>> s;
vector<int> maxis;

int solution(vector<int> priorities, int location) {
    vector<int> order;
    int answer = 0;

    for (int i = 0; i < priorities.size(); i++) {
        s.push(make_pair(priorities[i], i));
        maxis.push_back(priorities[i]);
    }

    sort(maxis.begin(), maxis.end(), greater<>()); // ��������

    int cnt = 1;
    while (!s.empty()) {
        pair<int, int> tmp = s.front();
        int prior = tmp.first; int n = tmp.second;
        s.pop();

        if (prior < maxis[0]) {
            // �� ���� �켱������ �ִٸ�?
            s.push(make_pair(prior, n)); // �ٽ� �ֱ�
        }
        else {
            // �׷� ���μ��� ���ٸ� 
            maxis.erase(maxis.begin());

            if (location == n) {
                answer = cnt;
                break;
            }
            else cnt++;
        }
    }

    return answer;
}

int main() {
    vector<int> priorities = { 2,1,3,2 };
    int location = 2;
    cout << solution(priorities, location);
}