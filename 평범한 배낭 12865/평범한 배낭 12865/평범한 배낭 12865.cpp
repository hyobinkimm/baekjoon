#include <iostream>
#include <cmath>
using namespace std;

int P[101][100001];
int Weight; // �賶 ����

int knapsack(int n, int W[], int V[]) { // ������ ����, ���� �迭, ��ġ �迭
	int maximum = -1; // ���濡 ���� ������ �ִ� ��ġ�� ��Ÿ��
	for (int i = 1; i <= n; i++) { // ������ ������ŭ �ݺ�
		for (int w = 1; w <= Weight; w++) { // �賶 ���Ը�ŭ �ݺ�
			if (W[i] <= w) { // ��� ���Ը� ���� ���� ��
				P[i][w] = max(P[i - 1][w], V[i] + P[i - 1][w - W[i]]);
				// i��° ������ ���� �ʾ��� ���� �־��� ���� ���Ͽ� �ִ��� ����
			}
			else { // ��� ���Ը� �ʰ��ϹǷ� ������ ���� ����
				P[i][w] = P[i - 1][w]; // i��° ������ ���� ����
			}
			// p[i][w] = ó������ i��°�� ������ Ž���ϰ� �賶�� �뷮�� w�� �� �賶�� �� ������ �ִ� ��ġ
		}
	}

	return P[n][Weight];
	// �ִ��� �翬�� ó������ ������ ������ Ž���ϰ� �賶�� �뷮�� Weight�� ���� P��
}
int main() {
	int W[101]; int V[101];
	int n;
	cin >> n >> Weight;
	for (int i = 1; i <= n; i++) {
		cin >> W[i] >> V[i];
	}

	cout << knapsack(n, W, V);
}