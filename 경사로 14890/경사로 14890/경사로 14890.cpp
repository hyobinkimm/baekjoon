#include <iostream>
#include <cmath>
#include <memory.h>
using namespace std;

int N, L;
int A[101][101];
int answer;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> A[i][j];
		}
	}

	// �� Ž��
	for (int i = 1; i <= N; i++) {
		int before = A[i][1];
		bool G[101] = { false }; // ����		
		bool isError = false;
		for(int j=2; j<=N; j++){
			if (!G[j]) {
				if (A[i][j] != before) {
					if (A[i][j] > before && A[i][j] - before == 1) {
						// before : 2, A[i][j] : 3
						// ��簡 �������ٸ�
						// ���� ��ƾ���
						// ���� ��Ͽ� ��縦 ��ƾ���
						for (int k = 1; k <= L; k++) {
							if (j - k < 1 || A[i][j - k] != before || G[j - k]) {
								// ���� ���� ���ų�, �������� �ʰų�, �̹� ���ΰ� �ִٸ�
								isError = true; break;
							}
						}

						if (isError)break;
						else {
							// error ���� ��� for���� ����ߴٸ�
							for (int k = 1; k <= L; k++) {
								G[j - k] = true; // ���� �ִ� �ɷ� ����
							}
						}
					}
					else if (A[i][j] < before && before - A[i][j] == 1) {
						// before : 3, A[i][j] : 2		
						// ��簡 �������ٸ�
						// ���� ��ƾ���
						// ���� i, j���� ���� ��ƾ���
						for (int k = 0; k < L; k++) {
							if (j + k > N || A[i][j + k] != A[i][j] || G[j + k]) {
								isError = true; break;
							}
						}
						if (isError)break;
						else {
							// error ���� ��� for���� ����ߴٸ�
							for (int k = 0; k < L; k++) {
								G[j + k] = true; // ���� ���� �ִ� 
							}
						}
					}
					else {
						// ���� 1ĭ ���� �ʰ�
						isError = true;
						break;
					}
				}
				else {
					// ��簡 �Ȱ��ٸ�
					// ����
				}

				if (isError)break;
				before = A[i][j];
			}
			
		}
		if (!isError) {
			answer++;
		}
	}

	for (int j = 1; j <= N; j++) {
		int before = A[1][j];
		bool G[101] = { false }; // ����		
		bool isError = false;
		for (int i = 2; i <= N; i++) {
			if (!G[i]) {
				if (A[i][j] != before) {
					if (A[i][j] > before && A[i][j] - before == 1) {
						// before : 2, A[i][j] : 3
						// ��簡 �������ٸ�
						// ���� ��ƾ���
						// ���� ��Ͽ� ��縦 ��ƾ���
						for (int k = 1; k <= L; k++) {
							if (i - k < 1 || A[i - k][j] != before || G[i - k]) {
								isError = true; break;
							}
						}

						if (isError)break;
						else {
							// error ���� ��� for���� ����ߴٸ�
							for (int k = 1; k <= L; k++) {
								G[i - k] = true; // ���� ���� �ִ�
							}
						}
					}
					else if (A[i][j] < before && before - A[i][j] == 1) {
						// before : 3, A[i][j] : 2		
						// ��簡 �������ٸ�
						// ���� ��ƾ���
						// ���� i, j���� ���� ��ƾ���
						for (int k = 0; k < L; k++) {
							if (i + k > N || A[i + k][j] != A[i][j] || G[i + k]) {
								isError = true; break;
							}
						}
						if (isError)break;
						else {
							// error ���� ��� for���� ����ߴٸ�
							for (int k = 0; k < L; k++) {
								G[i + k] = true; // ���� ���� �ִ� 
							}
						}
					}
					else {
						isError = true;
						break;
					}
				}
				else {
					// ��簡 �Ȱ��ٸ�
					// ����
				}

				if (isError)break;
				before = A[i][j];
			}

		}
		if (!isError) {
			answer++;
		}
	}


	cout << answer;
}