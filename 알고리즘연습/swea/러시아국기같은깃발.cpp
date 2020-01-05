#include <iostream>

using namespace std;

int row,col;
int min_count = 987654321;
char input[51][51];
int permutation[4];
int number;

void FindAnswer(){
  int white = permutation[0]; // 1
  int blue = white + permutation[1]; // 2
  int red = blue + permutation[2]; // 4
  int count = 0;
  for(int i = 0; i < white; ++i){
    for(int j = 0; j < col; ++j){
      if (input[i][j] != 'W') {
        count++;
      }
    }
  }

  for(int i = white; i < blue; ++i){
    for(int j = 0; j < col; ++j){
      if (input[i][j] != 'B') {
        count++;
      }
    }
  }

  for (int i = blue; i < red; ++i) {
    for (int j = 0; j < col; ++j) {
      if (input[i][j] != 'R') {
        count++;
      }
    }
  }
  if(min_count > count) min_count = count;
  return;
}

void Dfs(int num){
  if (num == 3) {
    int check_sum = 0;
    for(int i = 0; i < 3; ++i){
      check_sum += permutation[i];
    }
    if(check_sum == row) FindAnswer();
    return;
  } else {
    for(int i = 1; i <= number; ++i){
      permutation[num] = i;
      Dfs(num + 1);
    }
  }
}

int main() {
	int test_case;
	int T;
	freopen("sample_input.txt", "r", stdin);
  cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
    cin >> row >> col;
    number = row - 2;

    for(int i = 0; i < row; ++i){
      string temp_input = "";
      cin >> temp_input;
      for(int j = 0; j < temp_input.length(); ++j){
        input[i][j] = temp_input[j];
      }
    }

    for(int i = 0; i < row; ++i){
      for(int j = 0; j < col; ++j){
        cout << input[i][j];
      }
      puts("");
    }

    Dfs(0);
    cout << "#" << test_case << " " << min_count << "\n";
    min_count = 987654321;
	}

	return 0;
}