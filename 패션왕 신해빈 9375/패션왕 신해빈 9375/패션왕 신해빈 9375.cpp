#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int T, N;

int dp[101][101];
int R;

int f(int n, int k) {

	for (int i = 0; i <= n; i++) {
		dp[i][0] = 1;
	}

	for (int i = 0; i <= k; i++) {
		dp[i][i] = 1;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]);
		}
	}

	return dp[n][k];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	f(100, 100); // �̸� ���� ���س��� dp �迭�� �Ҵ��ϱ�

	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> N;

		// �ʱ�ȭ
		R = 1;
		unordered_map <string, int> mymap; 

		for (int j = 0; j < N; j++)
		{
			string wear, kind;
			cin >> wear >> kind;		
			// wear�� �ߺ����� �����Ƿ� ��ǻ� �ʿ����. ���� ������ �߿���
			// 1���� �̻��� ������ �����ؾ� ��
			// 
			// ex : M ������ ���� 3���� ��
			// m1����,  m2����, m3����, �ƹ��͵� ���� x 
			// �� (M + 1)������ ����� �� ����

			mymap[kind]++; // �ش� ������ �� ���� ����
		}
		for (auto const& pair : mymap) {
			R *= dp[pair.second + 1][1]; // M+1C1 ����
		}
		printf("%d\n", R - 1); // �ƹ��͵� ���� ���� ��츦 ����
	}


}