#include <iostream>
#include <vector>
using namespace std;

int brown, cony;
vector<int> b_pos;
vector<int> c_pos;
int main(void) {
	int i = 1;
	scanf("%d %d", &brown, &cony);
	b_pos.push_back(brown);
	c_pos.push_back(cony);
	while (0 <= brown && brown <= 200000) {
		brown += i;
		i += 1;
		b_pos.push_back(brown);
		
	}
	
	for (int i = 0; i < b_pos.size(); i++) {
		printf("%d ", b_pos[i]);
	}



	return 0;
}