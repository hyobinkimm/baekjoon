#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int N;
vector<long int> vp;
vector<long int> vn;
int sum1, sum2;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		long int input;
		cin >> input;
		// ���, ����(0����) ������ �и�
		if (input > 0) vp.push_back(input);
		else vn.push_back(input);
	}

	if (!vp.empty()) {
		sort(vp.begin(), vp.end(), greater<>()); // ��������

		for (int i = 0; i < vp.size() - 1; i += 2) {
			sum1 += max(vp[i] + vp[i + 1], vp[i] * vp[i + 1]);
		}
		if (vp.size() % 2 == 1) sum1 += vp.back();
		
	}

	if (!vn.empty()) {
		sort(vn.begin(), vn.end(), less<>()); // �������� (���� �������� ��������)

		for (int i = 0; i < vn.size() - 1; i += 2) {
			sum2 += max(vn[i] + vn[i + 1], vn[i] * vn[i + 1]);
		}
		if (vn.size() % 2 == 1) sum2 += vn.back();
		
	}



	cout << sum1 + sum2;
}