#include <bits/stdc++.h>

using namespace std;

//" '

int main()
{
    int n, m;
    cin >> n >> m;
    int arr[n][m];
    long long consc1[n], consc2[m], consc[n][m];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            consc[i][j] = x;
            if(i > 0)
            {
                consc[i][j] += consc[i-1][j];
            }
            if(j > 0)
            {
                consc[i][j] += consc[i][j-1];
            }
            if(i > 0 && j > 0)
            {
                consc[i][j] -= consc[i-1][j-1];
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cout << consc[i][j] << ' ';
        }
        cout << '\n';
    }
    /*
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
    */
    return 0;    
}
