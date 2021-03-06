#include <string>
#include <vector>
#include <iostream>
#include <memory.h>
#include <cmath>
#include <random>
using namespace std;

string global_numbers;
int check[8];
int prime_array[10000000];
int primes[10000000];
int answer;

void Getche (int num) 
{
    int i;
    for (i = 2; i <= num; ++i) 
    {
        primes[i] = i;
    }

    for (i = 2; i <= num; ++i) 
    {
        if (primes[i] == 0) 
        {
            continue;
        }
        else 
        {
            for (int j = i + i; j <= num; j += i) 
            {
                primes[j] = 0;
            }
        }

    }
}

void Bruteforce (int m, string prime, int index) 
{
    if (m == prime.length()) 
    {
        if (prime_array[stoi(prime)]) 
        {
            return;
        }
        else {
            prime_array[stoi(prime)] = 1;
            if (primes[stoi(prime)] != 0) answer++;
        }
        return;
    }
    else 
    {
        for (int i = 0; i < global_numbers.length(); ++i) 
        {
            if (check[i]) continue;
            check[i] = 1;
            Bruteforce(m, prime + global_numbers[i], i);
            check[i] = 0;
        }
    }
}

int solution (string numbers) 
{
    memset(check, 0, sizeof (check));
    global_numbers = numbers;
    answer = 0;
    Getche(pow(10, numbers.length()));
    for (int i = 1; i <= numbers.length(); ++i) 
    {
        Bruteforce(i, "", 0);
    }
    return answer;
}

int main () {

    std::random_device rd;
    std::mt19937 mersenne (rd ());
    std::uniform_int_distribution<> len (1, 7);
    std::uniform_int_distribution<> num (0, 9);

    for (int i = 1; i <= 100; ++i) 
    {
        string tmp = "";
        int l = len (mersenne);
        for (int j = 0; j < l; ++j) 
        {
            tmp += to_string (num (mersenne));
        }
        cout << tmp << " : ";
        cout << solution (tmp) << endl;
    }
    return 0;
}