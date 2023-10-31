#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    map<int, int> m;

    for (auto n : nums) {
        m[n]++;
    }

    // ������ �� �ִ� ���ϸ� ���� ���� �ִ� ���ϸ� ���� �� �� �ּڰ�
    answer = min(nums.size() / 2, m.size()); // size�� �ϸ� Ʋ�� ..
    return answer;
}

int main() {
    vector<int> nums = { 3,1,2,3 };
    cout << solution(nums);
}