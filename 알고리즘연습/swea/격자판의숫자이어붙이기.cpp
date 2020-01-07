#include <iostream>
#include <set>
#include <string>

using namespace std;

string input[4][4];
set<string> numbers;
int direction[4][2] = { {0,1}, {-1,0}, {0,-1}, {1,0} };
int number[7];

void Dfs (int x, int y, string number)
{
    if (number.length() == 7)
    {
        if (!numbers.count(number))
        {
            numbers.insert(number);
        }
    }
    else
    {
        for (int i = 0; i < 4; ++i)
        {
            int nx = x + direction[i][0];
            int ny = y + direction[i][1];
            if (nx < 0 || nx > 3 || ny < 0 || ny >3) continue;
            Dfs(nx, ny, number + input[nx][ny]);
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
                Dfs(i,j,input[i][j]);
            }
        }
        
        cout << "#" << test_case << " " << numbers.size() << "\n";
        numbers.clear();
    }

    return 0;
}