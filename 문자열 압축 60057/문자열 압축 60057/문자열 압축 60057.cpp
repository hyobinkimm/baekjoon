#include <string>
#include <vector>
#include <cmath>
#include <iostream>
using namespace std;

int minimum = 1001;

int solution(string s) {
    int size = s.length();

    for (int i = 1; i < s.length(); i++) {
        string result = ""; // ����� ���ڿ��� ��� ���ڿ�
        // ���ڿ� i���� ����
        string cur = ""; string tmp = "";
        int t;
        for (int j = 0; j < s.length(); j += t * i) {
            cur = s.substr(j, i);
            t = 1;
            while (1) {
                if (j + t * i > s.length()) break;
                tmp = s.substr(j + t * i, i);
                if (cur != tmp) { // �ٸ��ٸ�
                    break;
                }
                t++;
            }
            if (t > 1) {// �ι� �̻�
                result += to_string(t); // ���� ���� �߰�
            }
            result += cur;

        }

        int len = result.length();
        minimum = min(minimum, len);
    }


    if (minimum == 1001) {
        // for���� ���� ���� ��� : ���ڿ� ���� 1
        minimum = 1;
    }
    return minimum;
}

int main() {
    string s = "aabbaccc";
    cout << solution(s);

}