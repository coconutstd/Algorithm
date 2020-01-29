#include <iostream>
#include <vector>

using namespace std;

int Count (const int &mid, const vector<int> &music)
{
    int cnt = 1, sum = 0;
    for (int i = 0; i < music.size (); ++i)
    {
        if (sum + music[i] > mid)
        {
            cnt++;
            sum = music[i];
        }
        else
        {
            sum += music[i];
        }
    }

    return cnt;
}

int main ()
{
    //freopen ("input.txt", "r", stdin);

    int i, n, m;
    int lt = 1, rt = 0, mid;
    int res;
    cin >> n >> m;
    vector<int> music (n);

    for (i = 0; i < n; ++i)
    {
        cin >> music[i];
        rt += music[i];
    }

    while (lt <= rt)
    {
        mid = (lt + rt) / 2;
        if (Count (mid, music) <= m)
        {
            res = mid;
            rt = mid - 1;
        }
        else
        {
            lt = mid + 1;
        }
    }

    cout << res << endl;

    return 0;
}