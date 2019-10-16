/*
 ���������� ��������� ����
 dfs()�� �ΰ����� ȣ���� �ϰ� ���� ��ȸ ������� �迭 ��ġ�⸦ ������ ���� ����Ʈ
*/

#include <stdio.h>
int data[] = { 4,2,3,1,8,7,6,5 };
int temp[8];

void dfs(int lt, int rt) {
	int mid, pt1, pt2, pt3;
	if (lt < rt) {
		mid = (lt + rt) / 2;
		dfs(lt, mid);
		dfs(mid + 1, rt);
		pt1 = lt;
		pt2 = mid + 1;
		pt3 = lt;
		while (pt1 <= mid && pt2 <= rt) {
			if (data[pt1] < data[pt2]) {
				temp[pt3++] = data[pt1++];
			}
			else {
				temp[pt3++] = data[pt2++];
			}
		}
		while (pt1 <= mid) temp[pt3++] = data[pt1++];
		while (pt2 <= rt) temp[pt3++] = data[pt2++];
		for (int i = lt; i <= rt; i++) {
			data[i] = temp[i];
		}
	}
}

int main() {
	dfs(0, 7);
	for (int i = 0; i < 8; i++) {
		printf("%d ", data[i]);
	}
}