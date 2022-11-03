#include <iostream>
#include <string>
#define MAX 100000 // queue�� �ִ� ũ��� 10,000
using namespace std;

template<class T> class MyQueue
{
public :
	int front; int rear; int size;
	T* values;

	MyQueue() {
		size = MAX;
		values = new T[size];
		front = 0; rear = 0;
	}

	~MyQueue() { delete[] values; }

	void push(T value) {
		values[rear] = value;
		rear++;
	}

	void pop() {
		if (!empty()) {
			cout << values[front] << "\n";
			front++;
		}
		else { // queue�� ����ִ� ������ ���� ���
			cout << -1 << "\n";
		}
	}

	void size_() { // ������ ���� �߻�
		cout << rear - front <<"\n";
	}

	bool empty() {
		if (front == rear) {
			return true;
		}
		else return false;
	}

	void front_() { // ������ ���� �߻�
		if (!empty()) cout << values[front] << "\n";
		else cout << -1 << "\n";
	}

	void back() {
		if (!empty()) cout << values[rear - 1] << "\n";
		else cout << -1 << "\n";
	}
};

int N;
string command[6] = { "push", "pop", "size", "empty", "front", "back" };
string input;

MyQueue<int> myqueue;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N + 1; i++) // getline �Լ� ������ �ڲ� N-1��ŭ �Է��� ����,, �׷��� N��ŭ �ݺ��ϵ���
	{
		getline(cin, input); // �� ���� �� �Է¹���
		for (int j = 0; j < 6; j++) {
			if (input.find(command[j]) != string::npos) { // ã�Ҵٸ�				
				if (j == 0) { // push
					string temp = "";
					for (int k = 5; k < input.length(); k++) {
						temp += input[k]; // ���� string���� ��������
					}
					int in = stoi(temp); // stoi�� ���� ����
					myqueue.push(in);
				}
				else if (j == 1) { // pop
					myqueue.pop();
				}
				else if (j == 2) { // size
					myqueue.size_();
				}
				else if (j == 3) { // empty
					if (myqueue.empty() == true) {
						cout << 1 << "\n";
					}
					else {
						cout << 0 << "\n";
					}
				}
				else if (j == 4) { // front
					myqueue.front_();
				}
				else { // back
					myqueue.back();
				}
			}
		}
	}
}