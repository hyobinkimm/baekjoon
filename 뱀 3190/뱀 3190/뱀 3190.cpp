#include <iostream>
#include <deque>
using namespace std;

int N, K, L; // K : ��� ����
int X[101][101];

int itr = 1;
bool isover;

struct det {
	int x;
	char c;
};

struct det det[100];
deque<pair<int, int>> mydeque;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> K;
	for (int i = 0; i < K; i++)
	{
		int row, col;
		cin >> row >> col;
		X[row][col] = 1;
	}

	cin >> L;
	for (int i = 0; i < L; i++)
	{
		int x; char c;
		cin >> x >> c;
		det[i].x = x + 1; // x�� �����̹Ƿ� ���������� x+1�ʿ� ������ ƴ
		det[i].c = c;
	}

	
	int k = 0; // det ����ü�� ����Ŵ
	char state = 'E'; // ó������ �������� ���ϹǷ� E
	int i = 1; int j = 1;
	mydeque.push_back(make_pair(i, j)); // 1,1���� ���
	

	while (1) {
		// (1) ������ ��� �������� (i, j) ����
		if (itr  == det[k].x) { // ������ �ð��� �����ٸ� ȸ��
			if (det[k].c == 'L') {	// ��������
				if (state == 'E') { state = 'N'; i--; } // �����̾��ٸ� ��������
				else if (state == 'W') { state = 'S'; i++; } // �����̾��ٸ� ��������
				else if (state == 'N') { state = 'W'; j--; } // �����̾��ٸ� ��������
				else { state = 'E';	j++; } // �����̾��ٸ� ��������
			}
			else { // ����������
				if (state == 'E') { state = 'S'; i++; } // �����̾��ٸ� ��������
				else if (state == 'W') { state = 'N'; i--; } // �����̾��ٸ� ��������
				else if (state == 'N') { state = 'E'; j++; } // �����̾��ٸ� ��������
				else { state = 'W'; j--; } // �����̾��ٸ� ��������
			}
			k++; // �� ���� �ð�
		}
		else { // �׳� ��ҿ� �̵��� ��
			if (state == 'E') { j++; }
			else if (state == 'W') { j--; }
			else if (state == 'N') { i--; }
			else { i++; }
			
		}
		
		// (2) ������ ��ǥ�� ��������
		// ���� ����
		// 1. ���� �ε���
		if (i > N || j > N || i < 1 || j < 1) { break; }
		// 2. �ڱ��ڽ��� ���� �ε���
		for (int z = 0; z < mydeque.size(); z++) {
			if (mydeque[z].first == i && mydeque[z].second == j) { isover = true;	break; }
		}
		if (isover) break;
		

		// (3) �����ϸ� ����� �ִ��� / ������
		mydeque.push_front(make_pair(i,j)); // �����̸� �÷� ����ĭ�� ��ġ��Ŵ		

		if (X[i][j] == 1) { // ���� ����� �ִ� ���̶��
			X[i][j] = 0; // ��� �Ծ����ϱ� �����·�
			// �����̴� ����
		}
		else { // ����� ���� ���̶��
			mydeque.pop_back(); // ������ pop
		}

		itr++; // �ð� ����
	}

	cout << itr;
}