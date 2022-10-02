#include <iostream>
#include <cmath>
using namespace std;

struct xyz { // xyz ����ü
	double x;
	double y;
	double z;
};

struct xyz A;
struct xyz B;
struct xyz C;

double minimum = 2147483647; // �ʱ� �ּڰ��� �ִ�� �����ؾ� ..

void BinarySearch(struct xyz start, struct xyz end) { 
	double temp = sqrt((start.x - end.x) * (start.x - end.x) + (start.y - end.y) * (start.y - end.y)
		+ (start.z - end.z) * (start.z - end.z)); // start�� end���� �Ÿ��� ����
	double error = 1; 
	for (int i = 0; i < 6; i++) {
		error *= 0.1; // ������ 10^-6���� ����ϹǷ�
	}
	
	if (-1 * error <= temp && temp <= error) { // start�� end���� �Ÿ��� ������ �̳����� 0�̸� ���� ���� ����Ų�ٴ� �Ҹ�. Ž�� ����
		return;
	}

	struct xyz key; // ���Ž��
	key.x = (start.x + end.x) / 2;;
	key.y = (start.y + end.y) / 2;
	key.z = (start.z + end.z) / 2;

	// len : ���� ������ ����AB ���� �� key�� �� C������ �Ÿ�
	double len = sqrt((key.x - C.x) * (key.x - C.x) + (key.y - C.y) * (key.y - C.y) + (key.z - C.z) * (key.z - C.z));
	
	minimum = (len < minimum) ? len : minimum; // �ּڰ� ����

	// start_C : start�� C ������ �Ÿ�
	double start_C= sqrt((start.x - C.x) * (start.x - C.x) + (start.y - C.y) * (start.y - C.y) + (start.z - C.z) * (start.z - C.z));
	// end_C : end�� C ������ �Ÿ�
	double end_C = sqrt((end.x - C.x) * (end.x - C.x) + (end.y - C.y) * (end.y - C.y) + (end.z - C.z) * (end.z - C.z));
	

	if (start_C > end_C) { // end_C���� �Ÿ��� �� �����ٸ� �ּҰŸ��� �����ϴ� ���� �� key�� �� end ���̿� ������
		BinarySearch(key, end);
	}
	else { // �ݴ�δ� start�� key ���̿� ����
		BinarySearch(start, key);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> A.x >> A.y >> A.z;
	cin >> B.x >> B.y >> B.z;
	cin >> C.x >> C.y >> C.z;


	BinarySearch(A, B); // ���� AB�ȿ��� ã��
	 
	cout << fixed;
	cout.precision(10); // �Ҽ��� 10�ڸ� ���
	cout << minimum;

}