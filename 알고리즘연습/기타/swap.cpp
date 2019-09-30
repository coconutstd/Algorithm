#include <stdio.h>

void swap1(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swap2(int** a, int** b) {
	int* temp = &(**a);
	*a = &(**b);
	*(&(*b)) = temp;
}

int main() {

	int a = 3;
	int b = 4;

	swap1(&a, &b);
	printf("%d %d\n", a, b);

	int* pa = &a;
	int* pb = &b;
	int** da = &pa;
	int** db = &pb;

	swap2(da, db);
	printf("%d %d\n", *pa, *pb);
}
