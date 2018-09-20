#include <bits/stdc++.h>
using namespace std;
int par[100009], ranks[100009], table[100009][18], levels[100009];
long long summ[100009];
vector<int >listt[100009];
bool visited[100009];

void dfs(int node , int sum, int level)
{
    visited[node]=1;
    summ[node]=sum;
    levels[node]=level;
    for(int i=0;i<listt[node].size();i++)
    {
        int nxt=listt[node][i];
        if(!visited[nxt])
        {
            table[nxt][0]=node;
            dfs(nxt, sum+1, level+1);
        }
    }
}

int getpar(int node)
{
    if(par[node] == node)return node;
    return par[node] = getpar(par[node]);
}

bool connect(int x, int y)
{
    int xroot = getpar(x);
    int yroot = getpar(y);
    if(xroot!=yroot)
    {
        if(ranks[xroot]<ranks[yroot])
        {
            par[yroot]=xroot;
            ranks[xroot]++;
        }
        else
        {
            par[xroot]=yroot;
            ranks[yroot]++;
        }
        return 1;
    }
    return 0;
}

int get_kth(int node , int p)
{
    int target_level = p;
    //cout<<"target  = "<<target_level<<endl;
    for(int j=17;j>=0;j--)
    {
        //cout<<"node = "<<node<<" target = " <<target_level<<" el gy = "<<(levels[node] - (1<<j))<<" levels = "<<levels[node]<<" j = "<<(1<<j)<<endl;
        if((levels[node] - (1<<j)) >= target_level)
            node=table[node][j];

    }
    return node;
}
int get_lca(int u ,int v)
{
    //v el tht aktr
    if(levels[u]>levels[v])swap(u,v);
    //cout<<" u before = "<<u<<" v before = "<<v<<" levels[u] = "<<levels[u]<<" levels[v] = "<<levels[v]<<endl;
    int diff = levels[v]-levels[u];
    v = get_kth(v,levels[u]);
    //cout<<" u = "<<u<<" v = "<<v<<endl;
    if(u==v)return u;
    for(int j=17;j>=0;j--)
    {
        if(table[u][j]!=-1&&table[v][j]!=-1&&table[u][j]!=table[v][j])
        {
            u=table[u][j];
            v=table[v][j];
        }
    }
    return table[u][0];
}
int get_dist(int x, int y) {
    return levels[x] + levels[y] - 2 * levels[get_lca(x, y)];
}
int main()
{
   ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, q, u, v, a,b,c , lca1 , lca2, lca3, dist1, dist2, dist3;
    cin>>n>>q;
    for(int i=0;i<100009;i++)
    {
        for(int j=0;j<18;j++)
            table[i][j]=-1;
    }
    for(int i=0;i<n-1;i++)
    {
        cin>>u>>v;
        u--; v--;
        listt[u].push_back(v);
        listt[v].push_back(u);
    }
    dfs(0,0,0);
    for(int j=1;j<18;j++)
    {
        for(int i=0;i<n;i++)
        {
            if(table[i][j-1]!=-1)
            {
                //cout<<"build"<<endl;
                table[i][j]=table[table[i][j-1]][j-1];
            }
        }
    }
    while(q--)
    {
        cin>>a>>b>>c;
        a--; b--; c--;
        lca1 = get_lca(a,b);
        lca2 = get_lca(b,c);
        lca3 = get_lca(a,c);
        dist1 = get_dist(lca1,a) + get_dist(lca1,b) + get_dist(lca1,c);
        dist2 = get_dist(lca2,a) + get_dist(lca2,b) + get_dist(lca2,c);
        dist3 = get_dist(lca3,a) + get_dist(lca3,b) + get_dist(lca3,c);
        //cout<<"lca1 = "<<lca1<<" dist1 = "<<dist1<<endl<<"lca2 = "<<lca2<<" dist2= "<<dist2<<endl<<"lca3 = "<<lca3<<" dist3 = "<<dist3<<endl;
        if(dist1<=dist2&&dist1<=dist3)cout<<lca1+1<<" "<<dist1<<endl;
        else if(dist2<=dist1&&dist2<=dist3)cout<<lca2+1<<" "<<dist2<<endl;
        else cout<<lca3+1<<" "<<dist3<<endl;
    }
  return 0;
}



