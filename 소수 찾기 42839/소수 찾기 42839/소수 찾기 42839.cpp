#include <string>
#include <vector>
#include <cmath>
#include <iostream>
#include <algorithm>

using namespace std;
int A[10000000];

void make_prime_arr() {

    for (int i = 2; i < 10000000; i++) A[i] = 1; // A[1]�� �Ҽ� �ƴ�

    for (int i = 2; i < 10000000; i++) {
        if (A[i] == 0) continue; // �̹� �Ҽ��� �ƴϸ� �����(�װ��� ����� �Ҽ��� �ƴ��״�)
        for (int j = 2 * i; j < 10000000; j += i) {
            A[j] = 0; // �Ҽ��� �ƴ� �͵� �����
        }
    }
}


int ans[10000000]; // �Ҽ��� �̹� count�Ǿ����� �����ϱ� ���� �뵵
int solution(string numbers) {
    make_prime_arr(); // �Ҽ� ���� A[] �迭�� ����

    int answer = 0;
    vector<char> v;

    sort(numbers.begin(), numbers.end()); // next_permutation Ư���� �������� �����ؾ� ��� ����� ���� ����

    for (int i = 0; i < numbers.size(); i++)v.push_back(numbers[i]);

    do {
        string s = "";

        for (int i = 0; i < v.size(); i++) {
            s += v[i];

            if (A[stoi(s)] == 1) {
                // �Ҽ��� ���
                if (ans[stoi(s)] != 1) {
                    answer++;
                    ans[stoi(s)] = 1;
                }
            }
        }
    } while (next_permutation(v.begin(), v.end()));

    return answer;
}

int main() {

    string numbers = "011";

    cout << solution(numbers);
}