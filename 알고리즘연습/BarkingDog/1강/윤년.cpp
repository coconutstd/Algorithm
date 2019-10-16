#include <cstdio>

int main() {
	int year;
	scanf_s_s("%d", &year);
	if (year % 400 == 0) {
		printf("1\n");
		return 0;
	}
	if (year % 100 == 0) {
		printf("0\n");
		return 0;
	}
	if (year % 4 == 0) {
		printf("1\n");
		return 0;
	}
	printf("0\n");

}