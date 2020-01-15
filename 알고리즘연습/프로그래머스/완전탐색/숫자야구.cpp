#include <string>
#include <vector>
#include <iostream>

int answer = 0;

using namespace std;

void Bruteforce (string num, vector<vector<int>>& baseball, int index)
{
    if (index + 1 > baseball.size())
    {
        answer++;
        return;
    }
    else
    {
        int strike = 0;
        int ball = 0;
        int check[3] = { 0,0,0 };
        string question = to_string(baseball[index][0]);
        for (int i = 0; i < 3; i++)
        {
            if (num[i] == question[i])
            {
                strike++;
                check[i] = 1;
                continue;
            }
            else
            {
                for (int j = 0; j < 3; ++j)
                {
                    if (i == j) continue;
                    if (!check[j] && num[i] == question[j])
                    {
                        ball++;
                        check[j] = 1;
                        break;
                    }
                }
            }
        }
        if (strike == baseball[index][1] && ball == baseball[index][2])
        {
            Bruteforce(num, baseball, index + 1);
        }
        return;
    }
}

int solution (vector<vector<int>>& baseball)
{

    for (int i = 111; i <= 999; ++i)
    {
        string tmp = to_string(i);
        bool check = true;
        for (int j = 0; j < 3; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                if (tmp[k] == '0')
                {
                    check = false;
                }
                else
                {
                    if (j == k) continue;
                    else if (tmp[k] == tmp[j]) check = false;
                }
            }
        }
        if (!check) continue;
        Bruteforce(to_string(i), baseball, 0);
    }
    return answer;
}

int main ()
{
    int n;
    cin >> n;
    vector<vector<int>> baseball(n);
    for (int i = 0; i < n; ++i)
    {
        int num, strike, ball;
        cin >> num >> strike >> ball;
        baseball[i].push_back(num);
        baseball[i].push_back(strike);
        baseball[i].push_back(ball);
    }
    cout << solution(baseball);
    return 0;
}