#include <iostream>
#include <string>
#define MAX 100000
using namespace std;

template<class T> class MyDeque
{
public:
	int front; int rear; int size;
	T* values;

	MyDeque() {
		size = MAX;
		values = new T[size];
		front = 0; rear = 0;
	}

	~MyDeque() { delete[] values; }
	
	void push_front(T value) { // front���� �� �ֱ�
		values[front] = value; // �� �ְ�
		front = (front - 1 + MAX) % MAX; // front--�� ���(�迭 �ּ� �ε����� 0�̹Ƿ� �迭 ������ ���� front�� ����ų����) 
	}

	void push_back(T value) { // rear���� �� �ֱ�
		rear = (rear + 1) % MAX; // �̸� index�� ������Ű��
		values[rear] = value; // �� ����
	}

	void pop_front() { // front �� ����
		if (!empty()) {
			front = (front + 1) % MAX; // ����ִ� ���� ����Ű�Ƿ� ������Ų����
			cout << values[front] << "\n"; // ��� ��
			values[front] = NULL; // NULL������ �����
			
		}
		else { // queue�� ����ִ� ������ ���� ���
			cout << -1 << "\n";
		}
	}
	void pop_back() { // rear �� ����
		if (!empty()) {
			cout << values[rear] << "\n";
			rear = (rear - 1 + MAX) % MAX;
		}
		else { // queue�� ����ִ� ������ ���� ���
			cout << -1 << "\n";
		}
	}

	void size_() { // ������ ���� �߻�
		cout << (rear - front + MAX) % MAX << "\n";
	}

	bool empty() {
		return front == rear;
	}

	void front_() { // ������ ���� �߻�
		if (!empty()) cout << values[(front + 1) % MAX] << "\n"; // front�� ����ִ� ���� ����Ű�Ƿ� +1
		else cout << -1 << "\n";
	}

	void back() { // ���� �ڿ� �ִ� ���� ���
		if (!empty()) cout << values[rear] << "\n"; // rear�� ���� ���� �ִ� ���� ����Ű�Ƿ�
		else cout << -1 << "\n";
	}
};

MyDeque<int> mydeque;

int N;
string command[8] = { "push_front", "push_back", "pop_front", "pop_back",
"size", "empty", "front", "back" };
string input;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	for (int i = 0; i < N + 1; i++)
	{
		getline(cin, input);
		for (int j = 0; j < 8; j++) {
			if (input.find(command[j]) != string::npos) { // ã�Ҵٸ�				
				if (j == 0) { // push_front
					string temp = "";
					for (int k = 11; k < input.length(); k++) {
						temp += input[k]; // ���� string���� ��������
					}
					int in = stoi(temp); // stoi�� ���� ����
					mydeque.push_front(in);
				}
				else if (j == 1) { // push_back
					string temp = "";
					for (int k = 10; k < input.length(); k++) {
						temp += input[k]; // ���� string���� ��������
					}
					int in = stoi(temp); // stoi�� ���� ����
					mydeque.push_back(in);
				}
				else if (j == 2) { // pop_front
					mydeque.pop_front();
				}
				else if (j == 3) { // pop_back
					mydeque.pop_back();
				}
				else if (j == 4) { // size
					mydeque.size_();
				}
				else if (j == 5) { // empty
					cout << mydeque.empty() << "\n";
				}
				else if (j == 6) { // front
					mydeque.front_();
				}
				else { // back
					mydeque.back();
				}
				break;
			}
		}
	}

}