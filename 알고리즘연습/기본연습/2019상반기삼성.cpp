#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct FISH {
	int x, y, d, v,num;
};

struct LOC {
	vector<FISH> fishes;
	FISH big_fish;
	int cnt;
};

LOC map[100][100];
queue<FISH> next_fish;
const int dx[] = { 0,0,-1,+1 };
const int dy[] = { -1,+1,0,0 };

int T;
int width, depth, N;

void move(FISH& fish) {
	int x = fish.x; int y = fish.y; int d = fish.d; int v = fish.v;
	int nx = x + (v * dx[d - 1]); int ny = y + (v * dy[d - 1]);
	//printf("%d %d %d %d %d\n", x, y, d, v, fish.num);
	if (nx < 0) {
		int delta = 0 - nx;
		nx = 0 + delta;
		d = 4;
	}
	if (nx > width - 1) {
		
		int delta = nx - width;
		nx = width - 1 - delta - 1;
		d = 3;
	}
	if (ny < 0) {
		int delta = 0 - ny;
		ny = 0 + delta;
		d = 2;
	}
	if (ny > depth - 1) {
		int delta = ny - depth - 1;
		ny = depth - 1 - delta;
		d = 1;
	}
	FISH next = { nx,ny,d,v,fish.num };
	
	next_fish.push(next);
}

void init() {
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < depth; y++) {
			while (!map[x][y].fishes.empty()) {
				map[x][y].fishes.pop_back();
			}
			FISH fish = { 0, };
			map[x][y].big_fish = fish;
			map[x][y].cnt = 0;
		}
	}
}

int main() {
	scanf("%d", &T);
	while (T--) {
		init();
		scanf("%d %d %d", &width, &depth, &N);
		FISH fish;
		for (int i = 0; i < N; i++) {
			scanf("%d %d %d %d", &fish.x, &fish.y, &fish.d, &fish.v);
			fish.num = i + 1;
			map[fish.y][fish.x].cnt++;
			map[fish.y][fish.x].fishes.push_back(fish);
			map[fish.y][fish.x].big_fish = fish;
		}



		int ans = 0;
		for (int i = 0; i < width; i++) {
			printf("%d번째\n", i);
			for (int y = 0; y < depth; y++) {
				for (int x = 0; x < width; x++) {
					printf("%d ", map[y][x].big_fish.num);
				}
				printf("\n");
			}

			for (int z = 0; z < depth; z++) {
				if (map[z][i].cnt != 0) {
					ans += map[z][i].big_fish.num;
					printf("%d번째 투척 (%d , %d)의 %d 잡음\n", i,i, z, map[z][i].big_fish.num);
					map[z][i].cnt = 0;
					while (!map[z][i].fishes.empty()) {
						map[z][i].fishes.pop_back();
					}
					FISH fish = { 0,};
					map[z][i].big_fish = fish;
					break;
				}
			}
			printf("\n");
			
			for (int y = 0; y < depth; y++) {
				for (int x = 0; x < width; x++) {

					if (map[y][x].cnt == 0) continue;
					if (map[y][x].cnt != 0) {
						
						move(map[y][x].big_fish);
						map[y][x].cnt = 0;
						FISH fish = { 0, };
						map[y][x].big_fish = fish;
						
						while (!map[y][x].fishes.empty()) {
							
							map[y][x].fishes.pop_back();
						}
					}
				}
			}
			
			while (!next_fish.empty()) {
				FISH cur = next_fish.front(); next_fish.pop();
				map[cur.y][cur.x].cnt++;
				map[cur.y][cur.x].big_fish = cur;
				map[cur.y][cur.x].fishes.push_back(cur);
			}

			for (int y = 0; y < depth; y++) {
				for (int x = 0; x < width; x++) {
					if (map[y][x].cnt == 0) continue;
					if (map[y][x].cnt >= 2) {
						int num = -1; 
						for (int j = 0; j < map[y][x].cnt; j++) {
							if (num < map[y][x].fishes[j].num) {
								num = map[y][x].fishes[j].num;
								map[y][x].big_fish = map[y][x].fishes[j];
							}
						}
						map[y][x].cnt = 1;
						while (!map[y][x].fishes.empty()) {
							map[y][x].fishes.pop_back();
						}
						map[y][x].fishes.push_back(map[y][x].big_fish);
					}
				}
			}

		}
		printf("%d\n", ans);
	}

}