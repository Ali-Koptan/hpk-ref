#include <bits/stdc++.h>

using namespace std;

//" '

int main()
{
    int n, m, target;
    cin >> n >> m;
    long long consc1[n], consc2[m], consc[n][m];
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        consc1[i] = x + consc1[i-1] * (i != 0);
    }
    for(int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        consc2[i] = x + consc2[i-1] * (i != 0);
    }
    cin >> target;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            consc[i][j] = consc1[i] * consc2[j];
        }
    }
    int ans = 0;
    for(int y1 = 0; y1 < n; y1++)
    {
        for(int x1 = 0; x1 < m; x1++)
        {
            for(int y2 = 0; y2 <= y1; y2++)
            {
                for(int x2 = 0; x2 <= x1; x2++)
                {
                    int val = consc[y1][x1];
                    if(x2 > 0)
                    {
                        val -= consc[y1][x2-1];
                    }
                    if(y2 > 0)
                    {
                        val -= consc[y2-1][x2];
                    }
                    if(x2 > 0 && y2 > 0)
                    {
                        val += consc[y2-1][x2-1];
                    }
                    if(val > target)
                    {
                        continue;
                    }
                    ans = max(ans, (y1 - y2 + 1) * (x1 - x2 + 1));
                }
            }
        }
    }
    cout << ans;
    return 0;    
}
