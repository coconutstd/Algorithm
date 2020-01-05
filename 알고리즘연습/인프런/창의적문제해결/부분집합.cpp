#include <cstdio>

int number;
int checking_array[12];

void Dfs(int num){
  if (num == number + 1) {
    for(int i = 1; i <= number; ++i){
      if(checking_array[i] == 1){
        printf("%d ", i);
      }
    }
    puts("");
  } else {
    checking_array[num] = 1;
    Dfs(num+1);
    checking_array[num] = 0;
    Dfs(num+1);
  }
}

int main(){
  scanf("%d",&number);
  Dfs(1);
}