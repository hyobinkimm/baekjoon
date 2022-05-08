#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <stdlib.h>
using namespace std;

int n, d;

vector<pair<int, int>> A[10001];

int d_[10001]; // ������ �����ؼ� ����

void input() {
	cin >> n >> d;
	for (int i = 0; i <= d; i++)
	{
		d_[i] = 10001; // �ϴ� �ִ����� �ʱ�ȭ
	}
	d_[d] = d;
	for (int i = 0; i < n; i++)
	{
		int from, to, cost;
		cin >> from >> to >> cost;
		if (to - from <= cost)continue; // �������� �ƴѰ��
		if (to > d)continue; // �Ÿ��� �Ѿ�� ���
		A[from].push_back(make_pair(to, cost));
	}
}

void solve() {
	// d_�迭 ���� : d �ε��� ����� �� 1001�� �ʱ�ȭ
	// d_ : i�� �����ϱ� ���� �ּ� ���� �Ÿ� ����
	int prev = -1;
	for (int i = 0; i <= d; i++) {
		if (i != 0)prev = d_[i - 1]; 
		d_[i] = min(d_[i], prev + 1);
		for (auto next : A[i]) { // A�� next�� �о�´�
			if (d_[i] + next.second < d_[next.first]) { // ������� �̵����� �� < ���� ��ο��� �������� �� 
				d_[next.first] = d_[i] + next.second; // �� ���� �� ���� �����س��´�
			}
		}
	}
}

void output() {
	cout << d_[d];
}

int main() {
	input();
	solve();
	output(); 
}