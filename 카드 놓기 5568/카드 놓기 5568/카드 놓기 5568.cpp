#include <iostream>
#include <string>
using namespace std;

int n, k;
string A[10];
bool visited[10];
int cnt;
string X[5040]; // �ִ� ���� �� �ִ� ���� 10*9*8*7=4940��
int x;

bool is_include(string T) { // ������� ������ �̹� �ִ� ������
	for (int i = 0; i < x; i++)
	{
		if (X[i] == T) { // ��ġ��
			return true;
		}
	}
	return false;
}

void f(int count, string p, string res) {
	if (count > k) { // �� �������
		if (!is_include(res)) { // ���� ������� �������
			cout << res << " �����ϴ�.\n";
			X[x] = res; // ���
			cnt++; x++; 
		}
		return;
	}
	res += p;
	for (int i = 0; i < n; i++) { // �迭 ũ�⸸ŭ
		if (!visited[i]) {
			visited[i] = true;
			f(count + 1, A[i], res);
			visited[i] = false;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> k;

	for (int i = 0; i < n; i++)
	{
		cin >> A[i];
	}
	f(0, "", "");
	printf("%d", cnt);
}