#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int N, M;

unordered_map<int, string> myunorderedmap1;
unordered_map<string, int> myunorderedmap2;

bool isNumber(const string& str) {
	for (char const& c : str) {
		if (isdigit(c) == 0)return false;
	}
	return true;
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
		myunorderedmap1.insert({ i + 1, input }); // key�� ������ ���
		myunorderedmap2.insert({ input, i + 1 }); // key�� ���ڿ��� ���
	}

	for (int i = 0; i < M; i++)
	{
		string input;
		cin >> input;
		if (isNumber(input)) { // ���ڷ� �ԷµǸ� ���ڿ� ���
			printf("%s\n", myunorderedmap1[stoi(input)].c_str());
		}
		else { // ���ڿ��� �ԷµǸ� ���� ���
			printf("%d\n", myunorderedmap2[input]);
		}
	}
}