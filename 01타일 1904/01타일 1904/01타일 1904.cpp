#include <iostream>
#include <string>
using namespace std;

int N;
int M[1000001];

// ������ ��ƺ���

void f(int count) {
	if (count == 1 || count==2 || count==3) { // count=1,2,3�̸� count�� ������ ����
		M[count]=count;
	}
	else {
		if (M[count] == 0) { // ���� ���� ä������ �ʾҴٸ�
			M[count] = (M[count - 1] + M[count - 2]) % 15746; // �� ä���ֱ�
		}
	}
	if (count == N) return; // ���ϴ� ���� �����ߴٸ� return
	f(count + 1); // �ƴ϶�� count �������� N�� �����ϵ��� ����
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N;

	f(1);
	printf("%d", M[N]);
}