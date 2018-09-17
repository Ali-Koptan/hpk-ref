class DSU
{
private:
    int *parent, *score;
public:
    DSU(int n)
    {
        parent = new int[n];
        score = new int[n];
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
            score[i] = 0;
        }
    }
    int GetRoot(int i)
    {
        while(parent[i] != i)
        {
            i = parent[i];
        }
        return i;
    }
    bool IsConnected(int x, int y)
    {
        return (GetRoot(x) == GetRoot(y));
    }
    bool Connect(int x, int y)
    {
        int pX = GetRoot(x);
        int pY = GetRoot(y);
        if(pX == pY)
        {
            return false;
        }
        if(score[pX] >= score[pY])
        {
            parent[pY] = pX;
            score[pX]++;
        }
        else
        {
            parent[pX] = pY;
            score[pY]++;
        }
        return true;
    }
    ~DSU()
    {
        delete[] parent, score;
    }
};