#include <bits/stdc++.h>

using namespace std;

const int Range = 1000000;
int spf[Range + 5];

void GeneratePrimes()
{
    for(int i = 2; i <= Range; i++)
    {
        spf[i] = i;
    }
    for(int i = 2; (long long)i*i <= Range; i++)
    {
        if(spf[i] == i)
        {
            for(int j = i; (long long int)j * i <= Range; j++)
            {
                spf[j * i] = i;
            }
        }
    }
}

int FastPow(int base, int power)
{
    if(power == 0)
    {
        return 1;
    }
    if(power == 1)
    {
        return base;
    }
    if(power % 2 == 0)
    {
        int x = FastPow(base, power / 2);
        return x * x;
    }
    return base * FastPow(base, power - 1);
}

void multiplyFactors(int i, int val, const vector<pair<int, int>>& factors, vector<int>& divisors)
{
    if(i == factors.size())
    {
        divisors.push_back(val);
        return;
    }
    for(int j = 0; j <= factors[i].second; j++)
    {
        multiplyFactors(i+1, val * FastPow(factors[i].first, j), factors, divisors);
    }
}

void GetDivisors(int n, vector<int>& divisors)
{
    vector<pair<int, int>> factors;
    while(n > 1)
    {
        if(factors.empty() || factors[factors.size() - 1].first != spf[n])
        {
            factors.push_back({spf[n], 1});
        }
        else
        {
            factors[factors.size() - 1].second++;
        }
        n /= spf[n];
    }
    multiplyFactors(0, 1, factors, divisors);
    sort(divisors.begin(), divisors.end());
}

vector<vector<int>> allDivisors;

int main()
{
    GeneratePrimes();
    allDivisors.resize(Range + 5);
    for(int i = 1; i <= Range; i++)
    {
        GetDivisors(i, allDivisors[i]);
    }
    return 0;
}