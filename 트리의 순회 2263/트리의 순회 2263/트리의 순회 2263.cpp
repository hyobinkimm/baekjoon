#include <iostream>
using namespace std;

int N;
int inorder[100000];
int postorder[100000];
int position[100001]; // 100000�̸� ����

void preorder(int in_min, int in_max, int post_min, int post_max) {
	if (in_min > in_max || post_min > post_max) {
		return;
	}

	int root = postorder[post_max]; // ���� ��ȸ�� root�� ����
	int rootIndex = position[root]; // ���� ��ȸ �������� �ϴ� root�� index�� ����

	printf("%d ", root);

	// left
	preorder(in_min, rootIndex - 1,
		post_min, post_min + (rootIndex - 1) - in_min);
	// right
	preorder(rootIndex + 1, in_max, 
		(post_min + rootIndex) - in_min, post_max - 1);

}

int main() {
	cin >> N;

	// ���� ��ȸ
	for (int i = 0; i < N; i++) {
		cin >> inorder[i];
		position[inorder[i]] = i;
		// position[x] = y : x�� �ε����� y�̴�.
		// inorder ������ ��ġ ������ �����ϰ� �;�	
	}

	// ���� ��ȸ : �� ������ ��尡 root ���
	for (int i = 0; i < N; i++) {
		cin >> postorder[i];
	}

	preorder(0, N - 1, 0, N - 1);
}