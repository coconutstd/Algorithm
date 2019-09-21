/*
 ���� 1977 �� : ���� ������

 �ذ� : math.h �� ���ǵ� sqrt�Լ��� �̿��Ͽ� 65~80 �� ����� 8.xxx ���� Ȱ��

*/

#include <iostream>
#include <math.h>
using namespace std;
int N, M;

// ���� ������ ���θ� �Ǻ�
bool isPowered(int p) {
	double t = sqrt(p);
	int cast = t;
	if (p == cast * cast) return true;
	else return false;
}

int main() {
	cin >> N >> M;
	int sum = 0;
	int min=10001;
	// N���� M���� �Ѱ��� ������Ű�� ���������� ���� Ȯ��
	for (int i = N; i <= M; ++i) {
		if (isPowered(i)) {
			// ���� ���� i �ѹ��� ����Ǵ� ����
			if (min > i) {
				min = i;
			}
			sum += i;
		}
	}
	if (sum != 0) {
		cout << sum << "\n" << min << endl;
	}
	else {
		cout << "-1" << endl;
	}
	
}