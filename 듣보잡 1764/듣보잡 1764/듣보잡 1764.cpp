#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int N, M, cnt;
set<string> myset;
string Answer[500000];

bool cmp(string a, string b) { // ������ ����
	return a < b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;
		myset.insert(input);
	}

	for (int i = 0; i < M; i++)
	{
		string input;
		cin >> input;
		if (myset.find(input) != myset.end()) { // ã����
			Answer[cnt] = input;
			cnt++;
		}
		else { // ��ã���� pass
		}
	}
	sort(Answer, Answer + cnt, cmp); // ������ ����
	printf("%d\n", cnt); // �赵 && ����
	for (int i = 0; i < cnt; i++)
	{
		printf("%s\n", Answer[i].c_str());
	}
}