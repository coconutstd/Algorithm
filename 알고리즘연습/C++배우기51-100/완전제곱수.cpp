/*
 백준 1977 번 : 완전 제곱수

 해결 : math.h 에 정의된 sqrt함수를 이용하여 65~80 의 결과는 8.xxx 임을 활용

*/

#include <iostream>
#include <math.h>
using namespace std;
int N, M;

// 완전 제곱수 여부를 판별
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
	// N부터 M까지 한개씩 증가시키며 완전제곱수 여부 확인
	for (int i = N; i <= M; ++i) {
		if (isPowered(i)) {
			// 제일 작은 i 한번만 실행되는 구문
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