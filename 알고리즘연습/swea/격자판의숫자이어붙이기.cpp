#include <iostream>
#include <set>
#include <string>

using namespace std;

int input[4][4];
set<string> numbers;
int direction[4][2] = { {0,1}, {-1,0}, {0,-1}, {1,0} };
int number[7];

void Dfs (int x, int y, int size)
{
    if (size == 7)
    {
        string s;
        for (int i = 0; i < 7; ++i)
        {
            s.append(to_string(number[i]));
        }
        numbers.insert(s);
    }
    else
    {
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + direction[i][0];
            int ny = y + direction[i][1];
            if (nx < 0 || nx > 3 || ny < 0 || ny >3) continue;
            number[size] = input[nx][ny];
            Dfs(nx,ny,size+1);
        }
    }
}

int main()
{
    int T;
    int test_case;
    cin >> T;

    for (int test_case = 1; test_case <= T; ++test_case)
    {
        for (int i = 0; i < 4; ++i)
        {
            for (int j = 0; j < 4; ++j)
            {
                cin >> input[i][j];
            }
        }

        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                number[0] = input[i][j];
                Dfs(i,j,1);
            }
        }
        
        cout << "#" << test_case << " " << numbers.size() << "\n";
        numbers.clear();
    }

    return 0;
}