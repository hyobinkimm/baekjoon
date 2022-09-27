#include <iostream>
#include <algorithm>
using namespace std;

int N;
int INPUT[10000];
int M;
int maximum = -1;

void BinarySearch(int start, int end, int key) {

	if (start > end) { // �� Ž��������
		return;
	}
	key = (start + end) / 2; // ���Ѿ����� ����

	// key�� ���Ѿ��� ����� �� ������� ���غ�
	int s = 0;
	for (int i = 0; i < N; i++)
	{
		if (INPUT[i] > key) {
			s += key;
		}
		else {
			s += INPUT[i];
		}
	}

	if (s > M) { // ���Ѿ� ����, �� �۰� ����
		BinarySearch(start, key - 1, key);
	}
	else { 
		if (key > maximum)maximum = key; // ���� ���� ���Ѿ��� �������� ũ�� ����
		BinarySearch(key+1, end, key); // ���Ѿ��� �� Ŀ�� �� �ִ��� �� ũ�� ��ƺ�
	}

	
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int sum = 0;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> INPUT[i];
		sum += INPUT[i];
	}
	cin >> M;
	
	sort(INPUT, INPUT + N); // �̺� Ž���� ���� ����
	

	if (sum > M) { // ���� �ʰ� ��
		BinarySearch(1, INPUT[N - 1],-1);

		cout << maximum;
	}
	else { // ������ ���Ƶ���
		cout << INPUT[N - 1]; // �� ���� �� �ִ� ���
	}


}